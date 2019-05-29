#pragma once
#include "Objec.h"
#include "Shot.h"

// プレイヤークラス
class Player : public Objec {
private:
	// double x, y;
	// int size;
	// bool flag;
	static int image;	// 画像ハンドル
	int hp;				// 体力
	
	int shot_num;			// プレイヤーショット配列の現在の添字
	int shot_span;			// プレイヤーショットの間隔

public:
	static const int shot_max = 50;	// プレイヤーショット配列の要素数
	Shot *shot[shot_max];	// プレイヤーショット配列

	Player();
	void Update();		// 更新
	void Draw();		// 描画

	virtual void CollisionResult();	// あたり判定後の処理

	void ShotFire();
};
