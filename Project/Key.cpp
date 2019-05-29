#include "DxLib.h"
#include "Key.h"

// �L�[�z��̍ő�l
static const int KEY_NUM = 256;

// �L�[�̓��͊Ǘ��N���X
class KeyReceive {
private:
	char buf[KEY_NUM];	// �L�[�̏�Ԃ�ێ�����z��

public:
	// �X�V
	void Update() {
		// �S�L�[�̏�Ԃ�z��Ɋi�[����
		GetHitKeyStateAll(buf);
	}
	// �w�肵���L�[�̏�Ԃ�Ԃ�
	bool Get(int key_input) {
		if (buf[key_input]) { return true; }
		return false;
	}
};

// �O�ŃC���X�^���X�������Ȃ��ł悢�悤�ɗp
KeyReceive Key;

void KeyUpdate() {
	Key.Update();
}

bool GetKey(int key_input) {
	return Key.Get(key_input);
}