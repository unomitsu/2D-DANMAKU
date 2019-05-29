#pragma once
#include "Objec.h"

// プレイヤークラス
class Player : public Objec {
private:
	// double x, y;
	// int size;
	// bool flag;
	static int image;	// 画像ハンドル
	int hp;				// 体力

public:
	Player();
	void Update();		// 更新
	void Draw();		// 描画
	virtual void CollisionResult();	// あたり判定後の処理
};
