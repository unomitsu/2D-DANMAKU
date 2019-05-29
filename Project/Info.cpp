#include "DxLib.h"
#include "Info.h"
#include "Objec.h"
#include "Scene.h"
#include "TitleScene.h"
#include "StageScene.h"
#include "ResultScene.h"

// ウィンドウの横幅と縦幅
int g_Width, g_Height;

// ウィンドウの横幅と縦幅（とColorBitDepth）を取得
void info_initialize() {
	GetScreenState(&g_Width, &g_Height, NULL);
}

// ウィンドウの横幅を返す
int GetWidth() {
	return g_Width;
}
// ウィンドウの縦幅を返す
int GetHeight() {
	return g_Height;
}

// 2乗を返す
double pow(double x) {
	return x * x;
}

// あたり判定
void Collision(Objec* obj1, Objec* obj2) {
	// 両方が有効であるかの確認
	if (!(obj1->GetFlag() && obj2->GetFlag())) { return; }

	// あたり判定の計算、三平方の定理
	double distanceX = obj1->GetX() - obj2->GetX();		// 2オブジェクト間のx座標の差
	double distanceY = obj1->GetY() - obj2->GetY();		// 2オブジェクト間のy座標の差
	double distanceR = obj1->GetSize() / 8 + obj2->GetSize() / 2;	// 2オブジェクト間の半径の和

	// 2オブジェクトが衝突したとき
	if (pow(distanceX) + pow(distanceY) < pow(distanceR)) {
		// 各オブジェクトのあたり判定後の処理をする
		obj1->CollisionResult();
		obj2->CollisionResult();
	}
}

// シーン管理
Scene* scene = new TitleScene();

// 現在のシーンの更新
void SceneUpdate() {
	scene->Update();
}
// 現在のシーンの描画
void SceneDraw() {
	scene->Draw();
}
// シーンの変更
void SceneChange(int val) {
	switch (val) {
	case STAGE_SCENE: scene = new StageScene(); break;
	case RESULT_SCENE: scene = new ResultScene(); break;
	case TITLE_SCENE:
	default: scene = new TitleScene(); break;
	}
}
