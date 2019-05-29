#include "DxLib.h"
#include "StageScene.h"
#include "Info.h"

StageScene::StageScene() {
	info_initialize();
	player = new Player();
	for (int i = 0; i < shot_max; i++) { shot[i] = new Shot(); }
	time = 0;
}

void StageScene::Update() {
	// プレイヤーの操作
	player->Update();

	// ショットの作成
	shot[shot_num++]->Set();
	if (shot_num >= shot_max) { shot_num = 0; }

	// ショットの更新と描画
	for (int i = 0; i < shot_max; i++) { shot[i]->Update(); }

	// あたり判定
	for (int i = 0; i < shot_max; i++) {
		Collision(static_cast<Objec*>(player), static_cast<Objec*>(shot[i]));
	}

	// プレイヤーの終了判定
	if (!player->GetFlag()) { SceneChange(RESULT_SCENE); }

	// 経過時間の描画
	DrawFormatString(0, 50, GetColor(255, 255, 255), "Time : %d", time++);
}

void StageScene::Draw() {
	player->Draw();
	for (int i = 0; i < shot_max; i++) { shot[i]->Draw(); }
}