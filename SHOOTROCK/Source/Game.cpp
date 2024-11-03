#include "Game.h"


Game::Game()
{
	StartScreen = true;
	GameOver = false;
}


void Game::StartButton()
{
	if (IsKeyDown(KEY_ENTER))
	{
		StartScreen = false;
	}
}

void Game::RestartButton()
{
	if (IsKeyDown(KEY_R))
	{
		StartScreen = true;
		GameOver = false;
	}
}


void Game::SpawnRock()
{
	for (int i = 0; i <13; i++)
	{
		float posX = (float)(rand() % 1000 + 100);
		float posY = 0;
		float angle = (float)(rand() % 180 + 90);
		float speedX = (float)(rand() % 7 + 5);
		float speedY = (float)(rand() % 7 + 5);
		Rock rock(2, 35, posX, posY, angle, speedX, speedY, 0);
		rocks.push_back(rock);	
	}
}

void Game::SetUp()
{
	for (int j = (int)rocks.size() - 1; j >= 0; j--)
	{		
			rocks.erase(rocks.begin() + j);
	}
	for (int j = (int)gems.size() - 1; j >= 0; j--)
	{
		
		gems.erase(gems.begin() + j);
	}
	SpawnRock();
	ship.Position.x = 475;
	ship.Position.y = 700;
}

void Game::DestroyRock()
{
	for (int j = (int)rocks.size() - 1; j >= 0; j--)
	{
		if (rocks[j].Position.y >= 900 || rocks[j].Position.y < -110 ||
			rocks[j].Position.x >= 1100 || rocks[j].Position.x < -100)
		{
			
				rocks.erase(rocks.begin() + j);
			
		}			
	}
			
}

void Game::DestroyGem()
{
	for (int j = (int)gems.size() - 1; j >= 0; j--)
	{
		if (gems[j].Position.y >= 900|| gems[j].Position.y < 0||
			gems[j].Position.x >= 1100 || gems[j].Position.x <0)
		{
			gems.erase(gems.begin() + j);
		}
	}
}

void Game::BulletDestroyRock()
{
	for (int j = (int)rocks.size() - 1; j >= 0; j--)
	{
		for (int i = (int)ship.bullets.size() - 1; i >= 0; i--)
		{
			if (CheckCollisionCircles(rocks[j].Position, rocks[j].Radius, ship.bullets[i].Position, ship.bullets[i].radius) == true)
			{
				for (int a = 0; a < 5; a++)
				{
					float angle = (float)(rand() % 180 + 90);
					float speedX = (float)(rand() % 8 + 6);
					float speedY = (float)(rand() % 8 + 6);

					Gem gem(1, 32, rocks[j].Position.x, rocks[j].Position.y, angle, speedX, speedY, 0);		
					gems.push_back(gem);
				}
				PlaySoundMulti(boom);

				rocks.erase(rocks.begin() + j);
				break;
			}
		}
	}
}

void Game::RockDestroyShip()
{
	for (Rock& rock : rocks)  //for each asteroid in the vector 
	{
		if (CheckCollisionCircles(ship.Position, ship.radius, rock.Position, rock.Radius))
		{
			GameOver = true;
			SetUp();
		}
	}
}

void Game::ShipGetGem()
{
	for (int j = (int)gems.size() - 1; j >= 0; j--)
	{
		if (CheckCollisionCircles(gems[j].Position, gems[j].Radius, ship.Position, ship.radius) == true)
		{
			gems.erase(gems.begin() + j);
			PlaySoundMulti(coin);
			gui.ComboCounter(1);			
		}
	}
	
}

void Game::Combo()
{
	if (gems.empty())
	{
		gui.ComboCounter(0);
	}
	if (gui.showcombo)
	{
		DrawText(TextFormat("+ %02i", gui.m_combo), 180, 40, 30, BLUE);
		DrawText(TextFormat("%02i", gui.m_combo),(int)((ship.Position.x)- (ship.radius)+7),(int)((ship.Position.y) - 50), 30, BLUE);
	}	
}

void Game::Update()
{ 
	if (StartScreen)
	{
		DrawText(TextFormat("SHOOT"), 400, 300, 70, RED);
		DrawText(TextFormat("ROCK"), 390, 400, 100, BLUE);
		DrawText(TextFormat("PRESS ENTER TO START"), 200, 500, 50, GRAY);
		StartButton();
	}
	else if(!StartScreen&&!GameOver)
	{
		
		if (rocks.empty())
		{
			Game::SpawnRock();
		}
		for (Rock& rock : rocks)  //for each asteroid in the vector 
		{
			rock.Moving();
		}
		for (Gem& gem : gems)  //for each gem in the vector 
		{
			gem.Moving();
		}
		ship.Input();
		ship.Movement();
		ship.ShipContainer();
		ship.Shooting();
		ship.DestroyBullet();
		DestroyRock();
		BulletDestroyRock();
		RockDestroyShip();
		ShipGetGem();

		DestroyGem();

		gui.Score();
		ship.DrawShip();
		ship.ChargeAnimation();
		Combo();
		for (Rock& rock : rocks)  //for each asteroid in the vector 
		{
			rock.DrawRock();
		}
		for (Gem& gem : gems)  //for each gem in the vector 
		{
			gem.DrawGem();
		}
	}
	if (GameOver)
	{
		RestartButton();
		DrawText(TextFormat("ITS OVAR!"), 200, 400, 50, RED);
		DrawText(TextFormat("PRESS R TO RESTART"), 200, 600, 30, RAYWHITE);
		gui.ScoreForEndScreen();
	}
	

	ClearBackground(BLACK);
}


void Game::Load()
{
	
	coin = LoadSound("Assets/coin2.wav");
	boom = LoadSound("Assets/boom.wav");

	ship.LoadShip();
	Bullet::Load();
	Rock::LoadRock();
	Gem::LoadGem();
}


void Game::Unload()
{
	Bullet::Unload();
	Rock::UnloadRocks();
	Gem::UnloadGem();
	ship.UnloadShip();
	UnloadSound(coin);
	UnloadSound(boom);
	


}