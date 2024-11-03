#pragma once
#include "raylib.h"
#include <deque>
#include "Bullet.h"
class Ship
{

	bool Shoot;

	float Speed;
	float Charge;

	Texture2D ShipPic{};
	Texture2D ChargeShot{};

	Sound ChargeMP3{};
	Sound ShootMP3{};

	float ChargeBallSize;

	enum class input
	{
		Left,
		Right,
		Idle
	}input;
public:
	float radius;
	Vector2 Position;
	std::deque<Bullet> bullets;


	Ship();
	void LoadShip();
	void DrawShip();
	void ChargeAnimation();
	void Input();
	void Movement();
	void Shooting();
	void DestroyBullet();
	void UnloadShip();
	void ShipContainer();

};