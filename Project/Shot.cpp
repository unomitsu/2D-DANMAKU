#include "DxLib.h"
#include "Shot.h"
#include "Info.h"
#include "Lib.h"

int Shot::image = -1;

Shot::Shot() {
	x = y = 100.0;		// ���W�̏�����
	xv = yv = 0.0;		// ���x�̏�����
	flag = false;		// �L���t���O�𗎂Ƃ�
	SetImage();			// �摜�֘A�̏�����
}
Shot::Shot(double nx, double ny, double nxv, double nyv) {
	x = nx;
	y = ny;
	xv = nxv;
	yv = nyv;
	flag = true;
	SetImage();
}

void Shot::Update() {
	// �e���L���Ȏ��̂ݍX�V
	if (flag) {
		x += xv;
		y += yv;
	}
}

void Shot::Draw() {
	// �e���L���Ȏ��̂ݕ`��
	if (flag) {
		DrawGraph((int)(x - size / 2), (int)(y - size / 2), image, TRUE);
	}
}

// �����蔻���̏���
void Shot::CollisionResult() {
	// �����ɂ��������ꍇ�A�t���O�𗎂Ƃ�
	flag = false;
}

// �摜�֘A�̏�����
void Shot::SetImage() {
	size = 16;
	hit_size = size / 2;
	if (image == -1) {
		image = LoadGraph("../images/shot.png");
	}
}

// �t���O�𗧂ĂĔ��˂���
void Shot::Fire() {
	flag = true;
}

// ��ʔ͈͓��ɑ��݂��邩�ǂ�����Ԃ��B���݂���=TRUE�A���݂��Ȃ�=FALSE
bool Shot::InWindow() {
	if (x < 0 || GetWidth() < x || y < 0 || GetHeight() < y) {
		return false;
	}
	return true;
}
