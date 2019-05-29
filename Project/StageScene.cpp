#include "DxLib.h"
#include "StageScene.h"
#include "Info.h"

StageScene::StageScene() {
	info_initialize();
	player = new Player();
	for (int i = 0; i < shot_max; i++) { shot[i] = new Shot(); }
	time = 0;
}

void StageScene::Update() {
	// �v���C���[�̑���
	player->Update();

	// �V���b�g�̍쐬
	shot[shot_num++]->Set();
	if (shot_num >= shot_max) { shot_num = 0; }

	// �V���b�g�̍X�V�ƕ`��
	for (int i = 0; i < shot_max; i++) { shot[i]->Update(); }

	// �����蔻��
	for (int i = 0; i < shot_max; i++) {
		Collision(static_cast<Objec*>(player), static_cast<Objec*>(shot[i]));
	}

	// �v���C���[�̏I������
	if (!player->GetFlag()) { SceneChange(RESULT_SCENE); }

	// �o�ߎ��Ԃ̕`��
	DrawFormatString(0, 50, GetColor(255, 255, 255), "Time : %d", time++);
}

void StageScene::Draw() {
	player->Draw();
	for (int i = 0; i < shot_max; i++) { shot[i]->Draw(); }
}