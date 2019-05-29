#pragma once

# include "Scene.h"

// タイトルシーンクラス
class TitleScene : public Scene {
private:
	int titletextY;

public:
	TitleScene();
	void Update();	// 更新
	void Draw();	// 描画
};