#pragma once
#include "Objec.h"

class Shot : public Objec {
private:
	// double x, y, v;
	// int size;
	// bool flag;
	static int image;

public:
	Shot();
	void Update();
	void Draw();
	virtual void CollisionResult();

	void Set(double nx, double ny);
};

