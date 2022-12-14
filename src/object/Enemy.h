#pragma once
#include "Entity.h"
#include "Player.h"


static int amountAsteroids = 0;

class Enemy : public Entity
{
private:
	bool isActive;
	float speed;
	float moveCounter;

public:
	Enemy(Vector2 position, int width, int height, bool isAlive, float speed);
	~Enemy();
	void Draw();
	void DeleteEnemyDraw();

	void Movement();

	void SetActive(bool state);
	bool GetIsActive();

	static int GetAmount();
};