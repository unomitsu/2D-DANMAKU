#pragma once

class Objec {
protected:
	double x, y, v;
	int size;
	int image;
	bool flag;

public:
	Objec() {}
	virtual void Update() {}
	virtual void Draw() {}
	virtual void CollisionResult() {}


	double GetX() { return x; }
	double GetY() { return y; }
	int GetSize() { return size; }
	bool GetFlag() { return flag; }
};
