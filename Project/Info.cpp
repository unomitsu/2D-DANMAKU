#include "DxLib.h"
#include "Info.h"
#include "Objec.h"
#include "Scene.h"
#include "TitleScene.h"
#include "StageScene.h"
#include "ResultScene.h"

// �E�B���h�E�̉����Əc��
int g_Width, g_Height;

// �E�B���h�E�̉����Əc���i��ColorBitDepth�j���擾
void info_initialize() {
	GetScreenState(&g_Width, &g_Height, NULL);
}

// �E�B���h�E�̉�����Ԃ�
int GetWidth() {
	return g_Width;
}
// �E�B���h�E�̏c����Ԃ�
int GetHeight() {
	return g_Height;
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

// �V�[���Ǘ�
Scene* scene = new TitleScene();

// ���݂̃V�[���̍X�V
void SceneUpdate() {
	scene->Update();
}
// ���݂̃V�[���̕`��
void SceneDraw() {
	scene->Draw();
}
// �V�[���̕ύX
void SceneChange(int val) {
	switch (val) {
	case STAGE_SCENE: scene = new StageScene(); break;
	case RESULT_SCENE: scene = new ResultScene(); break;
	case TITLE_SCENE:
	default: scene = new TitleScene(); break;
	}
}
