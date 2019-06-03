#include "DxLib.h"
#include "ResultScene.h"
#include "Info.h"
#include "Key.h"

ResultScene::ResultScene(bool f) {
	flag = f;

	// クリア時は背景が白色
	if (f) {
		SetBackgroundColor(200, 200, 200);
	}
	// 未クリア時は背景が赤色
	else {
		SetBackgroundColor(255, 100, 100);
	}
}
void ResultScene::Update() {
	// スペースキーが押されたとき
	if (GetKey(KEY_INPUT_SPACE)) {
		SceneChange(TITLE_SCENE);		// タイトルシーンへ移行
		return;
	}
	// ESCキーが押されたとき
	if (GetKey(KEY_INPUT_ESCAPE)) {
		DxLib_End();					// ＤＸライブラリ使用の終了処理
		exit(0);
	}
}

void ResultScene::Draw() {
	if (flag) {
		DrawFormatString(0, 100, GetColor(255, 255, 255), "クリアー");
	}
	else {
		DrawFormatString(0, 100, GetColor(255, 255, 255), "死んだ");
	}

	DrawFormatString(0, 200, GetColor(255, 255, 255), "スペースキーを押したらタイトル画面へ");
	DrawFormatString(0, 250, GetColor(255, 255, 255), "ESCキーを押したらやめる");
}