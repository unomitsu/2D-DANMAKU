#include "DxLib.h"
#include "Player.h"
#include "Key.h"
#include "Info.h"

int Player::image;

Player::Player() {
	x = 100.0;
	y = 100.0;
	v = 4;
	size = 64;
	flag = true;
	hp = 20;
	image = LoadGraph("../images/player.png");
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
}

// �`��
void Player::Draw() {
	DrawFormatString(0, 0, GetColor(255, 255, 255), "HP : %d", hp);		// �̗�
	DrawGraph((int)(x - size / 2), (int)(y - size / 2), image, TRUE);	// �v���C���[�̉摜
	DrawCircle((int)x, (int)y, 8, GetColor(200, 100, 100), TRUE, 4);	// �����蔻��̑傫��
}

void Player::CollisionResult() {
	// �̗͂����炷  hp �� 0 �ȉ��ɂȂ����ꍇ�A�����t���O�𗎂Ƃ�
	if (--hp <= 0) { flag = false; }
}