#include "DxLib.h"
#include "StageScene.h"
#include "Info.h"
#include "Lib.h"

void numnumnum() {
	int time = GetStageTime();	// 基準時間

	/*
	// 体力が 半分以上あるとき
	while (GetEnemyHPRate() >= 0.5) {
		int t = GetStageTime() - time;

		// ショットの設定、10フレームごとに
		if (t % 10 == 0) {
			SetShot(GetWidth() * GetRand(100) / 100.0, 0.0, 0, 8);
		}
		// エネミーの動作、100フレーム経過するごとに
		if (t == 100) {
			//　プレイヤーより左にいるとき右に動く(xは増加)
			if (GetEnemyX() < GetPlayerX()) {
				if (GetEnemyXV() > 0) {
					SetEnemyXV(GetEnemyXV());
				}
				else {
					SetEnemyXV(-GetEnemyXV());
				}
			}
			//　プレイヤーより右にいるとき左に動く(xは減少)
			else {
				if (GetEnemyXV() > 0) {
					SetEnemyXV(-GetEnemyXV());
				}
				else {
					SetEnemyXV(GetEnemyXV());
				}
			}
			// 基準時間の更新
			time = GetStageTime();
		}
	}

	// 体力が半分以下になった時
	while (GetEnemyFlag()) {
		// 30フレーム経過するごとに
		if (GetStageTime() - time == 100) {


			// 基準時間の更新
			time = GetStageTime();
		}
	}
	*/
}

StageScene::StageScene() {
	Info_Initialize();	// ウィンドウサイズなどの初期化
	PlayerSet();		// プレイヤーの初期化
	EnemySet();			// エネミーの初期化

	// スレッドの開始
	std::thread ttth(numnumnum);
	th = std::move(ttth);
}

void StageScene::Update() {
	PlayerUpdate();			// プレイヤーの操作
	EnemyUpdate();			// エネミーの更新
	ShotUpdate();			// ショットの更新
	Info_Update();			// 各データの更新

	//-- あたり判定
	// プレイヤーとエネミーショット
	for (int i = 0; i < GetShotNum(); i++) {
		Collision(static_cast<Objec*>(GetPlayerInstance()), static_cast<Objec*>(GetShotInstance(i)));
	}
	// プレイヤーショットとのあたり判定
	for (int i = 0; i < GetPlayerInstance()->shot_max; i++) {
		Collision(static_cast<Objec*>(GetPlayerInstance()->shot[i]), static_cast<Objec*>(GetEnemyInstance()));
	}

	//-- 終了判定
	// エネミー終了した場合、クリア
	if (!GetEnemyFlag()) {
		th.join();			// スレッド終了まで待つ
		SceneChange(RESULT_SCENE_CLEAR);
	}
	// プレイヤーが終了した場合、失敗
	if (!GetPlayerFlag()) {
		th.join();			// スレッド終了まで待つ
		SceneChange(RESULT_SCENE_MISS);
	}
}

void StageScene::Draw() {
	PlayerDraw();		// プレイヤーの描画
	EnemyDraw();		// エネミーの描画
	ShotDraw();			// ショットの描画

	// 経過時間の描画
	DrawFormatString(0, 100, GetColor(255, 255, 255), "Time : %d", GetStageTime());

	DrawFormatString(0, 150, GetColor(255, 255, 255), "Tdsaime : %d", GetShotNum());
}