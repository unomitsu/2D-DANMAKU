#pragma once

#include "Scene.h"
#include "Player.h"
#include "Shot.h"
#include "Enemy.h"
#include <thread>


// ステージシーンクラス
class StageScene : public Scene {
private:
	std::thread th_stage;

public:
	StageScene();
	void Update();	// 更新
	void Draw();	// 描画
};

