#pragma once
#include "Objec.h"
#include "Shot.h"

// �v���C���[�N���X
class Player : public Objec {
private:
	// int size;
	// bool flag;
	static int image;		// �摜�n���h��
	
	int shot_num;			// �v���C���[�V���b�g�z��̌��݂̓Y��
	int shot_span;			// �v���C���[�V���b�g�̊Ԋu

public:
	// double x, y;
	double v;							// �ړ����x
	int hp_now, hp_max;		// ���݂̗̑́A�ő�̗̑�

	static const int shot_max = 50;		// �v���C���[�V���b�g�z��̗v�f��
	Shot *shot[shot_max];				// �v���C���[�V���b�g�z��

	Player();
	void Update();		// �X�V
	void Draw();		// �`��
	virtual void CollisionResult();	// �����蔻���̏���

	void SetImage();	// �摜�֘A�̐ݒ�
	void SetShot();		// �v���C���[�V���b�g�̐ݒ�
	void ShotFire();	// �v���C���[�V���b�g�̔���
};
