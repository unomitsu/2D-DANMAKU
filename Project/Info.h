#pragma once

#include "Objec.h"

// �V�[���̏��
enum { TITLE_SCENE, STAGE_SCENE, RESULT_SCENE };

void info_initialize();	// �e������
int GetWidth();			// �E�B���h�E�̉����𓾂�
int GetHeight();		// �E�B���h�E�̏c���𓾂�

void Collision(Objec* obj1, Objec* obj2);	// �����蔻��

void SceneUpdate();			// ���݂̃V�[���̍X�V
void SceneDraw();			// ���݂̃V�[���̕`��
void SceneChange(int val);	// �V�[���̕ύX
