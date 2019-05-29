#include "DxLib.h"
#include "Enemy.h"
#include "Info.h"

int Enemy::image;

Enemy::Enemy() {
	x = 100.0;
	y = 50.0;
	v = 4.0;
	size = 64;
	flag = true;
	hp = 100;
	image = LoadGraph("../images/enemy.png");
	span = 0;
}

void Enemy::Update() {
	Movement();	// �s�����e
}

void Enemy::Draw() {
	// �G�l�~�[�̉摜�̕`��
	DrawGraph((int)(x - size / 2), (int)(y - size / 2), image, TRUE);
	// �G�l�~�[�̗̑͂̕`��
	DrawFormatString(GetWidth()/2, 50, GetColor(255, 255, 255), "ENEMY_HP : %d", hp);
}

// �����蔻���̏���
void Enemy::CollisionResult() {
	// �̗͂����炷  hp �� 0 �ȉ��ɂȂ����ꍇ�A�����t���O�𗎂Ƃ�
	if (--hp <= 0) { flag = false; }
}

void Enemy::Movement() {
	//�@�����Ȃ�
	if (++span < 0) {
		return;
	}
	// span �� 0 �ɂȂ������A�����l��ݒ肷��
	if (span++ == 0) {
		//�@�v���C���[��荶�ɂ���Ƃ��E�ɓ���(x�͑���)
		if (x < GetPlayerX()) {
			v = v > 0 ? v : -v;
		}
		//�@�v���C���[���E�ɂ���Ƃ����ɓ���(x�͌���)
		if (GetPlayerX() < x) {
			v = v > 0 ? -v : v;
		}
		return;
	}
	// span �� 40 �ɂȂ�܂œ���
	if (span <= 40) {
		x += v;
	}
	// 20 �𒴂���� span �����Z�b�g
	else {
		span = -60;
	}

}