#include "DxLib.h"
#include "Key.h"
#include "Player.h"
#include "Shot.h"
#include "Info.h"
#include "Objec.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	// ＤＸライブラリ初期化処理、エラーが起きたら直ちに終了
	if (DxLib_Init() == -1) { return -1; }

	// ウィンドウモードで起動、拡大して表示する
	ChangeWindowMode(TRUE);
	SetWindowSizeExtendRate(1.5);

	// アニメーションのちらつきを消すために、描画先を裏画面にする
	SetDrawScreen(DX_SCREEN_BACK);

	// -- 宣言と初期化
	info_initialize();
	Player *player = new Player();
	static const int shot_max = 200;
	int shot_num = 0;
	Shot *shot[shot_max];
	for (int i = 0; i < shot_max; i++) { shot[i] = new Shot(); }
	// --

	// 背景を灰色にします
	SetBackgroundColor(100, 100, 100);

	// ProcessMessage()		Windowsアプリのプログラムの、メッセージ(イベント)処理をしてくれる。成功で0、失敗で-1。
	// ScreenFlip()			裏画面の内容を表画面に反映する。成功で0、エラーで-1。
	// ClearDrawScreen()	描画先の画面に書かれたものを消去する。成功で0、エラーで-1。
	int nnn = 0;
	while (!ProcessMessage() && !ScreenFlip() && !ClearDrawScreen()) {
		// キーの入力更新
		KeyUpdate();

		// ショットの作成
		shot[shot_num++]->Set();
		if (shot_num >= shot_max) { shot_num = 0; }

		// ショットの更新
		for (int i = 0; i < shot_max; i++) {
			shot[i]->Update();
			shot[i]->Draw();
		}

		// プレイヤーの操作と描画
		player->Update();
		player->Draw();
		
		// あたり判定
		for (int i = 0; i < shot_max; i++) {
			Collision(static_cast<Objec*>(player), static_cast<Objec*>(shot[i]));
		}

		DrawFormatString(0, 50, GetColor(255, 255,255), "Time : %d", nnn++);

		if (GetKey(KEY_INPUT_ESCAPE)) { break; }
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}

