#include "DxLib.h"
#include "TitleScene.h"
#include "Info.h"

TitleScene::TitleScene() {
	titletextY = 0;	// �^�C�g���e�L�X�g��y���W
}
// �X�V
void TitleScene::Update() {
	// �e�L�X�g�̈ʒu�� 100 ��菬�����Ƃ�
	if (titletextY < 100) {
		// ���Z���ďI��
		titletextY += 5;
		return;
	}

	// �X�y�[�X�L�[�������ꂽ�Ƃ�
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		SceneChange(STAGE_SCENE);		// �X�e�[�W�V�[���ֈڍs
	}
}

// �`��
void TitleScene::Draw() {
	DrawFormatString(0, titletextY, GetColor(255, 255, 255), "�X�y�[�X�L�[����������X�^�[�g");		// �e�L�X�g��\��
}