#include "Game.h"

Game::Game()
{
	MaxScreenWidth = 75;
	MaxScreenHeight = 30;

	enemySpeed = 0.2f;
	bulletSpeed = 0.2f;

	isPlaying = true;
	player = new Player({ MaxScreenWidth / 2, MaxScreenHeight - 3 }, 5, 3, 3, 0, 10);
	bullet = new Bullet({ MaxScreenWidth / 2, MaxScreenHeight - 3 }, 1, 1, false, bulletSpeed);

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

	do
	{
		Input();
		Update();
		Draw();

	} while (player->IsAlive() && !player->RechMaxPoints());

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
	if (_kbhit())
	{
		char input;
		input = _getch();
		player->Movement(input);
		bullet->Shoot(input);
	}
}

void Game::Update()
{

	for (int i = 0; i < maxEnemy; i++)
	{
		arrayEnemy[i]->Movement();
		if (arrayEnemy[i]->GetY() >= 29)
		{
			delete arrayEnemy[i];
			arrayEnemy[i] = new Enemy({ rand() % 70 + 2, 2 }, 3, 3, true, enemySpeed);
		}

		if (arrayEnemy[i]->GetIsActive())
		{
			if (player->CheckColition(arrayEnemy[i]->GetPosition(), arrayEnemy[i]->GetWidth(), arrayEnemy[i]->GetHeight()))
			{
				player->loseLive();
				CreateEnemy();
				system("cls");
			}
		}

		if (bullet->GetIsActive() && arrayEnemy[i]->GetIsActive())
		{
			if (bullet->CheckColition(arrayEnemy[i]->GetPosition(), arrayEnemy[i]->GetWidth(), arrayEnemy[i]->GetHeight()))
			{
				arrayEnemy[i]->SetActive(false);
				goToCoordinates(bullet->GetX() - 1, bullet->GetY() - 1);
				cout << "   ";
				goToCoordinates(bullet->GetX(), bullet->GetY());
				cout << "   ";
				goToCoordinates(bullet->GetX() - 1, bullet->GetY() + 1);
				cout << "   ";

				arrayEnemy[i]->DeleteEnemyDraw();
				delete arrayEnemy[i];
				arrayEnemy[i] = new Enemy({ rand() % 70 + 2, 2 }, 3, 3, true, enemySpeed);

				delete bullet;
				bullet = new Bullet({ MaxScreenWidth / 2, MaxScreenHeight - 3 }, 1, 1, false, bulletSpeed);
				player->Add1Point();
			}
		}

		bullet->Movement(player->GetPosition());

		if (bullet->GetY() <= 1)
		{
			goToCoordinates(bullet->GetX()-1, bullet->GetY()-1);
			cout << "   ";
			goToCoordinates(bullet->GetX(), bullet->GetY());
			cout << "   ";
			goToCoordinates(bullet->GetX()-1, bullet->GetY()+1);
			cout << "   ";
			delete bullet;
			bullet = new Bullet({ MaxScreenWidth / 2, MaxScreenHeight - 3 }, 1, 1, false, bulletSpeed);
		}

	}
}

void Game::Draw()
{
	for (int i = 0; i < maxEnemy; i++)
	{
		if (arrayEnemy[i]->GetIsActive())
		{
			arrayEnemy[i]->Draw();
		}
	}

	player->Draw();

	if (bullet->GetIsActive())
	{
		bullet->Draw();
	}

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