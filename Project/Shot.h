#pragma once
#include "Objec.h"

// �V���b�g�N���X
class Shot : public Objec {
private:
	// double x, y, v;
	// int size;
	// bool flag;
	static int image;	// �摜�n���h��

public:
	Shot();
	void Update();		// �X�V
	void Draw();		// �`��
	virtual void CollisionResult();	// �����蔻���̏���

	void Set(double nx, double ny);	// �w����W�ɃV���b�g���Z�b�g����
};

