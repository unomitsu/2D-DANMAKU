#include "DxLib.h"
#include "ResultScene.h"
#include "Info.h"
#include "Key.h"

void ResultScene::Update() {
	// �X�y�[�X�L�[�������ꂽ�Ƃ�
	if (GetKey(KEY_INPUT_SPACE)) {
		SceneChange(TITLE_SCENE);		// �^�C�g���V�[���ֈڍs
		return;
	}
	// ESC�L�[�������ꂽ�Ƃ�
	if (GetKey(KEY_INPUT_ESCAPE)) {
		DxLib_End();					// �c�w���C�u�����g�p�̏I������
		exit(0);
	}
}

void ResultScene::Draw() {
	DrawFormatString(0, 50, GetColor(255, 255, 255), "�X�y�[�X�L�[����������^�C�g����ʂ�");
	DrawFormatString(0, 100, GetColor(255, 255, 255), "ESC�L�[�����������߂�");
}