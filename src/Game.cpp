#include "Game.h"

Game::Game()
{
	MaxScreenWidth = 75;
	MaxScreenHeight = 30;

	enemySpeed = 0.2f;
	bulletSpeed = 0.2f;

	isPlaying = true;
	player = new Player({ MaxScreenWidth / 2, MaxScreenHeight - 3 }, 5, 3, 3, 0, 10);

	for (int i = 0; i < maxBullets; i++)
	{
		bullet[i] = new Bullet({ MaxScreenWidth / 2, MaxScreenHeight - 3 }, 1, 1, false, bulletSpeed);
	}

	for (int i = 0; i < maxEnemy; i++)
	{
		arrayEnemy[i] = new Enemy({ rand() % 70 + 2, 2 }, 3, 3, true, enemySpeed);
	}

	hud = new HUD(player, arrayEnemy, MaxScreenWidth, MaxScreenHeight, maxEnemy);


}

Game::~Game()
{

}

void Game::GameLoop()
{
	char start;
	cout << "Enter letter to start : ";
	cin >> start;

	//gameloop
	do
	{
		Input();
		Update();
		Draw();

	} while (player->IsAlive() && !player->RechMaxPoints());

	//win & defeat
	if (player->IsAlive())
	{
		hud->ShowWin();
	}
	else
	{
		hud->ShowDefeat();
	}
}

void Game::Input()
{
	//player input
	if (_kbhit())
	{
		char input;
		input = _getch();
		player->Movement(input);

		if (input == 'f' || input == 'F')
		{
			for (int i = 0; i < maxBullets; i++)
			{
				if (!bullet[i]->GetIsActive())
				{
					bullet[i]->Shoot(input);
					i = maxBullets;
				}
			}
		}

	}
}

void Game::Update()
{

	for (int i = 0; i < maxEnemy; i++)
	{
		//enemy move
		arrayEnemy[i]->Movement();

		//enemy pass limit
		if (arrayEnemy[i]->GetY() >= 29)
		{
			delete arrayEnemy[i];
			arrayEnemy[i] = new Enemy({ rand() % 70 + 2, 2 }, 3, 3, true, enemySpeed);
		}

		//check colition player enemy
		if (arrayEnemy[i]->GetIsActive())
		{
			if (player->CheckColition(arrayEnemy[i]->GetPosition(), arrayEnemy[i]->GetWidth(), arrayEnemy[i]->GetHeight()))
			{
				player->loseLive();
				CreateEnemy();
				system("cls");
			}
		}

		//check colition bullet enemy
		for (int x = 0; x < maxBullets; x++)
		{
			if (bullet[x]->GetIsActive() && arrayEnemy[i]->GetIsActive())
			{
				if (bullet[x]->CheckColition(arrayEnemy[i]->GetPosition(), arrayEnemy[i]->GetWidth(), arrayEnemy[i]->GetHeight()))
				{
					arrayEnemy[i]->SetActive(false);
					goToCoordinates(bullet[x]->GetX() - 1, bullet[x]->GetY() - 1);
					cout << "   ";
					goToCoordinates(bullet[x]->GetX(), bullet[x]->GetY());
					cout << "   ";
					goToCoordinates(bullet[x]->GetX() - 1, bullet[x]->GetY() + 1);
					cout << "   ";

					arrayEnemy[i]->DeleteEnemyDraw();
					delete arrayEnemy[i];
					arrayEnemy[i] = new Enemy({ rand() % 70 + 2, 2 }, 3, 3, true, enemySpeed);

					delete bullet[x];
					bullet[x] = new Bullet({ MaxScreenWidth / 2, MaxScreenHeight - 3 }, 1, 1, false, bulletSpeed);
					player->Add1Point();
				}
			}

			//bullet movement
			bullet[x]->Movement(player->GetPosition());

			//bullet pass limit
			if (bullet[x]->GetY() <= 1)
			{
				goToCoordinates(bullet[x]->GetX() - 1, bullet[x]->GetY() - 1);
				cout << "   ";
				goToCoordinates(bullet[x]->GetX(), bullet[x]->GetY());
				cout << "   ";
				goToCoordinates(bullet[x]->GetX() - 1, bullet[x]->GetY() + 1);
				cout << "   ";
				delete bullet[x];
				bullet[x] = new Bullet({ MaxScreenWidth / 2, MaxScreenHeight - 3 }, 1, 1, false, bulletSpeed);
			}
		}


	}
}

void Game::Draw()
{
	//draw enemy
	for (int i = 0; i < maxEnemy; i++)
	{
		if (arrayEnemy[i]->GetIsActive())
		{
			arrayEnemy[i]->Draw();
		}
	}

	//draw player
	player->Draw();

	//draw bullet
	for (int i = 0; i < maxBullets; i++)
	{
		if (bullet[i]->GetIsActive())
		{
			bullet[i]->Draw();
		}
	}

	//hud draw
	hud->Draw();
}

void Game::CreateEnemy()
{
	for (int i = 0; i < maxEnemy; i++)
	{
		delete arrayEnemy[i];
		arrayEnemy[i] = new Enemy({ rand() % 70 + 2, 2 }, 3, 3, true, enemySpeed);
	}
}