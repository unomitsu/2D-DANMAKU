#include "DxLib.h"
#include "StageScene.h"
#include "Info.h"
#include "Lib.h"

void ThStage() {
	int time = 0;	// 基準時間

	// 体力が 半分以上あるとき
	while (GetPlayerFlag() && GetEnemyHPRate() >= 0.5) {
		// ショットの設定
		for (int i = 0; i < 10; i++) {
			SetShot(GetWidth() * GetRand(100) / 100.0, 0.0, 0, 1.0 + GetRand(40) / 10.0);
		}
		// エネミーの動作、1s 経過するごとに
		if (time % 2 == 0) {
			//　プレイヤーより左にいるとき右に動く(xは増加)
			if (GetEnemyX() < GetPlayerX()) {
				SetEnemyXV(4.0);
			}
			//　プレイヤーより右にいるとき左に動く(xは減少)
			else {
				SetEnemyXV(-4.0);
			}
		}
		Loop(0.4);
		SetEnemyXV(0.0);

		// 待ち時間 10s
		Loop(0.6);
	}
	
	time = 0;	// 基準時間
	
	// 体力が半分以下になった時
	while (GetPlayerFlag() && GetEnemyFlag()) {
		// 弾発射
		for (int i = 0; i < 10; i++) {
			double nxv = GetRand(40) / 10.0 - 2.0;
			double nyv = GetRand(40) / 10.0 - 2.0;
			SetShot(GetEnemyX(), GetEnemyY(), nxv, nyv);
		}
		Loop(1.0);
	}

}

StageScene::StageScene() {
	Info_Initialize();	// ウィンドウサイズなどの初期化
	PlayerSet();		// プレイヤーの初期化
	EnemySet();			// エネミーの初期化

	// スレッドの開始
	std::thread th_st(ThStage);
	th_stage = std::move(th_st);
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
		th_stage.join();			// スレッド終了まで待つ
		SceneChange(RESULT_SCENE_CLEAR);
	}
	// プレイヤーが終了した場合、失敗
	if (!GetPlayerFlag()) {
		th_stage.join();			// スレッド終了まで待つ
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