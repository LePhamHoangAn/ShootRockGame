#pragma once
#include "raylib.h"
#include "Ship.h"
#include "Rock.h"
#include "Gem.h"
#include "GUI.h"
#include <deque>
class Game
{
	Ship ship;
	GUI gui;

	std::deque<Rock>rocks;
	std::deque<Gem>gems;

	Sound coin{};
	Sound boom{};
	
	
	bool StartScreen;
	bool GameOver;
public:

	Game();
	void StartButton();
	void RestartButton();
	void SetUp();
	void Combo();

	void SpawnRock();
	void DestroyRock();
	void DestroyGem();
	void BulletDestroyRock();
	void RockDestroyShip();
	void ShipGetGem();


	void Load();
	void Update();
	void Unload();






};
