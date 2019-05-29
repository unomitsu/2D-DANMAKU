#pragma once
#include "Objec.h"

class Player : public Objec {
private:
	// double x, y;
	// int size;
	// int image;
	// bool flag;
	int hp;

public:
	Player();
	void Update();
	void Draw();
	virtual void CollisionResult();
};
