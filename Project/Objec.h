#pragma once

// �I�u�W�F�N�g�N���X player, enemy, shot
class Objec {
protected:
	int size;		// �摜�T�C�Y
	int hit_size;	// �����蔻��̑傫��
	bool flag;		// �����t���O
	//static int image;

public:
	double x, y;	// x���W�Ay���W

	virtual void Update() {}	// �X�V
	virtual void Draw() {}		// �`��
	virtual void CollisionResult() {}	// �����蔻���̏���

	double GetX() { return x; }		// �I�u�W�F�N�g��x���W���擾
	double GetY() { return y; }		// �I�u�W�F�N�g��y���W���擾
	int GetSize() { return size; }	// �I�u�W�F�N�g�̉摜�T�C�Y���擾
	int GetHitSize() { return hit_size; }	// �I�u�W�F�N�g�̂����蔻��̑傫�����擾
	bool GetFlag() { return flag; }	// �I�u�W�F�N�g�̐����t���O���擾
};

