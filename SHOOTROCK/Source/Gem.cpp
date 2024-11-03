#include "Gem.h"

Texture Gem::GemPic;

Gem::Gem(float size, float radius, float posX, float posY, float angle, float speedX, float speedY, float rotation)
{
	Rotate = rotation;
	Size = size;
	Radius = radius;
	Position.x = posX;
	Position.y = posY;
	SpeedX = speedX;
	SpeedY = speedY;
	Angle = angle;
}

void Gem::Moving()
{
	Position.x += (float)sin((Angle * 3.14) / 180) * SpeedX;
	Position.y -= (float)cos((Angle * 3.14) / 180) * SpeedY;
}

void Gem::LoadGem()
{
	GemPic = LoadTexture("Assets/Gem.png");
}


void Gem::DrawGem()
{
	DrawTextureEx(GemPic, Vector2{ Position.x - Radius, Position.y - Radius }, Rotate, Size, RAYWHITE);
}

void Gem::UnloadGem()
{
	UnloadTexture(GemPic);
}