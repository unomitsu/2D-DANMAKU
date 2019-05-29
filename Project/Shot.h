#pragma once
#include "Objec.h"

class Shot : public Objec {
private:
	// double x, y, v;
	// int size;
	// int image;
	// bool flag;

public:
	Shot();
	void Update();
	void Draw();
	virtual void CollisionResult();

	void Set();
};