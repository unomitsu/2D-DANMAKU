#include "DxLib.h"
#include "Info.h"
#include "Objec.h"
#include "Scene.h"
#include "TitleScene.h"
#include "StageScene.h"
#include "ResultScene.h"
#include "Player.h"
#include "Enemy.h"
#include "Shot.h"
#include <vector>

Info* g_Info = new Info();			// データ保持
Scene* g_Scene = new TitleScene();	// シーン管理
Player* g_Player = new Player();	// プレイヤー
Enemy* g_Enemy = new Enemy();		// エネミー
std::vector<Shot> g_Shot(0);			// ショット配列

// Infoクラスの初期化
void Info::Initialize() {
	GetScreenState(&width, &height, NULL);
	stage_time = 0;
}
// Infoクラスの更新
void Info::Update() {
	stage_time++;	// 経過時間の加算
}

// Infoクラスのインスタンスを返す
Info* GetInfoInstance() {
	return g_Info;
}
// 各データの初期化
void Info_Initialize() {
	g_Info->Initialize();
}
// 各データの更新
void Info_Update() {
	g_Info->Update();
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
	case RESULT_SCENE_CLEAR: g_Scene = new ResultScene(TRUE); break;
	case RESULT_SCENE_MISS: g_Scene = new ResultScene(FALSE); break;
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

// エネミークラスのインスタンスを取得する
Enemy* GetEnemyInstance() {
	return g_Enemy;
}
// エネミーの初期化を行う
void EnemySet() {
	g_Enemy = new Enemy();
}

// エネミーの更新
void EnemyUpdate() {
	g_Enemy->Update();
}
// エネミーの描画
void EnemyDraw() {
	g_Enemy->Draw();
}

// ショット配列のvectorインスタンスを取得する
Shot* GetShotInstance(int id) {
	return &g_Shot.at(id);
}
// ショットの更新
void ShotUpdate() {
	for (auto i = g_Shot.begin(); i != g_Shot.end(); ++i) {
		i->Update();	// 更新

		// 有効でなくなった、もしくは範囲外に出た場合、このデータを削除する
		// 削除すると、全データが前にずらされるため、インクリメントを実行しない
		if (! i->GetFlag() || i->InWindow()) {
			g_Shot.erase(i);
			continue;
		}
	}
}
// ショットの描画
void ShotDraw() {
	for (auto i = g_Shot.begin(); i != g_Shot.end(); ++i) {
		i->Draw();
	}
}
// ショットの追加
void ShotAdd(Shot shot) {
	g_Shot.push_back(shot);
}
// ショットの追加
int GetShotNum() {
	return static_cast<int>(g_Shot.size());
}

int g_NumNum = 0;
void AddNumNum() {
	g_NumNum++;
}
int GetNumNum() {
	return g_NumNum;
}