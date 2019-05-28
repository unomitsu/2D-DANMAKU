#pragma once

#ifndef DEF_SHOT_H
#define DEF_SHOT_H

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
	virtual bool CollisionResult();

	void Set();
};

#endif // DEF_SHOT_H