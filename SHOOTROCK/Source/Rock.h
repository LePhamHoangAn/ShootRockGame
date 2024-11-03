#pragma once


#pragma once
#include "raylib.h"
#include "Math.h"


class Rock
{
	float SpeedX{};
	float SpeedY{};
	float Angle{};
	float Size{};
	float Rotate{};
	//only need to send the texture once
	static Texture Rockpic;
public:
	float Radius{};
	Vector2 Position{};

	Rock(float size, float radius, float posX, float posY, float angle, float speedX, float speedY, float rotation);

	void Moving();
	static void LoadRock();
	void DrawRock();
	static void UnloadRocks();
};
