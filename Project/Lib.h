#pragma once

int GetWidth();			// ウィンドウの横幅を得る
int GetHeight();		// ウィンドウの縦幅を得る
int GetStageTime();		// ステージが開始されてからの経過時間を得る

double GetPlayerX();	// プレイヤーのx座標を取得する
double GetPlayerY();	// プレイヤーのy座標を取得する
bool GetPlayerFlag();	// プレイヤーの生存フラグを取得する

double GetEnemyX();		// エネミーのx座標を取得する
double GetEnemyY();		// エネミーのy座標を取得する
double GetEnemyXV();	// エネミーのx方向の速度を取得する
double GetEnemyYV();	// エネミーのy方向の速度を取得する
bool GetEnemyFlag();	// エネミーの生存フラグを取得する
double GetEnemyHPRate();	// 現在の体力割合を返す

void SetEnemyXV(double nxv);	// エネミーのx方向の速度を設定する
void SetEnemyYV(double nyv);	// エネミーのy方向の速度を設定する

void SetShot(double nx, double ny, double nxv, double nyv);	// 指定座標(nx, ny)に速度 (nxv, nyv) のショットを設置する

void Loop(double time);