#include "DxLib.h"
#include "Shot.h"
#include "Info.h"

int Shot::image;

Shot::Shot() {
	x = 100.0;
	y = 0.0;
	v = 1.0;
	size = 16;
	hit_size = size / 2;
	flag = false;
	image = LoadGraph("../images/shot.png");
}

void Shot::Update() {
	// 弾が有効な時のみ更新
	if (flag) {
		y += v;
	}
}

void Shot::Draw() {
	// 弾が有効な時のみ描画
	if (flag) {
		DrawGraph((int)(x - size / 2), (int)(y - size / 2), image, TRUE);
	}
}

// あたり判定後の処理
void Shot::CollisionResult() {
	// 何かにあたった場合、フラグを落とす
	flag = false;
}

// 指定した座標（x, y）に弾を設置し、速度を付けて、有効にする 
void Shot::Set(double nx, double ny) {
	x = nx;
	y = ny;
	v = GetRand(50) / 10.0;
	flag = true;
}

// 指定した座標（x, y）に弾を設置し、速度を付けて、有効にする 
void Shot::Set(double nx, double ny, double nv) {
	x = nx;
	y = ny;
	v = nv;
	flag = true;
}