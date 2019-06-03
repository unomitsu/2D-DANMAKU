#pragma once

#include "Objec.h"
#include "Player.h"
#include "Enemy.h"
#include "Shot.h"
#include <vector>

enum { TITLE_SCENE, STAGE_SCENE, RESULT_SCENE_CLEAR, RESULT_SCENE_MISS };	// �V�[���̏��

class Info {
public:
	int width, height;		// �E�B���h�E�̉����Əc��
	int stage_time;			// �X�e�[�W�V�[���ɕς���Ă���̌o�ߎ���
	bool stage_flag;		// �X���b�h�Ǘ��p�̃t���O

	void Initialize();
	void Update();
};

Info* GetInfoInstance();		// Info�N���X�̃C���X�^���X��Ԃ�
void Info_Initialize();			// �e�f�[�^�̏�����
void Info_Update();				// �e�f�[�^�̍X�V
void StageFlagOff();			// �X���b�h�����Ǘ��p�t���O�𗎂Ƃ�
bool GetStageFlag();			// �X���b�h�����Ǘ��p�t���O���擾����

void Collision(Objec* obj1, Objec* obj2);	// �����蔻��

void SceneUpdate();				// ���݂̃V�[���̍X�V
void SceneDraw();				// ���݂̃V�[���̕`��
void SceneChange(int val);		// �V�[���̕ύX

Player* GetPlayerInstance();	// �v���C���[�N���X�̃C���X�^���X���擾����
void PlayerSet();				// �v���C���[�̏��������s��
void PlayerUpdate();			// �v���C���[�̍X�V
void PlayerDraw();				// �v���C���[�̕`��

Enemy* GetEnemyInstance();		// �G�l�~�[�N���X�̃C���X�^���X���擾����
void EnemySet();				// �G�l�~�[�̏��������s��
void EnemyUpdate();				// �G�l�~�[�̍X�V
void EnemyDraw();				// �G�l�~�[�̕`��

Shot* GetShotInstance(int id);	// �V���b�g�z���vector�C���X�^���X���擾����
void ShotUpdate();				// �V���b�g�̍X�V
void ShotDraw();				// �V���b�g�̕`��
void ShotAdd(double nx, double ny, double nxv, double nyv);		// �V���b�g�̒ǉ�
int GetShotNum();				// �V���b�g�̐���Ԃ�

void AddNumNum();
int GetNumNum();