#include "DxLib.h"
#include "Player.h"
#include "Key.h"
#include "Lib.h"


int Player::image;

Player::Player() {
	x = y = 200.0;			// ���W�̏�����
	v = 4;					// ���x�̏�����
	flag = true;			// �����t���O�𗧂Ă�
	hp_now = hp_max = 3;	// �̗͂̐ݒ�

	SetImage();			// �摜�֘A�̐ݒ�
	SetShot();			// �v���C���[�V���b�g�֘A�̐ݒ�
}

void Player::Update() {
	// �ړ��̍X�V
	double val = v;
	if (GetKey(KEY_INPUT_LSHIFT)) { val /= 2; }	// ���V�t�g�������Ă���Ƃ�������
	if (GetKey(KEY_INPUT_UP)) { y -= val; }
	if (GetKey(KEY_INPUT_RIGHT)) { x += val; }
	if (GetKey(KEY_INPUT_DOWN)) { y += val; }
	if (GetKey(KEY_INPUT_LEFT)) { x -= val; }
	
	// �ړ��͈͂̐����A�͈͊O�ɏo�����͔͈͓��ɖ߂�
	if (y < 0) { y = 0; }
	if (GetHeight() < y) { y = GetHeight(); }
	if (GetWidth() < x) { x = GetWidth(); }
	if (x < 0) { x = 0; }

	// Z�L�[�ŃV���b�g��ł�
	ShotFire();

	// �v���C���[�V���b�g�̍X�V
	for (int i = 0; i < shot_max; i++) {
		shot[i]->Update();
	}
}

// �`��
void Player::Draw() {
	DrawFormatString(0, 0, GetColor(255, 255, 255), "HP : %d", hp_now);		// �̗�
	DrawGraph((int)(x - size / 2), (int)(y - size / 2), image, TRUE);		// �v���C���[�̉摜
	DrawCircle((int)x, (int)y, 8, GetColor(200, 100, 100), TRUE, 4);		// �����蔻��̑傫��

	for (int i = 0; i < shot_max; i++) {
		shot[i]->Draw();		// �v���C���[�V���b�g�̕`��
	}
	DrawFormatString(0, 300, GetColor(255, 255, 255), "HP : %d", shot_num);		// �̗�
	DrawFormatString(0, 350, GetColor(255, 255, 255), "HP : %d", shot_max);		// �̗�
}

void Player::CollisionResult() {
	// �̗͂����炷  hp �� 0 �ȉ��ɂȂ����ꍇ�A�����t���O�𗎂Ƃ�
	if (--hp_now <= 0) { flag = false; }
}

// �摜�֘A�̐ݒ�
void Player::SetImage() {
	size = 64;
	hit_size = 8;
	image = LoadGraph("../images/player.png");
}

// �v���C���[�V���b�g�֘A�̐ݒ�
void Player::SetShot() {
	shot_num = 0;			// ���݂̓Y��
	shot_span = 0;			// �V���b�g�̊Ԋu
	for (int i = 0; i < shot_max; i++) {
		shot[i] = new Shot();		// �V���b�g�z��
	}
}
// �v���C���[�V���b�g�̔���
void Player::ShotFire() {
	// Z�L�[�������Ă���Ƃ�
	if (GetKey(KEY_INPUT_Z)) {
		// span �� 4�ȏ�ɂȂ�����
		if (shot_span++ >= 4) {
			// �v���C���[�̈ʒu����e�𔭎˂���
			shot[shot_num]->x = this->x;
			shot[shot_num]->y = this->y;
			shot[shot_num]->yv = -8;
			shot[shot_num++]->Fire();
			
			if (shot_num >= shot_max) { shot_num = 0; }
			shot_span = 0;						// shot_span �̃��Z�b�g
		}
	}
}