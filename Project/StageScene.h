#pragma once

#include "Scene.h"
#include "Player.h"
#include "Shot.h"
#include "Enemy.h"
#include <thread>


// �X�e�[�W�V�[���N���X
class StageScene : public Scene {
private:
	std::thread th_stage;

public:
	StageScene();
	void Update();	// �X�V
	void Draw();	// �`��
};

