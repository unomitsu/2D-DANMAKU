#include "Info.h"
#include "Player.h"
#include <thread>

// �E�B���h�E�̉�����Ԃ�
int GetWidth() {
	return GetInfoInstance()->width;
}
// �E�B���h�E�̏c����Ԃ�
int GetHeight() {
	return GetInfoInstance()->height;
}
// �X�e�[�W���J�n����Ă���̌o�ߎ��Ԃ𓾂�
int GetStageTime() {
	return GetInfoInstance()->stage_time;
}

// �v���C���[�� x���W��Ԃ�
double GetPlayerX() {
	return GetPlayerInstance()->GetX();
}
// �v���C���[�� y���W��Ԃ�
double GetPlayerY() {
	return GetPlayerInstance()->GetY();
}
// �v���C���[�̐����t���O��Ԃ�
bool GetPlayerFlag() {
	return GetPlayerInstance()->GetFlag();
}

// �G�l�~�[��x���W���擾����
double GetEnemyX() {
	return GetEnemyInstance()->GetX();
}
// �G�l�~�[��y���W���擾����
double GetEnemyY() {
	return GetEnemyInstance()->GetY();
}
// �G�l�~�[�̑��x���擾����
double GetEnemyXV() {
	return GetEnemyInstance()->xv;
}
// �G�l�~�[�̑��x���擾����
double GetEnemyYV() {
	return GetEnemyInstance()->xv;
}
// �G�l�~�[�̐����t���O���擾����
bool GetEnemyFlag() {
	return GetEnemyInstance()->GetFlag();
}
// ���݂̗̑͊�����Ԃ�
double GetEnemyHPRate() {
	int enemy_hp_now = GetEnemyInstance()->hp_now;
	int enemy_hp_max = GetEnemyInstance()->hp_max;

	// ���݂̗̑͂� 0 �ȉ��̏ꍇ�A0.0%��Ԃ�
	if (enemy_hp_now <= 0) { return 0.0; }

	// 0 �ȉ��łȂ��ꍇ�́A�v�Z�������ʂ�Ԃ�
	return (double)enemy_hp_now / enemy_hp_max;
}

// �G�l�~�[��x�����̑��x��ݒ肷��
void SetEnemyXV(double nxv) {
	GetEnemyInstance()->xv = nxv;
}
// �G�l�~�[��y�����̑��x��ݒ肷��
void SetEnemyYV(double nyv) {
	GetEnemyInstance()->yv = nyv;
}

// �w����W(x, y)�ɑ��x v �̃V���b�g��ݒu����
void SetShot(double nx, double ny, double nxv, double nyv) {
	// vector�z��֖����ǉ�
	ShotAdd(nx, ny, nxv, nyv);
}

void Loop(double time) {
	std::this_thread::sleep_for(std::chrono::milliseconds((int)(time * 1000)));
}