#include "Info.h"
#include "Player.h"
#include <thread>

// ウィンドウの横幅を返す
int GetWidth() {
	return GetInfoInstance()->width;
}
// ウィンドウの縦幅を返す
int GetHeight() {
	return GetInfoInstance()->height;
}
// ステージが開始されてからの経過時間を得る
int GetStageTime() {
	return GetInfoInstance()->stage_time;
}

// プレイヤーの x座標を返す
double GetPlayerX() {
	return GetPlayerInstance()->GetX();
}
// プレイヤーの y座標を返す
double GetPlayerY() {
	return GetPlayerInstance()->GetY();
}
// プレイヤーの生存フラグを返す
bool GetPlayerFlag() {
	return GetPlayerInstance()->GetFlag();
}

// エネミーのx座標を取得する
double GetEnemyX() {
	return GetEnemyInstance()->GetX();
}
// エネミーのy座標を取得する
double GetEnemyY() {
	return GetEnemyInstance()->GetY();
}
// エネミーの速度を取得する
double GetEnemyXV() {
	return GetEnemyInstance()->xv;
}
// エネミーの速度を取得する
double GetEnemyYV() {
	return GetEnemyInstance()->xv;
}
// エネミーの生存フラグを取得する
bool GetEnemyFlag() {
	return GetEnemyInstance()->GetFlag();
}
// 現在の体力割合を返す
double GetEnemyHPRate() {
	int enemy_hp_now = GetEnemyInstance()->hp_now;
	int enemy_hp_max = GetEnemyInstance()->hp_max;

	// 現在の体力が 0 以下の場合、0.0%を返す
	if (enemy_hp_now <= 0) { return 0.0; }

	// 0 以下でない場合は、計算した結果を返す
	return (double)enemy_hp_now / enemy_hp_max;
}

// エネミーのx方向の速度を設定する
void SetEnemyXV(double nxv) {
	GetEnemyInstance()->xv = nxv;
}
// エネミーのy方向の速度を設定する
void SetEnemyYV(double nyv) {
	GetEnemyInstance()->yv = nyv;
}

// 指定座標(x, y)に速度 v のショットを設置する
void SetShot(double nx, double ny, double nxv, double nyv) {
	// vector配列へ末尾追加
	ShotAdd(nx, ny, nxv, nyv);
}

void Loop(double time) {
	std::this_thread::sleep_for(std::chrono::milliseconds((int)(time * 1000)));
}