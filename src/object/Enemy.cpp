#include "Enemy.h"

Enemy::Enemy(Vector2 position, int width, int height, bool isAlive, float speed) : Entity(position, width, height)
{
	this->position = position;
	this->width = width;
	this->height = height;
	this->isActive = isAlive;
	this->speed = speed;
	moveCounter = 0;
	amountAsteroids++;
}

Enemy::~Enemy()
{
	amountAsteroids--;
}

void Enemy::Draw()
{
	char top = 30;
	char midL = 17;
	char mid = 219;
	char midR = 16;
	char bot = 31;

	setForegroundColor(Color::RED);
	goToCoordinates(position.x, position.y - 1);
	cout << "    ";
	goToCoordinates(position.x, position.y);
	cout << " " << top << top << " ";
	goToCoordinates(position.x, position.y + 1);
	cout << midL << mid << mid << midR;
	goToCoordinates(position.x, position.y + 2);
	cout << " " << bot << bot << " ";
	setForegroundColor(Color::WHITE);
}

void Enemy::Movement()
{
	moveCounter += speed;
	if (moveCounter >= 1)
	{
		moveCounter = 0;
		position.y++;
		goToCoordinates(position.x, position.y - 2);
		cout << "    ";
		goToCoordinates(position.x, position.y - 1);
		cout << "    ";
		goToCoordinates(position.x, position.y);
		cout << "    ";
	}
}

void Enemy::SetActive(bool state)
{
	isActive = state;
}

bool Enemy::GetIsActive()
{
	return isActive;
}

int Enemy::GetAmount()
{
	return amountAsteroids;
}

void Enemy::DeleteEnemyDraw()
{
	goToCoordinates(position.x, position.y);
	cout << "    ";
	goToCoordinates(position.x, position.y + 1);
	cout << "    ";
	goToCoordinates(position.x, position.y + 2);
	cout << "    ";
}