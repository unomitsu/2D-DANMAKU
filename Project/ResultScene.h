#pragma once
#include "Scene.h"

// ���U���g�V�[��
class ResultScene : public Scene {
private:
	bool flag;	// �N���A���ǂ���

public:
	ResultScene(bool f);
	void Update();	// �X�V
	void Draw();	// �`��
};