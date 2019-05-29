#include "DxLib.h"
#include "Info.h"
#include "Objec.h"
#include "Scene.h"
#include "TitleScene.h"
#include "StageScene.h"
#include "ResultScene.h"
#include "Player.h"

Info* g_Info = new Info();			// データ保持
Scene* g_Scene = new TitleScene();	// シーン管理
Player* g_Player = new Player();	// プレイヤー

// 各データの初期化
void Info_Initialize() {
	GetScreenState(&g_Info->width, &g_Info->height, NULL);
}

// ウィンドウの横幅を返す
int GetWidth() {
	return g_Info->width;
}
// ウィンドウの縦幅を返す
int GetHeight() {
	return g_Info->height;
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
	double distanceR = obj1->GetHitSize() + obj2->GetHitSize();	// 2オブジェクト間の半径の和

	// 2オブジェクトが衝突したとき
	if (pow(distanceX) + pow(distanceY) < pow(distanceR)) {
		// 各オブジェクトのあたり判定後の処理をする
		obj1->CollisionResult();
		obj2->CollisionResult();
	}
}

// 現在のシーンの更新
void SceneUpdate() {
	g_Scene->Update();
}
// 現在のシーンの描画
void SceneDraw() {
	g_Scene->Draw();
}
// シーンの変更
void SceneChange(int val) {
	switch (val) {
	case STAGE_SCENE: g_Scene = new StageScene(); break;
	case RESULT_SCENE: g_Scene = new ResultScene(); break;
	case TITLE_SCENE:
	default: g_Scene = new TitleScene(); break;
	}
}

// プレイヤーのインスタンスを返す
Player* GetPlayerInstance() {
	return g_Player;
}
// プレイヤーの初期化を行う
void PlayerSet() {
	g_Player = new Player();
}
// プレイヤーの更新
void PlayerUpdate() {
	g_Player->Update();
}
// プレイヤーの描画
void PlayerDraw() {
	g_Player->Draw();
}
// プレイヤーの x座標を返す
double GetPlayerX() {
	return g_Player->GetX();
}
// プレイヤーの y座標を返す
double GetPlayerY() {
	return g_Player->GetY();
}
// プレイヤーの生存フラグを返す
bool GetPlayerFlag() {
	return g_Player->GetFlag();
}