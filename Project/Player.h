#pragma once
#include "Objec.h"

// �v���C���[�N���X
class Player : public Objec {
private:
	// double x, y;
	// int size;
	// bool flag;
	static int image;	// �摜�n���h��
	int hp;				// �̗�

public:
	Player();
	void Update();		// �X�V
	void Draw();		// �`��
	virtual void CollisionResult();	// �����蔻���̏���
};
