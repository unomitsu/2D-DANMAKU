#pragma once

#include "Objec.h"

// シーンの状態
enum { TITLE_SCENE, STAGE_SCENE, RESULT_SCENE };

void info_initialize();	// 各初期化
int GetWidth();			// ウィンドウの横幅を得る
int GetHeight();		// ウィンドウの縦幅を得る

void Collision(Objec* obj1, Objec* obj2);	// あたり判定

void SceneUpdate();			// 現在のシーンの更新
void SceneDraw();			// 現在のシーンの描画
void SceneChange(int val);	// シーンの変更
