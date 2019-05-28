#include "DxLib.h"
#include "Key.h"
#include "Player.h"
#include "Shot.h"
#include "Info.h"
#include "Objec.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	// �c�w���C�u���������������A�G���[���N�����璼���ɏI��
	if (DxLib_Init() == -1) { return -1; }

	// �E�B���h�E���[�h�ŋN���A�g�債�ĕ\������
	ChangeWindowMode(TRUE);
	SetWindowSizeExtendRate(1.5);

	// �A�j���[�V�����̂�������������߂ɁA�`���𗠉�ʂɂ���
	SetDrawScreen(DX_SCREEN_BACK);

	// -- �錾�Ə�����
	info_initialize();
	Player *player = new Player();
	static const int shot_max = 200;
	int shot_num = 0;
	Shot *shot[shot_max];
	for (int i = 0; i < shot_max; i++) { shot[i] = new Shot(); }
	// --

	// �w�i���D�F�ɂ��܂�
	SetBackgroundColor(100, 100, 100);

	// ProcessMessage()		Windows�A�v���̃v���O�����́A���b�Z�[�W(�C�x���g)���������Ă����B������0�A���s��-1�B
	// ScreenFlip()			����ʂ̓��e��\��ʂɔ��f����B������0�A�G���[��-1�B
	// ClearDrawScreen()	�`���̉�ʂɏ����ꂽ���̂���������B������0�A�G���[��-1�B
	int nnn = 0;
	while (!ProcessMessage() && !ScreenFlip() && !ClearDrawScreen()) {
		// �L�[�̓��͍X�V
		KeyUpdate();

		// �V���b�g�̍쐬
		shot[shot_num++]->Set();
		if (shot_num >= shot_max) { shot_num = 0; }

		// �V���b�g�̍X�V
		for (int i = 0; i < shot_max; i++) {
			shot[i]->Update();
			shot[i]->Draw();
		}

		// �v���C���[�̑���ƕ`��
		player->Update();
		player->Draw();
		
		// �����蔻��
		for (int i = 0; i < shot_max; i++) {
			Collision(static_cast<Objec*>(player), static_cast<Objec*>(shot[i]));
		}

		DrawFormatString(0, 50, GetColor(255, 255,255), "Time : %d", nnn++);

		if (GetKey(KEY_INPUT_ESCAPE)) { break; }
	}

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}

