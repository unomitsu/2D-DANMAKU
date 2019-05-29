#pragma once
#include "Objec.h"
#include "Shot.h"

// �v���C���[�N���X
class Player : public Objec {
private:
	// double x, y;
	// int size;
	// bool flag;
	static int image;	// �摜�n���h��
	int hp;				// �̗�
	
	int shot_num;			// �v���C���[�V���b�g�z��̌��݂̓Y��
	int shot_span;			// �v���C���[�V���b�g�̊Ԋu

public:
	static const int shot_max = 50;	// �v���C���[�V���b�g�z��̗v�f��
	Shot *shot[shot_max];	// �v���C���[�V���b�g�z��

	Player();
	void Update();		// �X�V
	void Draw();		// �`��

	virtual void CollisionResult();	// �����蔻���̏���

	void ShotFire();
};
