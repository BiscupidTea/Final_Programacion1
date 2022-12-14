#include "HUD.h"

HUD::HUD(Player* player, Enemy* arrayEnemy[], int ScreenWidth, int ScreenHeight, int maxEnemy)
{
	this->ScreenWidth = ScreenWidth;
	this->ScreenHeight = ScreenHeight;
	win = false;
	isPlaying = false;
	this->player = player;
	this->maxEnemy = maxEnemy;

	for (int i = 0; i < maxEnemy; i++)
	{
		this->arrayEnemy[i] = arrayEnemy[i];
	}
}

HUD::~HUD()
{

}

void HUD::Draw()
{
	ShowFrame();
	char liveDraw = 3;
	//score
	goToCoordinates(78, 4);
	setForegroundColor(Color::WHITE);
	cout << "Score: ";
	setForegroundColor(Color::YELLOW);
	cout << player->GetPoints() << "   ";
	setForegroundColor(Color::WHITE);
	//lives
	goToCoordinates(78, 6);
	setForegroundColor(Color::WHITE);
	cout << "Lives: ";
	setForegroundColor(Color::RED);
	for (int i = 0; i < player->GetLives(); i++)
	{
		cout << liveDraw;
	}
	setForegroundColor(Color::WHITE);
	//rules key
	setForegroundColor(Color::WHITE);
	goToCoordinates(78, 9);
	cout << "D = RIGHT" << endl;
	goToCoordinates(78, 10);
	cout << "A = LEFT" << endl;
	goToCoordinates(78, 11);
	cout << "F = SHOOT" << endl;
	//amount asteroids
	setForegroundColor(Color::WHITE);
	goToCoordinates(78, 15);
	cout << "Asteroids = " << Enemy::GetAmount() << " " << endl;
}

void HUD::ShowFrame()
{
	setForegroundColor(Color::WHITE);
	drawFrame(1, 1, 75, 30);
	setForegroundColor(Color::WHITE);
}

void HUD::ShowWin()
{
	system("cls");
	goToCoordinates(1, 1);
	setForegroundColor(Color::YELLOW);
	cout << R"(
 /$$     /$$ /$$$$$$  /$$   /$$       /$$      /$$ /$$$$$$ /$$   /$$ /$$
|  $$   /$$//$$__  $$| $$  | $$      | $$  /$ | $$|_  $$_/| $$$ | $$| $$
 \  $$ /$$/| $$  \ $$| $$  | $$      | $$ /$$$| $$  | $$  | $$$$| $$| $$
  \  $$$$/ | $$  | $$| $$  | $$      | $$/$$ $$ $$  | $$  | $$ $$ $$| $$
   \  $$/  | $$  | $$| $$  | $$      | $$$$_  $$$$  | $$  | $$  $$$$|__/
    | $$   | $$  | $$| $$  | $$      | $$$/ \  $$$  | $$  | $$\  $$$    
    | $$   |  $$$$$$/|  $$$$$$/      | $$/   \  $$ /$$$$$$| $$ \  $$ /$$
    |__/    \______/  \______/       |__/     \__/|______/|__/  \__/|__/      
                                                              
)" << endl;

	char exit;
	cout << "Total score: " << player->GetPoints() << endl;
	cout << "Enter letter to continue : ";
	cin >> exit;
}

void HUD::ShowDefeat()
{
	system("cls");
	goToCoordinates(1, 1);
	setForegroundColor(Color::RED);
	cout << R"(
 /$$     /$$ /$$$$$$  /$$   /$$       /$$        /$$$$$$   /$$$$$$  /$$$$$$$$ /$$
|  $$   /$$//$$__  $$| $$  | $$      | $$       /$$__  $$ /$$__  $$| $$_____/| $$
 \  $$ /$$/| $$  \ $$| $$  | $$      | $$      | $$  \ $$| $$  \__/| $$      | $$
  \  $$$$/ | $$  | $$| $$  | $$      | $$      | $$  | $$|  $$$$$$ | $$$$$   | $$
   \  $$/  | $$  | $$| $$  | $$      | $$      | $$  | $$ \____  $$| $$__/   |__/
    | $$   | $$  | $$| $$  | $$      | $$      | $$  | $$ /$$  \ $$| $$          
    | $$   |  $$$$$$/|  $$$$$$/      | $$$$$$$$|  $$$$$$/|  $$$$$$/| $$$$$$$$ /$$
    |__/    \______/  \______/       |________/ \______/  \______/ |________/|__/
                                                                                 
)" << endl;

	char exit;
	cout << "Total score: " << player->GetPoints() << endl;
	cout << "Enter letter to continue : ";
	cin >> exit;
}