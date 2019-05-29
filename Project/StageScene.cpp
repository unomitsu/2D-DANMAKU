#include "DxLib.h"
#include "StageScene.h"
#include "Info.h"

StageScene::StageScene() {
	Info_Initialize();	// ウィンドウサイズなどの初期化
	PlayerSet();		// プレイヤーの初期化
	for (int i = 0; i < shot_max; i++) { shot[i] = new Shot(); }	// エネミーショットの初期化
	enemy = new Enemy();	// エネミーの初期化
	time = 0;				// 経過時間の初期化
}

void StageScene::Update() {
	// プレイヤーの操作
	PlayerUpdate();

	// エネミーの更新
	enemy->Update();

	// ショットの作成 配列を回して使用する
	shot[shot_num++]->Set(GetWidth() * GetRand(100) / 100.0, 0.0);
	if (shot_num >= shot_max) { shot_num = 0; }	// 添字が最大になったら 0 に戻す

	// ショットの更新と描画
	for (int i = 0; i < shot_max; i++) { shot[i]->Update(); }

	//-- あたり判定
	// プレイヤーとエネミーショット
	for (int i = 0; i < shot_max; i++) {
		Collision(static_cast<Objec*>(GetPlayerInstance()), static_cast<Objec*>(shot[i]));
	}

	// プレイヤーの終了判定
	if (!GetPlayerFlag()) { SceneChange(RESULT_SCENE); }

}

void StageScene::Draw() {
	PlayerDraw();	// プレイヤーの描画
	enemy->Draw();	// エネミーの描画

	for (int i = 0; i < shot_max; i++) { shot[i]->Draw(); }	// エネミーショットの描画

	// 経過時間の描画
	DrawFormatString(0, 50, GetColor(255, 255, 255), "Time : %d", time++);
}