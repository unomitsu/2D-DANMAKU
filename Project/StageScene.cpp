#include "DxLib.h"
#include "StageScene.h"
#include "Info.h"

StageScene::StageScene() {
	Info_Initialize();
	PlayerSet();
	for (int i = 0; i < shot_max; i++) { shot[i] = new Shot(); }
	enemy = new Enemy();
	time = 0;
}

void StageScene::Update() {
	// プレイヤーの操作
	PlayerUpdate();

	// エネミーの更新
	enemy->Update();

	// ショットの作成
	shot[shot_num++]->Set(GetWidth() * GetRand(100) / 100.0, 0.0);
	if (shot_num >= shot_max) { shot_num = 0; }

	// ショットの更新と描画
	for (int i = 0; i < shot_max; i++) { shot[i]->Update(); }

	// あたり判定
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