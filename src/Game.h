#pragma once
#include "tools/AwesomeLibrary.h"
#include "tools/Vector2.h"
#include <vector>

#include "HUD.h"
#include "Object/Entity.h"

#include "object/Player.h"
#include "object/Enemy.h"
#include "object/Bullet.h"

class Game
{
public:
	static const int maxEnemy = 4;
	Game();
	~Game();
	void GameLoop();
	void Input();
	void Update();
	void Draw();
	void CreateEnemy();

private:
	int MaxScreenWidth;
	int MaxScreenHeight;
	float enemySpeed;
	float bulletSpeed;
	bool isPlaying;
	Player* player;
	Bullet* bullet;
	Enemy* arrayEnemy[4];
	HUD* hud;

};