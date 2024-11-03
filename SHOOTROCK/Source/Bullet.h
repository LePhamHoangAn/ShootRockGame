
#pragma once
#include "raylib.h"
#include <math.h>

class Bullet
{
	static Texture bullet;
	float speed, angle;

public:
	float radius;
	Vector2 Position;

	Bullet(float posX, float posY, float ang);

	void Update();
	void DrawBullet();
	void Movement();
	static void Load();
	static void Unload();


};