#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	int lives;
	int points;
	int maxPoints;

	Player(Vector2 position, int width, int height, int lives, int points, int maxPoints);
	~Player();

	void Draw();

	void Movement(char input);

	bool IsAlive();
	void loseLive();
	int GetLives();

	int GetPoints();
	void Add1Point();
	bool RechMaxPoints();
};

