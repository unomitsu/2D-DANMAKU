#pragma once

#include "Scene.h"
#include "Player.h"
#include "Shot.h"
#include "Enemy.h"

class StageScene : public Scene {
private:
	// エネミー関連
	Enemy *enemy;
	static const int shot_max = 200;
	int shot_num = 0;
	Shot *shot[shot_max];

	int time;	// 経過時間

public:
	StageScene();
	void Update();
	void Draw();
};

