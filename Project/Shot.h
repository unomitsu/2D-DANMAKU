#pragma once
#include "Objec.h"

// ショットクラス
class Shot : public Objec {
private:
	// double x, y, v;
	// int size;
	// bool flag;
	static int image;	// 画像ハンドル

public:
	Shot();
	void Update();		// 更新
	void Draw();		// 描画
	virtual void CollisionResult();	// あたり判定後の処理

	void Set(double nx, double ny);	// 指定座標にショットをセットする
};

