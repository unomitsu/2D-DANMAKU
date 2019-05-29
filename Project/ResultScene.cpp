#include "DxLib.h"
#include "ResultScene.h"
#include "Info.h"
#include "Key.h"

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
	DrawFormatString(0, 50, GetColor(255, 255, 255), "スペースキーを押したらタイトル画面へ");
	DrawFormatString(0, 100, GetColor(255, 255, 255), "ESCキーを押したらやめる");
}