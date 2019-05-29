#include "DxLib.h"
#include "Enemy.h"
#include "Info.h"

int Enemy::image;

Enemy::Enemy() {
	x = 100.0;
	y = 50.0;
	v = 4.0;
	size = 64;
	flag = true;
	hp = 100;
	image = LoadGraph("../images/enemy.png");
	span = 0;
}

void Enemy::Update() {
	Movement();	// 行動内容
}

void Enemy::Draw() {
	// エネミーの画像の描画
	DrawGraph((int)(x - size / 2), (int)(y - size / 2), image, TRUE);
	// エネミーの体力の描画
	DrawFormatString(GetWidth()/2, 50, GetColor(255, 255, 255), "ENEMY_HP : %d", hp);
}

// あたり判定後の処理
void Enemy::CollisionResult() {
	// 体力を減らす  hp が 0 以下になった場合、生存フラグを落とす
	if (--hp <= 0) { flag = false; }
}

void Enemy::Movement() {
	//　動かない
	if (++span < 0) {
		return;
	}
	// span が 0 になった時、動く値を設定する
	if (span++ == 0) {
		//　プレイヤーより左にいるとき右に動く(xは増加)
		if (x < GetPlayerX()) {
			v = v > 0 ? v : -v;
		}
		//　プレイヤーより右にいるとき左に動く(xは減少)
		if (GetPlayerX() < x) {
			v = v > 0 ? -v : v;
		}
		return;
	}
	// span が 40 になるまで動く
	if (span <= 40) {
		x += v;
	}
	// 20 を超えると span をリセット
	else {
		span = -60;
	}

}