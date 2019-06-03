#include "DxLib.h"
#include "Player.h"
#include "Key.h"
#include "Lib.h"


int Player::image;

Player::Player() {
	x = y = 200.0;			// 座標の初期化
	v = 4;					// 速度の初期化
	flag = true;			// 生存フラグを立てる
	hp_now = hp_max = 3;	// 体力の設定

	SetImage();			// 画像関連の設定
	SetShot();			// プレイヤーショット関連の設定
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
	DrawFormatString(0, 0, GetColor(255, 255, 255), "HP : %d", hp_now);		// 体力
	DrawGraph((int)(x - size / 2), (int)(y - size / 2), image, TRUE);		// プレイヤーの画像
	DrawCircle((int)x, (int)y, 8, GetColor(200, 100, 100), TRUE, 4);		// あたり判定の大きさ

	for (int i = 0; i < shot_max; i++) {
		shot[i]->Draw();		// プレイヤーショットの描画
	}
	DrawFormatString(0, 300, GetColor(255, 255, 255), "HP : %d", shot_num);		// 体力
	DrawFormatString(0, 350, GetColor(255, 255, 255), "HP : %d", shot_max);		// 体力
}

void Player::CollisionResult() {
	// 体力を減らす  hp が 0 以下になった場合、生存フラグを落とす
	if (--hp_now <= 0) { flag = false; }
}

// 画像関連の設定
void Player::SetImage() {
	size = 64;
	hit_size = 8;
	image = LoadGraph("../images/player.png");
}

// プレイヤーショット関連の設定
void Player::SetShot() {
	shot_num = 0;			// 現在の添字
	shot_span = 0;			// ショットの間隔
	for (int i = 0; i < shot_max; i++) {
		shot[i] = new Shot();		// ショット配列
	}
}
// プレイヤーショットの発射
void Player::ShotFire() {
	// Zキーを押しているとき
	if (GetKey(KEY_INPUT_Z)) {
		// span が 4以上になった時
		if (shot_span++ >= 4) {
			// プレイヤーの位置から弾を発射する
			shot[shot_num]->x = this->x;
			shot[shot_num]->y = this->y;
			shot[shot_num]->yv = -8;
			shot[shot_num++]->Fire();
			
			if (shot_num >= shot_max) { shot_num = 0; }
			shot_span = 0;						// shot_span のリセット
		}
	}
}