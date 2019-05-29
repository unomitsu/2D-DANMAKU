#pragma once

#include "Scene.h"
#include "Player.h"
#include "Shot.h"
#include "Enemy.h"

// �X�e�[�W�V�[���N���X
class StageScene : public Scene {
private:
	//-- enemy �֘A
	Enemy *enemy;	// enemy �C���X�^���X
	static const int shot_max = 200;	// enemy shot �̍ő�l
	int shot_num = 0;		// enemy shot �z��Y���̌��ݒl
	Shot *shot[shot_max];	// enemy shot �̔z��

	int time;		// �o�ߎ���

public:
	StageScene();
	void Update();	// �X�V
	void Draw();	// �`��
};

