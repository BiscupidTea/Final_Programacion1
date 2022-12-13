#pragma once
#include "../tools/AwesomeLibrary.h"
#include "../tools/Vector2.h"

class Entity
{
protected:
	Vector2 position;
	int width;
	int height;

public:
	Entity(Vector2 position, int width, int height);
	virtual ~Entity();

	bool CheckColition(Vector2 EPosition, int Ewidth, int Eheight);
	virtual void Draw() = 0;

	void SetPosition(Vector2 position);
	Vector2 GetPosition();
	int GetX();
	int GetY();
	int GetWidth();
	int GetHeight();
};