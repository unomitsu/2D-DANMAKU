#include "DxLib.h"
#include "Enemy.h"
#include "Info.h"
#include "Lib.h"

int Enemy::image;

Enemy::Enemy() {
	x = GetWidth() / 2;		// x���W�̏�����
	y = 50.0;				// y���W�̏�����
	xv = yv = 0.0;			// x�����Ay�����̏�����
	flag = true;			// �����t���O�𗧂Ă�
	hp_max = hp_now = 100;	// ���݂̗̑́A�ő�̗͂̐ݒ�

	this->SetImage();		// �摜�֘A�̐ݒ�
}

void Enemy::Update() {
	// �ړ��ʂ̉��Z
	x += xv;
	y += yv;
}

void Enemy::Draw() {
	// �G�l�~�[�̉摜�̕`��
	DrawGraph((int)(x - size / 2), (int)(y - size / 2), image, TRUE);
	// �G�l�~�[�̗̑͂̕`��
	DrawFormatString(GetWidth()/2, 50, GetColor(255, 255, 255), "ENEMY_HP : %d", hp_now);
}

// �����蔻���̏���
void Enemy::CollisionResult() {
	// �̗͂����炷  hp �� 0 �ȉ��ɂȂ����ꍇ�A�����t���O�𗎂Ƃ�
	if (--hp_now <= 0) { flag = false; }
}

// �摜�֘A�̐ݒ�
void Enemy::SetImage() {
	size = 64;
	hit_size = size / 2;
	image = LoadGraph("../images/enemy.png");
}