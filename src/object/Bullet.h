#pragma once
#include "Entity.h"

class Bullet : public Entity
{
public:
	bool isActive;
	float speed;
	float moveCounter;

	Bullet(Vector2 position, int width, int height, bool isActive, float speed);

	void Draw();
	void Shoot(char input);
	void Movement(Vector2 playerPosition);
	void SetActive(bool state);
	bool GetIsActive();
};

