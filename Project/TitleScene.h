#pragma once

# include "Scene.h"

// �^�C�g���V�[���N���X
class TitleScene : public Scene {
private:
	int titletextY;

public:
	TitleScene();
	void Update();	// �X�V
	void Draw();	// �`��
};