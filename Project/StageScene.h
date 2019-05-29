#pragma once

#include "Scene.h"
#include "Player.h"
#include "Shot.h"
#include "Enemy.h"

class StageScene : public Scene {
private:
	// �G�l�~�[�֘A
	Enemy *enemy;
	static const int shot_max = 200;
	int shot_num = 0;
	Shot *shot[shot_max];

	int time;	// �o�ߎ���

public:
	StageScene();
	void Update();
	void Draw();
};

