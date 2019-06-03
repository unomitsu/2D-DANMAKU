#pragma once
#include "Objec.h"
#include "Shot.h"

// プレイヤークラス
class Player : public Objec {
private:
	// int size;
	// bool flag;
	static int image;		// 画像ハンドル
	
	int shot_num;			// プレイヤーショット配列の現在の添字
	int shot_span;			// プレイヤーショットの間隔

public:
	// double x, y;
	double v;							// 移動速度
	int hp_now, hp_max;		// 現在の体力、最大の体力

	static const int shot_max = 50;		// プレイヤーショット配列の要素数
	Shot *shot[shot_max];				// プレイヤーショット配列

	Player();
	void Update();		// 更新
	void Draw();		// 描画
	virtual void CollisionResult();	// あたり判定後の処理

	void SetImage();	// 画像関連の設定
	void SetShot();		// プレイヤーショットの設定
	void ShotFire();	// プレイヤーショットの発射
};
