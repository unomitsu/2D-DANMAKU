#pragma once
#include "Objec.h"

// ショットクラス
class Shot : public Objec {
private:
	// int size;
	// bool flag;
	static int image;	// 画像ハンドル

public:
	// double x, y;
	double xv, yv;		// x方向、y方向の速度

	Shot();
	void Update();		// 更新
	void Draw();		// 描画
	virtual void CollisionResult();	// あたり判定後の処理

	void SetImage();	// 画像関連の初期化

	void Fire();		// フラグを立てて発射する
	bool InWindow();	// 画面範囲内に存在するかどうかを返す。存在する=TRUE、存在しない=FALSE
};

