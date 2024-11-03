#include "Ship.h"







Ship::Ship()
{
	Position.x = 475;
	Position.y = 700;
	Speed = 10;
	input = input::Idle;
	radius = 25;
	ChargeBallSize = 0;
	Charge = 0;
}


void Ship::LoadShip()
{
	ChargeMP3 = LoadSound("Assets/Charge.wav");
	ShootMP3= LoadSound("Assets/shoot.wav");
	ShipPic = LoadTexture("Assets/spaceship.png");
	ChargeShot = LoadTexture("Assets/LaserBall.png");
}

void Ship::Input()
{
	//_____________SHOOT______________
	if (IsKeyDown(KEY_SPACE))
	{	
		Charge++;
		ChargeBallSize=ChargeBallSize+0.01f;
		if (ChargeBallSize > 1)
		{
			ChargeBallSize = 1;
		}	
	}
	else
	{
		Charge=Charge-2;
		if (Charge<0)
		{
			Charge = 0;
		}
		ChargeBallSize = 0;
	}
	if (IsKeyPressed(KEY_SPACE))
	{
		PlaySoundMulti(ChargeMP3);
	}
	if (IsKeyReleased(KEY_SPACE))
	{
		PlaySoundMulti(ShootMP3);
	}

	//_____________MOVE___________________
	if (IsKeyDown(KEY_LEFT))
	{
		input = input::Left;
	}
	else if (IsKeyDown(KEY_RIGHT))
	{
		input = input::Right;
	}
	else
	{
		input = input::Idle;
	}


	
}


void Ship::Movement()
{

	switch (input)
	{
	case input::Right:
	{
		Position.x = Position.x + Speed;
		break;
	}
	case input::Left:
	{
		Position.x = Position.x - Speed;
		break;
	}
	case input::Idle:
	{
		break;
	}
	}
}

void Ship::ChargeAnimation()
{
	if (ChargeBallSize > 0)
	{
		DrawTextureEx(ChargeShot, { Position.x + 138 , Position.y - 140 }, 120, ChargeBallSize, RAYWHITE);
		DrawTextureEx(ChargeShot, { Position.x - 100 , Position.y - 200 }, 0, ChargeBallSize, RAYWHITE);
	}
}



void Ship::Shooting()
{
	if (Charge>=50&&!IsKeyDown(KEY_SPACE))
	{
		Bullet newBullet(Position.x, Position.y-160, 0);
		bullets.push_back(newBullet);
		Charge = 0;
	}
	

	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i].Update();
	}


	DestroyBullet();
}

void Ship::DestroyBullet()
{
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i].Position.y < 0 || bullets[i].Position.y > 1000 ||
			bullets[i].Position.x < 0 || bullets[i].Position.x > 1000)
		{
			bullets.pop_front();
		}
	}
}

void Ship::ShipContainer()
{
	if (Position.y < 0)
	{
		Position.y = 0;
	}
	if (Position.y > 800)
	{
		Position.y = 800;
	}
	if (Position.x > 1000)
	{
		Position.x = 1000;
	}
	if (Position.x < 0)
	{
		Position.x = 0;
	}
}

void Ship::DrawShip()
{
	DrawTextureEx(ShipPic, { Position.x - radius, Position.y - radius }, 0, 1, RAYWHITE);

}
void Ship::UnloadShip()
{
	UnloadSound(ChargeMP3);
	UnloadSound(ShootMP3);
	UnloadTexture(ShipPic);
}