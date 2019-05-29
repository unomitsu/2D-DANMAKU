#pragma once
#include "Objec.h"

class Enemy : public Objec {
private:
	// double x, y, v;
	// int size;
	// bool flag;
	int hp;
	static int image;
	int span;

public:
	Enemy();
	void Update();
	void Draw();
	virtual void CollisionResult();

	void Movement();
};