#pragma once

#include "Objec.h"
#include "Scene.h"
#include "Player.h"

enum { TITLE_SCENE, STAGE_SCENE, RESULT_SCENE };	// �V�[���̏��

class Info {
public:
	int width, height;		// �E�B���h�E�̉����Əc��
};

void Info_Initialize();	// �e�f�[�^�̏�����
int GetWidth();			// �E�B���h�E�̉����𓾂�
int GetHeight();		// �E�B���h�E�̏c���𓾂�

void Collision(Objec* obj1, Objec* obj2);	// �����蔻��

void SceneUpdate();			// ���݂̃V�[���̍X�V
void SceneDraw();			// ���݂̃V�[���̕`��
void SceneChange(int val);	// �V�[���̕ύX

Player* GetPlayerInstance();
void PlayerSet();
void PlayerUpdate();
void PlayerDraw();
double GetPlayerX();
double GetPlayerY();
bool GetPlayerFlag();