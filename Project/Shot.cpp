#include "DxLib.h"
#include "Shot.h"
#include "Info.h"

Shot::Shot() {
	x = 100.0;
	y = 0.0;
	v = 1.0;
	size = 16;
	image = LoadGraph("../images/shot.png");
	flag = false;
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

void Shot::Set() {
	x = GetWidth() * GetRand(100)/100.0;
	y = 0;
	v = GetRand(50) / 10.0;
	flag = true;
}