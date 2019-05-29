#include "DxLib.h"
#include "TitleScene.h"
#include "Info.h"

TitleScene::TitleScene() {
	titletextY = 0;	// タイトルテキストのy座標
}
// 更新
void TitleScene::Update() {
	// テキストの位置が 100 より小さいとき
	if (titletextY < 100) {
		// 加算して終了
		titletextY += 5;
		return;
	}

	// スペースキーが押されたとき
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		SceneChange(STAGE_SCENE);		// ステージシーンへ移行
	}
}

// 描画
void TitleScene::Draw() {
	DrawFormatString(0, titletextY, GetColor(255, 255, 255), "スペースキーを押したらスタート");		// テキストを表示
}