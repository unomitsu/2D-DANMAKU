#pragma once
#include "Objec.h"

// �G�l�~�[�N���X
class Enemy : public Objec {
private:
	// double x, y, v;
	// int size;
	// bool flag;
	static int image;	// �摜�n���h��
	int hp;				// �̗�
	int span;			// �s���Ԋu

public:
	Enemy();
	void Update();	// �X�V
	void Draw();	// �`��
	virtual void CollisionResult();	// �����蔻���̏���

	void Movement();	// �s�����e
};