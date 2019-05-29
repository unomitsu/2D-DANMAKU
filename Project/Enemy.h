#pragma once
#include "Objec.h"

// エネミークラス
class Enemy : public Objec {
private:
	// double x, y, v;
	// int size;
	// bool flag;
	static int image;	// 画像ハンドル
	int hp;				// 体力
	int span;			// 行動間隔

public:
	Enemy();
	void Update();	// 更新
	void Draw();	// 描画
	virtual void CollisionResult();	// あたり判定後の処理

	void Movement();	// 行動内容
};