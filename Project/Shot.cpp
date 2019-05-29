#include "DxLib.h"
#include "Shot.h"
#include "Info.h"

int Shot::image;

Shot::Shot() {
	x = 100.0;
	y = 0.0;
	v = 1.0;
	size = 16;
	flag = false;
	image = LoadGraph("../images/shot.png");
}

void Shot::Update() {
	if (flag) {
		y += v;
	}
}

void Shot::Draw() {
	if (flag) {
		DrawGraph((int)(x - size / 2), (int)(y - size / 2), image, TRUE);
	}
}

void Shot::CollisionResult() {
	flag = false;
}

void Shot::Set(double nx, double ny) {
	x = nx;
	y = ny;
	v = GetRand(50) / 10.0;
	flag = true;
}