#include "DxLib.h"
#include "Info.h"
#include "Objec.h"
#include "Scene.h"
#include "TitleScene.h"
#include "StageScene.h"
#include "ResultScene.h"
#include "Player.h"
#include "Enemy.h"
#include "Shot.h"
#include <vector>

Info* g_Info = new Info();			// �f�[�^�ێ�
Scene* g_Scene = new TitleScene();	// �V�[���Ǘ�
Player* g_Player = new Player();	// �v���C���[
Enemy* g_Enemy = new Enemy();		// �G�l�~�[
std::vector<Shot> g_Shot(0);			// �V���b�g�z��

// Info�N���X�̏�����
void Info::Initialize() {
	GetScreenState(&width, &height, NULL);
	stage_time = 0;
}
// Info�N���X�̍X�V
void Info::Update() {
	stage_time++;	// �o�ߎ��Ԃ̉��Z
}

// Info�N���X�̃C���X�^���X��Ԃ�
Info* GetInfoInstance() {
	return g_Info;
}
// �e�f�[�^�̏�����
void Info_Initialize() {
	g_Info->Initialize();
}
// �e�f�[�^�̍X�V
void Info_Update() {
	g_Info->Update();
}

// 2���Ԃ�
double pow(double x) {
	return x * x;
}

// �����蔻��
void Collision(Objec* obj1, Objec* obj2) {
	// �������L���ł��邩�̊m�F
	if (!(obj1->GetFlag() && obj2->GetFlag())) { return; }

	// �����蔻��̌v�Z�A�O�����̒藝
	double distanceX = obj1->GetX() - obj2->GetX();		// 2�I�u�W�F�N�g�Ԃ�x���W�̍�
	double distanceY = obj1->GetY() - obj2->GetY();		// 2�I�u�W�F�N�g�Ԃ�y���W�̍�
	double distanceR = obj1->GetHitSize() + obj2->GetHitSize();	// 2�I�u�W�F�N�g�Ԃ̔��a�̘a

	// 2�I�u�W�F�N�g���Փ˂����Ƃ�
	if (pow(distanceX) + pow(distanceY) < pow(distanceR)) {
		// �e�I�u�W�F�N�g�̂����蔻���̏���������
		obj1->CollisionResult();
		obj2->CollisionResult();
	}
}

// ���݂̃V�[���̍X�V
void SceneUpdate() {
	g_Scene->Update();
}
// ���݂̃V�[���̕`��
void SceneDraw() {
	g_Scene->Draw();
}
// �V�[���̕ύX
void SceneChange(int val) {
	switch (val) {
	case STAGE_SCENE: g_Scene = new StageScene(); break;
	case RESULT_SCENE_CLEAR: g_Scene = new ResultScene(TRUE); break;
	case RESULT_SCENE_MISS: g_Scene = new ResultScene(FALSE); break;
	case TITLE_SCENE:
	default: g_Scene = new TitleScene(); break;
	}
}

// �v���C���[�̃C���X�^���X��Ԃ�
Player* GetPlayerInstance() {
	return g_Player;
}
// �v���C���[�̏��������s��
void PlayerSet() {
	g_Player = new Player();
}
// �v���C���[�̍X�V
void PlayerUpdate() {
	g_Player->Update();
}
// �v���C���[�̕`��
void PlayerDraw() {
	g_Player->Draw();
}

// �G�l�~�[�N���X�̃C���X�^���X���擾����
Enemy* GetEnemyInstance() {
	return g_Enemy;
}
// �G�l�~�[�̏��������s��
void EnemySet() {
	g_Enemy = new Enemy();
}

// �G�l�~�[�̍X�V
void EnemyUpdate() {
	g_Enemy->Update();
}
// �G�l�~�[�̕`��
void EnemyDraw() {
	g_Enemy->Draw();
}

// �V���b�g�z���vector�C���X�^���X���擾����
Shot* GetShotInstance(int id) {
	return &g_Shot.at(id);
}
// �V���b�g�̍X�V
void ShotUpdate() {
	for (auto i = g_Shot.begin(); i != g_Shot.end(); ++i) {
		i->Update();	// �X�V

		// �L���łȂ��Ȃ����A�������͔͈͊O�ɏo���ꍇ�A���̃f�[�^���폜����
		// �폜����ƁA�S�f�[�^���O�ɂ��炳��邽�߁A�C���N�������g�����s���Ȃ�
		if (! i->GetFlag() || i->InWindow()) {
			g_Shot.erase(i);
			continue;
		}
	}
}
// �V���b�g�̕`��
void ShotDraw() {
	for (auto i = g_Shot.begin(); i != g_Shot.end(); ++i) {
		i->Draw();
	}
}
// �V���b�g�̒ǉ�
void ShotAdd(Shot shot) {
	g_Shot.push_back(shot);
}
// �V���b�g�̒ǉ�
int GetShotNum() {
	return static_cast<int>(g_Shot.size());
}

int g_NumNum = 0;
void AddNumNum() {
	g_NumNum++;
}
int GetNumNum() {
	return g_NumNum;
}