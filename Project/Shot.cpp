#include "DxLib.h"
#include "Shot.h"
#include "Info.h"
#include "Lib.h"

int Shot::image = -1;

Shot::Shot() {
	x = y = 100.0;		// 座標の初期化
	xv = yv = 0.0;		// 速度の初期化
	flag = false;		// 有効フラグを落とす
	SetImage();			// 画像関連の初期化
}
Shot::Shot(double nx, double ny, double nxv, double nyv) {
	x = nx;
	y = ny;
	xv = nxv;
	yv = nyv;
	flag = true;
	SetImage();
}

void Shot::Update() {
	// 弾が有効な時のみ更新
	if (flag) {
		x += xv;
		y += yv;
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

// 画像関連の初期化
void Shot::SetImage() {
	size = 16;
	hit_size = size / 2;
	if (image == -1) {
		image = LoadGraph("../images/shot.png");
	}
}

// フラグを立てて発射する
void Shot::Fire() {
	flag = true;
}

// 画面範囲内に存在するかどうかを返す。存在する=TRUE、存在しない=FALSE
bool Shot::InWindow() {
	if (x < 0 || GetWidth() < x || y < 0 || GetHeight() < y) {
		return false;
	}
	return true;
}
