#include "Bullet.h"

Texture Bullet::bullet;

Bullet::Bullet(float posX, float posY, float ang)
{
	Position.x = 0;
	Position.y = 0;
	Position.x = posX;
	Position.y = posY;
	radius = 100;
	speed = 10;
	angle = 0;
}

void Bullet::Update()
{
	DrawBullet();
	Movement();
}

void Bullet::DrawBullet()
{
	DrawTextureEx(bullet, { Position.x - radius, Position.y - radius }, 0, 1, RAYWHITE);
}

void Bullet::Load()
{
	bullet = LoadTexture("Assets/LaserBall.png");
}

void Bullet::Unload()
{
	UnloadTexture(bullet);
}

void Bullet::Movement()
{
	Position.x = Position.x;
	Position.y = Position.y - speed;
}
