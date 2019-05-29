#include "DxLib.h"
#include "Key.h"
#include "Info.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	// �c�w���C�u���������������A�G���[���N�����璼���ɏI��
	if (DxLib_Init() == -1) { return -1; }

	// �E�B���h�E���[�h�ŋN���A�g�債�ĕ\������
	ChangeWindowMode(TRUE);
	SetWindowSizeExtendRate(1.5);

	// �A�j���[�V�����̂�������������߂ɁA�`���𗠉�ʂɂ���
	SetDrawScreen(DX_SCREEN_BACK);

	// �w�i���D�F�ɂ��܂�
	SetBackgroundColor(100, 100, 100);

	// ProcessMessage()		Windows�A�v���̃v���O�����́A���b�Z�[�W(�C�x���g)���������Ă����B������0�A���s��-1�B
	// ScreenFlip()			����ʂ̓��e��\��ʂɔ��f����B������0�A�G���[��-1�B
	// ClearDrawScreen()	�`���̉�ʂɏ����ꂽ���̂���������B������0�A�G���[��-1�B
	while (!ProcessMessage() && !ScreenFlip() && !ClearDrawScreen()) {
		// �L�[�̓��͍X�V
		KeyUpdate();

		// �Q�[���I��
		if (GetKey(KEY_INPUT_ESCAPE)) { break; }

		// �X�V
		SceneUpdate();
		SceneDraw();
	}
	// �c�w���C�u�����g�p�̏I������
	DxLib_End();

	return 0;				// �\�t�g�̏I�� 
}

