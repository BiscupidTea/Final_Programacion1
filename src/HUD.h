#pragma once
#include "tools/AwesomeLibrary.h"
#include "tools/Vector2.h"
#include <vector>

#include "Object/Player.h"
#include "object/Enemy.h"

class HUD
{
private:
	int ScreenWidth;
	int ScreenHeight;
	int maxEnemy;
	bool win;
	bool isPlaying;
	Player* player;
	Enemy* arrayEnemy[4];

public:
	HUD(Player* player, Enemy* arrayEnemy[] , int ScreenWidth, int ScreenHeight, int maxEnemy);
	~HUD();

	void Draw();

	void ShowFrame();

	void ShowWin();
	void ShowDefeat();
};