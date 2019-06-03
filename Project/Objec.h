#pragma once

// オブジェクトクラス player, enemy, shot
class Objec {
protected:
	int size;		// 画像サイズ
	int hit_size;	// あたり判定の大きさ
	bool flag;		// 生存フラグ
	//static int image;

public:
	double x, y;	// x座標、y座標

	virtual void Update() {}	// 更新
	virtual void Draw() {}		// 描画
	virtual void CollisionResult() {}	// あたり判定後の処理

	double GetX() { return x; }		// オブジェクトのx座標を取得
	double GetY() { return y; }		// オブジェクトのy座標を取得
	int GetSize() { return size; }	// オブジェクトの画像サイズを取得
	int GetHitSize() { return hit_size; }	// オブジェクトのあたり判定の大きさを取得
	bool GetFlag() { return flag; }	// オブジェクトの生存フラグを取得
};

