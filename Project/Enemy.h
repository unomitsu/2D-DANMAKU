#pragma once
#include "Objec.h"

// エネミークラス
class Enemy : public Objec {
private:
	// int size;
	// bool flag;
	static int image;	// 画像ハンドル

public:
	// double x, y;
	double xv, yv;		// x方向、y方向の速度
	int hp_now, hp_max;	// 体力

	Enemy();
	void Update();	// 更新
	void Draw();	// 描画
	virtual void CollisionResult();	// あたり判定後の処理

	void SetImage();	// 画像関連の設定
};