#include "DxLib.h"
#include "StageScene.h"
#include "Info.h"
#include "Lib.h"

void ThStage() {
	int time = 0;	// �����

	// �̗͂� �����ȏ゠��Ƃ�
	while (GetPlayerFlag() && GetEnemyHPRate() >= 0.5) {
		// �V���b�g�̐ݒ�
		for (int i = 0; i < 10; i++) {
			SetShot(GetWidth() * GetRand(100) / 100.0, 0.0, 0, 1.0 + GetRand(40) / 10.0);
		}
		// �G�l�~�[�̓���A1s �o�߂��邲�Ƃ�
		if (time % 2 == 0) {
			//�@�v���C���[��荶�ɂ���Ƃ��E�ɓ���(x�͑���)
			if (GetEnemyX() < GetPlayerX()) {
				SetEnemyXV(4.0);
			}
			//�@�v���C���[���E�ɂ���Ƃ����ɓ���(x�͌���)
			else {
				SetEnemyXV(-4.0);
			}
		}
		Loop(0.4);
		SetEnemyXV(0.0);

		// �҂����� 10s
		Loop(0.6);
	}
	
	time = 0;	// �����
	
	// �̗͂������ȉ��ɂȂ�����
	while (GetPlayerFlag() && GetEnemyFlag()) {
		// �e����
		for (int i = 0; i < 10; i++) {
			double nxv = GetRand(40) / 10.0 - 2.0;
			double nyv = GetRand(40) / 10.0 - 2.0;
			SetShot(GetEnemyX(), GetEnemyY(), nxv, nyv);
		}
		Loop(1.0);
	}

}

StageScene::StageScene() {
	Info_Initialize();	// �E�B���h�E�T�C�Y�Ȃǂ̏�����
	PlayerSet();		// �v���C���[�̏�����
	EnemySet();			// �G�l�~�[�̏�����

	// �X���b�h�̊J�n
	std::thread th_st(ThStage);
	th_stage = std::move(th_st);
}

void StageScene::Update() {
	PlayerUpdate();			// �v���C���[�̑���
	EnemyUpdate();			// �G�l�~�[�̍X�V
	ShotUpdate();			// �V���b�g�̍X�V
	Info_Update();			// �e�f�[�^�̍X�V

	//-- �����蔻��
	// �v���C���[�ƃG�l�~�[�V���b�g
	for (int i = 0; i < GetShotNum(); i++) {
		Collision(static_cast<Objec*>(GetPlayerInstance()), static_cast<Objec*>(GetShotInstance(i)));
	}
	// �v���C���[�V���b�g�Ƃ̂����蔻��
	for (int i = 0; i < GetPlayerInstance()->shot_max; i++) {
		Collision(static_cast<Objec*>(GetPlayerInstance()->shot[i]), static_cast<Objec*>(GetEnemyInstance()));
	}
	//-- �I������
	// �G�l�~�[�I�������ꍇ�A�N���A
	if (!GetEnemyFlag()) {
		th_stage.join();			// �X���b�h�I���܂ő҂�
		SceneChange(RESULT_SCENE_CLEAR);
	}
	// �v���C���[���I�������ꍇ�A���s
	if (!GetPlayerFlag()) {
		th_stage.join();			// �X���b�h�I���܂ő҂�
		SceneChange(RESULT_SCENE_MISS);
	}
}

void StageScene::Draw() {
	PlayerDraw();		// �v���C���[�̕`��
	EnemyDraw();		// �G�l�~�[�̕`��
	ShotDraw();			// �V���b�g�̕`��

	// �o�ߎ��Ԃ̕`��
	DrawFormatString(0, 100, GetColor(255, 255, 255), "Time : %d", GetStageTime());

	DrawFormatString(0, 150, GetColor(255, 255, 255), "Tdsaime : %d", GetShotNum());
}