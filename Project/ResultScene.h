#pragma once
#include "Scene.h"

// リザルトシーン
class ResultScene : public Scene {
private:
	bool flag;	// クリアかどうか

public:
	ResultScene(bool f);
	void Update();	// 更新
	void Draw();	// 描画
};