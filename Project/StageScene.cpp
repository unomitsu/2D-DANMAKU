#include "DxLib.h"
#include "StageScene.h"
#include "Info.h"

StageScene::StageScene() {
	Info_Initialize();	// �E�B���h�E�T�C�Y�Ȃǂ̏�����
	PlayerSet();		// �v���C���[�̏�����
	for (int i = 0; i < shot_max; i++) { shot[i] = new Shot(); }	// �G�l�~�[�V���b�g�̏�����
	enemy = new Enemy();	// �G�l�~�[�̏�����
	time = 0;				// �o�ߎ��Ԃ̏�����
}

void StageScene::Update() {
	// �v���C���[�̑���
	PlayerUpdate();

	// �G�l�~�[�̍X�V
	enemy->Update();

	// �V���b�g�̍쐬 �z����񂵂Ďg�p����
	shot[shot_num++]->Set(GetWidth() * GetRand(100) / 100.0, 0.0);
	if (shot_num >= shot_max) { shot_num = 0; }	// �Y�����ő�ɂȂ����� 0 �ɖ߂�

	// �V���b�g�̍X�V�ƕ`��
	for (int i = 0; i < shot_max; i++) { shot[i]->Update(); }

	//-- �����蔻��
	// �v���C���[�ƃG�l�~�[�V���b�g
	for (int i = 0; i < shot_max; i++) {
		Collision(static_cast<Objec*>(GetPlayerInstance()), static_cast<Objec*>(shot[i]));
	}
	// �v���C���[�V���b�g�ƃG�l�~�[
	for (int i = 0; i < GetPlayerInstance()->shot_max; i++) {
		Collision(static_cast<Objec*>(GetPlayerInstance()->shot[i]), static_cast<Objec*>(enemy));
	}

	//-- �I������
	// �G�l�~�[�I�������ꍇ�A�N���A
	if (!enemy->GetFlag()) { SceneChange(RESULT_SCENE_CLEAR); }
	// �v���C���[���I�������ꍇ�A���s
	if (!GetPlayerFlag()) { SceneChange(RESULT_SCENE_MISS); }

}

void StageScene::Draw() {
	PlayerDraw();	// �v���C���[�̕`��
	enemy->Draw();	// �G�l�~�[�̕`��

	for (int i = 0; i < shot_max; i++) { shot[i]->Draw(); }	// �G�l�~�[�V���b�g�̕`��

	// �o�ߎ��Ԃ̕`��
	DrawFormatString(0, 50, GetColor(255, 255, 255), "Time : %d", time++);
	DrawFormatString(0, 300, GetColor(255, 255, 255), "Time : %d", GetPlayerInstance()->shot_max);
}