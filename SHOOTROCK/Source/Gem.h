#pragma once


#pragma once
#include "raylib.h"
#include "Math.h"


class Gem
{
	float SpeedX{};
	float SpeedY{};
	float Angle{};
	float Size{};
	float Rotate{};
	static Texture GemPic;
	static Sound coin;
public:

	//only need to send the texture once
	float Radius{};


	Vector2 Position{};

	Gem(float size, float radius, float posX, float posY, float angle, float speedX, float speedY, float rotation);

	void Moving();
    static void LoadGem();
	void DrawGem();
	static void UnloadGem();
};
