#pragma once

int GetWidth();			// �E�B���h�E�̉����𓾂�
int GetHeight();		// �E�B���h�E�̏c���𓾂�
int GetStageTime();		// �X�e�[�W���J�n����Ă���̌o�ߎ��Ԃ𓾂�

double GetPlayerX();	// �v���C���[��x���W���擾����
double GetPlayerY();	// �v���C���[��y���W���擾����
bool GetPlayerFlag();	// �v���C���[�̐����t���O���擾����

double GetEnemyX();		// �G�l�~�[��x���W���擾����
double GetEnemyY();		// �G�l�~�[��y���W���擾����
double GetEnemyXV();	// �G�l�~�[��x�����̑��x���擾����
double GetEnemyYV();	// �G�l�~�[��y�����̑��x���擾����
bool GetEnemyFlag();	// �G�l�~�[�̐����t���O���擾����
double GetEnemyHPRate();	// ���݂̗̑͊�����Ԃ�

void SetEnemyXV(double nxv);	// �G�l�~�[��x�����̑��x��ݒ肷��
void SetEnemyYV(double nyv);	// �G�l�~�[��y�����̑��x��ݒ肷��

void SetShot(double nx, double ny, double nxv, double nyv);	// �w����W(nx, ny)�ɑ��x (nxv, nyv) �̃V���b�g��ݒu����

void Loop(double time);