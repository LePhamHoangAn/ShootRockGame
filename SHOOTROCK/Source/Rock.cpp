#include "Rock.h"

Texture Rock::Rockpic;

Rock::Rock(float size, float radius, float posX, float posY, float angle, float speedX, float speedY, float rotation)
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

void Rock::Moving()
{
	Position.x += (float)sin((Angle * 3.14) / 180) * SpeedX;
	Position.y -= (float)cos((Angle * 3.14) / 180) * SpeedY;
}



void Rock::LoadRock()
{
	Rockpic = LoadTexture("Assets/Rock.png");
}


void Rock::DrawRock()
{
	DrawTextureEx(Rockpic, Vector2{ Position.x - Radius, Position.y - Radius }, Rotate, Size, RAYWHITE);
}

void Rock::UnloadRocks()
{
	UnloadTexture(Rockpic);
}