#include "DxLib.h"
#include "Enemy.h"
#include "Info.h"
#include "Lib.h"

int Enemy::image;

Enemy::Enemy() {
	x = GetWidth() / 2;		// x座標の初期化
	y = 50.0;				// y座標の初期化
	xv = yv = 0.0;			// x方向、y方向の初期化
	flag = true;			// 生存フラグを立てる
	hp_max = hp_now = 100;	// 現在の体力、最大体力の設定

	this->SetImage();		// 画像関連の設定
}

void Enemy::Update() {
	// 移動量の加算
	x += xv;
	y += yv;
}

void Enemy::Draw() {
	// エネミーの画像の描画
	DrawGraph((int)(x - size / 2), (int)(y - size / 2), image, TRUE);
	// エネミーの体力の描画
	DrawFormatString(GetWidth()/2, 50, GetColor(255, 255, 255), "ENEMY_HP : %d", hp_now);
}

// あたり判定後の処理
void Enemy::CollisionResult() {
	// 体力を減らす  hp が 0 以下になった場合、生存フラグを落とす
	if (--hp_now <= 0) { flag = false; }
}

// 画像関連の設定
void Enemy::SetImage() {
	size = 64;
	hit_size = size / 2;
	image = LoadGraph("../images/enemy.png");
}