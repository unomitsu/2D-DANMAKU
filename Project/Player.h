#pragma once
#include "Objec.h"

class Player : public Objec {
private:
	// double x, y;
	// int size;
	// bool flag;
	int hp;
	static int image;

public:
	Player();
	void Update();
	void Draw();
	virtual void CollisionResult();
};
