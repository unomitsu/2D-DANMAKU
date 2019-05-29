#pragma once

#ifndef DEF_STAGESCENE_H
#define DEF_STAGESCENE_H

#include "Scene.h"
#include "Player.h"
#include "Shot.h"

class StageScene : public Scene {
private:
	// -- éŒ¾‚Æ‰Šú‰»
	Player *player;
	static const int shot_max = 200;
	int shot_num = 0;
	Shot *shot[shot_max];
	int time;

public:
	StageScene();
	void Update();
	void Draw();
};

#endif // !DEF_STAGESCENE_H
