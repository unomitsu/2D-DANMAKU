#include "DxLib.h"
#include "Player.h"
#include "Key.h"
#include "Info.h"

int Player::image;

Player::Player() {
	x = 100.0;
	y = 100.0;
	v = 4;
	size = 64;
	hit_size = 8;
	flag = true;
	hp = 20;
	image = LoadGraph("../images/player.png");

	shot_num = 0;			// 現在の添字
	shot_span = 0;			// ショットの間隔
	for (int i = 0; i < shot_max; i++) {
		shot[i] = new Shot();		// ショット配列
	}
}

void Player::Update() {
	// 移動の更新
	double val = v;
	if (GetKey(KEY_INPUT_LSHIFT)) { val /= 2; }	// 左シフトを押しているとき半減速
	if (GetKey(KEY_INPUT_UP)) { y -= val; }
	if (GetKey(KEY_INPUT_RIGHT)) { x += val; }
	if (GetKey(KEY_INPUT_DOWN)) { y += val; }
	if (GetKey(KEY_INPUT_LEFT)) { x -= val; }
	
	// 移動範囲の制限、範囲外に出た時は範囲内に戻す
	if (y < 0) { y = 0; }
	if (GetHeight() < y) { y = GetHeight(); }
	if (GetWidth() < x) { x = GetWidth(); }
	if (x < 0) { x = 0; }

	// Zキーでショットを打つ
	ShotFire();

	// プレイヤーショットの更新
	for (int i = 0; i < shot_max; i++) {
		shot[i]->Update();
	}
}

// 描画
void Player::Draw() {
	DrawFormatString(0, 0, GetColor(255, 255, 255), "HP : %d", hp);		// 体力
	DrawGraph((int)(x - size / 2), (int)(y - size / 2), image, TRUE);	// プレイヤーの画像
	DrawCircle((int)x, (int)y, 8, GetColor(200, 100, 100), TRUE, 4);	// あたり判定の大きさ

	for (int i = 0; i < shot_max; i++) {
		shot[i]->Draw();		// プレイヤーショットの描画
	}
}

void Player::CollisionResult() {
	// 体力を減らす  hp が 0 以下になった場合、生存フラグを落とす
	if (--hp <= 0) { flag = false; }
}

void Player::ShotFire() {
	// Zキーを押しているとき
	if (GetKey(KEY_INPUT_Z)) {
		// span が 4以上になった時
		if (shot_span++ >= 4) {
			shot[shot_num++]->Set(x, y, -8);		// プレイヤーの位置から弾を発射する
			if (shot_num >= shot_max) { shot_num = 0; }
			shot_span = 0;						// shot_span のリセット
		}
	}
}