#include "DxLib.h"
#include "Key.h"
#include "Info.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	// ＤＸライブラリ初期化処理、エラーが起きたら直ちに終了
	if (DxLib_Init() == -1) { return -1; }

	// ウィンドウモードで起動、拡大して表示する
	ChangeWindowMode(TRUE);
	SetWindowSizeExtendRate(1.5);

	// アニメーションのちらつきを消すために、描画先を裏画面にする
	SetDrawScreen(DX_SCREEN_BACK);

	// 背景を灰色にします
	SetBackgroundColor(100, 100, 100);

	// ProcessMessage()		Windowsアプリのプログラムの、メッセージ(イベント)処理をしてくれる。成功で0、失敗で-1。
	// ScreenFlip()			裏画面の内容を表画面に反映する。成功で0、エラーで-1。
	// ClearDrawScreen()	描画先の画面に書かれたものを消去する。成功で0、エラーで-1。
	while (!ProcessMessage() && !ScreenFlip() && !ClearDrawScreen()) {
		// キーの入力更新
		KeyUpdate();

		// ゲーム終了
		if (GetKey(KEY_INPUT_ESCAPE)) { break; }

		// 更新
		SceneUpdate();
		SceneDraw();
	}
	// ＤＸライブラリ使用の終了処理
	DxLib_End();

	return 0;				// ソフトの終了 
}

