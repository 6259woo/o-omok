#pragma once
#include "RunGame.h"
class MainScene
{
public:
	int stX = 3; // 시작위치
	int stY = 2;
	int ord = 1; // 공겨 순서
	RunGame flow;

	MainScene();
	~MainScene();

	void beginScreen();
	void selectFirst();
};

