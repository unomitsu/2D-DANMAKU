#pragma once
#include "Objec.h"

// �V���b�g�N���X
class Shot : public Objec {
private:
	// int size;
	// bool flag;
	static int image;	// �摜�n���h��

public:
	// double x, y;
	double xv, yv;		// x�����Ay�����̑��x

	Shot();
	Shot(double nx, double ny, double nxv, double nyv);
	void Update();		// �X�V
	void Draw();		// �`��
	virtual void CollisionResult();	// �����蔻���̏���

	void SetImage();	// �摜�֘A�̏�����
	bool InWindow();	// ��ʔ͈͓��ɑ��݂��邩�ǂ�����Ԃ��B���݂���=TRUE�A���݂��Ȃ�=FALSE

	void Fire();		// �t���O�𗧂ĂĔ��˂���
};

