#pragma once

# include "Scene.h"

// �^�C�g���V�[���N���X
class TitleScene : public Scene {
private:
	int titletextY;	// �^�C�g���̃e�L�X�g��Y���W

public:
	TitleScene();
	void Update();	// �X�V
	void Draw();	// �`��
};