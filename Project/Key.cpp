#include "DxLib.h"
#include "Key.h"

// キー配列の最大値
static const int KEY_NUM = 256;

// キーの入力管理クラス
class KeyReceive {
private:
	char buf[KEY_NUM];	// キーの状態を保持する配列

public:
	// 更新
	void Update() {
		// 全キーの状態を配列に格納する
		GetHitKeyStateAll(buf);
	}
	// 指定したキーの状態を返す
	bool Get(int key_input) {
		if (buf[key_input]) { return true; }
		return false;
	}
};

// 外でインスタンスを持たないでよいように用
KeyReceive Key;

void KeyUpdate() {
	Key.Update();
}

bool GetKey(int key_input) {
	return Key.Get(key_input);
}