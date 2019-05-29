#include "DxLib.h"
#include "Info.h"
#include "Objec.h"
#include "Scene.h"
#include "TitleScene.h"
#include "StageScene.h"
#include "ResultScene.h"
#include "Player.h"

Info* g_Info = new Info();
Scene* g_Scene = new TitleScene();
Player* g_Player = new Player();

void Info_Initialize() {
	GetScreenState(&g_Info->width, &g_Info->height, NULL);
}

// �E�B���h�E�̉�����Ԃ�
int GetWidth() {
	return g_Info->width;
}
// �E�B���h�E�̏c����Ԃ�
int GetHeight() {
	return g_Info->height;
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
	double distanceR = obj1->GetSize() / 8 + obj2->GetSize() / 2;	// 2�I�u�W�F�N�g�Ԃ̔��a�̘a

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
	case RESULT_SCENE: g_Scene = new ResultScene(); break;
	case TITLE_SCENE:
	default: g_Scene = new TitleScene(); break;
	}
}

Player* GetPlayerInstance() {
	return g_Player;
}
void PlayerSet() {
	g_Player = new Player();
}
void PlayerUpdate() {
	g_Player->Update();
}
void PlayerDraw() {
	g_Player->Draw();
}
double GetPlayerX() {
	return g_Player->GetX();
}
double GetPlayerY() {
	return g_Player->GetY();
}
bool GetPlayerFlag() {
	return g_Player->GetFlag();
}