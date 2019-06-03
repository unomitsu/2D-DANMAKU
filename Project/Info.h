#pragma once

#include "Objec.h"
#include "Player.h"
#include "Enemy.h"
#include "Shot.h"
#include <vector>

enum { TITLE_SCENE, STAGE_SCENE, RESULT_SCENE_CLEAR, RESULT_SCENE_MISS };	// シーンの状態

class Info {
public:
	int width, height;		// ウィンドウの横幅と縦幅
	int stage_time;			// ステージシーンに変わってからの経過時間
	bool stage_flag;		// スレッド管理用のフラグ

	void Initialize();
	void Update();
};

Info* GetInfoInstance();		// Infoクラスのインスタンスを返す
void Info_Initialize();			// 各データの初期化
void Info_Update();				// 各データの更新
void StageFlagOff();			// スレッド処理管理用フラグを落とす
bool GetStageFlag();			// スレッド処理管理用フラグを取得する

void Collision(Objec* obj1, Objec* obj2);	// あたり判定

void SceneUpdate();				// 現在のシーンの更新
void SceneDraw();				// 現在のシーンの描画
void SceneChange(int val);		// シーンの変更

Player* GetPlayerInstance();	// プレイヤークラスのインスタンスを取得する
void PlayerSet();				// プレイヤーの初期化を行う
void PlayerUpdate();			// プレイヤーの更新
void PlayerDraw();				// プレイヤーの描画

Enemy* GetEnemyInstance();		// エネミークラスのインスタンスを取得する
void EnemySet();				// エネミーの初期化を行う
void EnemyUpdate();				// エネミーの更新
void EnemyDraw();				// エネミーの描画

Shot* GetShotInstance(int id);	// ショット配列のvectorインスタンスを取得する
void ShotUpdate();				// ショットの更新
void ShotDraw();				// ショットの描画
void ShotAdd(double nx, double ny, double nxv, double nyv);		// ショットの追加
int GetShotNum();				// ショットの数を返す

void AddNumNum();
int GetNumNum();