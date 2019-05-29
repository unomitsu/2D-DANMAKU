#pragma once

#include "Objec.h"
#include "Scene.h"
#include "Player.h"

enum { TITLE_SCENE, STAGE_SCENE, RESULT_SCENE };	// シーンの状態

class Info {
public:
	int width, height;		// ウィンドウの横幅と縦幅
};

void Info_Initialize();	// 各データの初期化
int GetWidth();			// ウィンドウの横幅を得る
int GetHeight();		// ウィンドウの縦幅を得る

void Collision(Objec* obj1, Objec* obj2);	// あたり判定

void SceneUpdate();			// 現在のシーンの更新
void SceneDraw();			// 現在のシーンの描画
void SceneChange(int val);	// シーンの変更

Player* GetPlayerInstance();	// プレイヤークラスのインスタンスを取得する
void PlayerSet();		// プレイヤーの初期化を行う
void PlayerUpdate();	// プレイヤーの更新
void PlayerDraw();		// プレイヤーの描画
double GetPlayerX();	// プレイヤーのx座標を取得する
double GetPlayerY();	// プレイヤーのy座標を取得する
bool GetPlayerFlag();	// プレイヤーの生存フラグを取得する