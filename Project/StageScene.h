#pragma once

#include "Scene.h"
#include "Player.h"
#include "Shot.h"
#include "Enemy.h"

// ステージシーンクラス
class StageScene : public Scene {
private:
	//-- enemy 関連
	Enemy *enemy;	// enemy インスタンス
	static const int shot_max = 200;	// enemy shot の最大値
	int shot_num = 0;		// enemy shot 配列添字の現在値
	Shot *shot[shot_max];	// enemy shot の配列

	int time;		// 経過時間

public:
	StageScene();
	void Update();	// 更新
	void Draw();	// 描画
};

