#include "DxLib.h"
#include "Key.h"

static const int KEY_NUM = 256;

class KeyReceive {
private:
	char buf[KEY_NUM];

public:
	void Update() {
		GetHitKeyStateAll(buf);
	}
	bool Get(int key_input) {
		if (buf[key_input]) { return true; }
		return false;
	}
};

KeyReceive Key;

void KeyUpdate() {
	Key.Update();
}

bool GetKey(int key_input) {
	return Key.Get(key_input);
}