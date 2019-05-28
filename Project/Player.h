#pragma once

#ifndef DEF_PLAYER_H
#define DEF_PLAYER_H

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
	virtual bool CollisionResult();
};

#endif DEF_PLAYER_H