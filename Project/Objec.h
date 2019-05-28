#pragma once

#ifndef DEF_OBJEC_H
#define DEF_OBJEC_H

class Objec {
protected:
	double x, y, v;
	int size;
	int image;
	bool flag;

public:
	Objec() {}
	void Update() {}
	void Draw() {}
	virtual bool CollisionResult() { return false; }

	double GetX() { return x; }
	double GetY() { return y; }
	int GetSize() { return size; }
	bool GetFlag() { return flag; }
};

#endif DEF_OBJECT_H
