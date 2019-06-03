#include "DxLib.h"
#include "StageScene.h"
#include "Info.h"
#include "Lib.h"

void numnumnum() {
	int time = GetStageTime();	// �����

	/*
	// �̗͂� �����ȏ゠��Ƃ�
	while (GetEnemyHPRate() >= 0.5) {
		int t = GetStageTime() - time;

		// �V���b�g�̐ݒ�A10�t���[�����Ƃ�
		if (t % 10 == 0) {
			SetShot(GetWidth() * GetRand(100) / 100.0, 0.0, 0, 8);
		}
		// �G�l�~�[�̓���A100�t���[���o�߂��邲�Ƃ�
		if (t == 100) {
			//�@�v���C���[��荶�ɂ���Ƃ��E�ɓ���(x�͑���)
			if (GetEnemyX() < GetPlayerX()) {
				if (GetEnemyXV() > 0) {
					SetEnemyXV(GetEnemyXV());
				}
				else {
					SetEnemyXV(-GetEnemyXV());
				}
			}
			//�@�v���C���[���E�ɂ���Ƃ����ɓ���(x�͌���)
			else {
				if (GetEnemyXV() > 0) {
					SetEnemyXV(-GetEnemyXV());
				}
				else {
					SetEnemyXV(GetEnemyXV());
				}
			}
			// ����Ԃ̍X�V
			time = GetStageTime();
		}
	}

	// �̗͂������ȉ��ɂȂ�����
	while (GetEnemyFlag()) {
		// 30�t���[���o�߂��邲�Ƃ�
		if (GetStageTime() - time == 100) {


			// ����Ԃ̍X�V
			time = GetStageTime();
		}
	}
	*/
}

StageScene::StageScene() {
	Info_Initialize();	// �E�B���h�E�T�C�Y�Ȃǂ̏�����
	PlayerSet();		// �v���C���[�̏�����
	EnemySet();			// �G�l�~�[�̏�����

	// �X���b�h�̊J�n
	std::thread ttth(numnumnum);
	th = std::move(ttth);
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
		th.join();			// �X���b�h�I���܂ő҂�
		SceneChange(RESULT_SCENE_CLEAR);
	}
	// �v���C���[���I�������ꍇ�A���s
	if (!GetPlayerFlag()) {
		th.join();			// �X���b�h�I���܂ő҂�
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