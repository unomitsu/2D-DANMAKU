#include "DxLib.h"
#include "Info.h"
#include "Objec.h"

int width, height;

void info_initialize() {
	GetScreenState(&width, &height, NULL);
}

int GetWidth() {
	return width;
}
int GetHeight() {
	return height;
}

double pow(double x) {
	return x * x;
}

void Collision(Objec* obj1, Objec* obj2) {
	// 両方が有効であるかの確認
	if (!(obj1->GetFlag() && obj2->GetFlag())) { return; }

	// あたり判定の計算
	if (pow(obj1->GetX() - obj2->GetX()) + pow(obj1->GetY() - obj2->GetY()) < pow(obj1->GetSize() / 8 + obj2->GetSize() / 2)) {
		obj1->CollisionResult();
		obj2->CollisionResult();
	}
}
