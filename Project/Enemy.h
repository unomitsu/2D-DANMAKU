#pragma once
#include "Objec.h"

// �G�l�~�[�N���X
class Enemy : public Objec {
private:
	// int size;
	// bool flag;
	static int image;	// �摜�n���h��

public:
	// double x, y;
	double xv, yv;		// x�����Ay�����̑��x
	int hp_now, hp_max;	// �̗�

	Enemy();
	void Update();	// �X�V
	void Draw();	// �`��
	virtual void CollisionResult();	// �����蔻���̏���

	void SetImage();	// �摜�֘A�̐ݒ�
};