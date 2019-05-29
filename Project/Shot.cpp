#include "DxLib.h"
#include "Shot.h"
#include "Info.h"

int Shot::image;

Shot::Shot() {
	x = 100.0;
	y = 0.0;
	v = 1.0;
	size = 16;
	hit_size = size / 2;
	flag = false;
	image = LoadGraph("../images/shot.png");
}

void Shot::Update() {
	// �e���L���Ȏ��̂ݍX�V
	if (flag) {
		y += v;
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

// �w�肵�����W�ix, y�j�ɒe��ݒu���A���x��t���āA�L���ɂ��� 
void Shot::Set(double nx, double ny) {
	x = nx;
	y = ny;
	v = GetRand(50) / 10.0;
	flag = true;
}

// �w�肵�����W�ix, y�j�ɒe��ݒu���A���x��t���āA�L���ɂ��� 
void Shot::Set(double nx, double ny, double nv) {
	x = nx;
	y = ny;
	v = nv;
	flag = true;
}