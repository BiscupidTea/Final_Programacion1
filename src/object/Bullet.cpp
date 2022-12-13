#include "Bullet.h"

Bullet::Bullet(Vector2 position, int width, int height, bool isActive, float speed) : Entity(position, width, height)
{
	this->position = position;
	this->width = width;
	this->height = height;
	this->isActive = isActive;
	this->speed = speed;
	moveCounter = 0;
}

void Bullet::Draw()
{
	char bulletDraw = 30;
	goToCoordinates(position.x, position.y);
	cout << bulletDraw;
	goToCoordinates(position.x, position.y+1);
	cout << " " ;
}

void Bullet::Shoot(char input)
{
	if (input == 'f' || input == 'F')
	{
		SetActive(true);
	}
}

void Bullet::Movement(Vector2 playerPosition)
{

	if (isActive)
	{
		moveCounter += speed;
		if (moveCounter >= 1)
		{
			moveCounter = 0;
			position.y--;
		}
	}
	else
	{
		SetPosition({ playerPosition.x + 3, playerPosition.y });
	}
}

void Bullet::SetActive(bool state)
{
	isActive = state;
}

bool Bullet::GetIsActive()
{
	return isActive;
}