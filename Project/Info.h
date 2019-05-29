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

Player* GetPlayerInstance();
void PlayerSet();
void PlayerUpdate();
void PlayerDraw();
double GetPlayerX();
double GetPlayerY();
bool GetPlayerFlag();