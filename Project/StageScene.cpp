#include "DxLib.h"
#include "StageScene.h"
#include "Info.h"

StageScene::StageScene() {
	Info_Initialize();
	PlayerSet();
	for (int i = 0; i < shot_max; i++) { shot[i] = new Shot(); }
	enemy = new Enemy();
	time = 0;
}

void StageScene::Update() {
	// �v���C���[�̑���
	PlayerUpdate();

	// �G�l�~�[�̍X�V
	enemy->Update();

	// �V���b�g�̍쐬
	shot[shot_num++]->Set(GetWidth() * GetRand(100) / 100.0, 0.0);
	if (shot_num >= shot_max) { shot_num = 0; }

	// �V���b�g�̍X�V�ƕ`��
	for (int i = 0; i < shot_max; i++) { shot[i]->Update(); }

	// �����蔻��
	for (int i = 0; i < shot_max; i++) {
		Collision(static_cast<Objec*>(GetPlayerInstance()), static_cast<Objec*>(shot[i]));
	}

	// �v���C���[�̏I������
	if (!GetPlayerFlag()) { SceneChange(RESULT_SCENE); }

}

void StageScene::Draw() {
	PlayerDraw();	// �v���C���[�̕`��
	enemy->Draw();	// �G�l�~�[�̕`��

	for (int i = 0; i < shot_max; i++) { shot[i]->Draw(); }	// �G�l�~�[�V���b�g�̕`��

	// �o�ߎ��Ԃ̕`��
	DrawFormatString(0, 50, GetColor(255, 255, 255), "Time : %d", time++);
}