#include "player.h"

Player::Player(Vector2 position, int width, int height, int lives, int points, int maxPoints) : Entity(position, width, height)
{
	this->position = position;
	this->width = width;
	this->height = height;
	this->lives = lives;
	this->points = points;
	this->maxPoints = maxPoints;
}

Player::~Player()
{

}

void Player::Draw()
{
	char triangle = 30;
	char mid = 206;
	char botL = 188;
	char botR = 200;

	setForegroundColor(Color::GREEN);
	goToCoordinates(position.x, position.y);
	cout << " " << "  " << triangle << "  " << " ";
	goToCoordinates(position.x, position.y + 1);
	cout << " " << " (" << mid << ")" << " ";
	goToCoordinates(position.x, position.y + 2);
	cout << " " << triangle << botL << " " << botR << triangle << " ";
	setForegroundColor(Color::WHITE);
}

void Player::Movement(char input)
{

	if ((input == 'd' || input == 'D') && position.x < 68)
	{
		position.x++;
	}
	else if ((input == 'a' || input == 'A') && position.x > 2)
	{
		position.x--;
	}
}

bool Player::IsAlive()
{
	if (lives > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Player::loseLive()
{
	lives -= 1;
}

int Player::GetLives()
{
	return lives;
}

int Player::GetPoints()
{
	return points;
}

void Player::Add1Point()
{
	points++;
}

bool Player::RechMaxPoints()
{
	if (points >= maxPoints)
	{
		return true;
	}

	return false;
}