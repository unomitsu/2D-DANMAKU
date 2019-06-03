#include "DxLib.h"
#include "ResultScene.h"
#include "Info.h"
#include "Key.h"

ResultScene::ResultScene(bool f) {
	flag = f;

	// �N���A���͔w�i�����F
	if (f) {
		SetBackgroundColor(200, 200, 200);
	}
	// ���N���A���͔w�i���ԐF
	else {
		SetBackgroundColor(255, 100, 100);
	}
}
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
	if (flag) {
		DrawFormatString(0, 100, GetColor(255, 255, 255), "�N���A�[");
	}
	else {
		DrawFormatString(0, 100, GetColor(255, 255, 255), "����");
	}

	DrawFormatString(0, 200, GetColor(255, 255, 255), "�X�y�[�X�L�[����������^�C�g����ʂ�");
	DrawFormatString(0, 250, GetColor(255, 255, 255), "ESC�L�[�����������߂�");
}