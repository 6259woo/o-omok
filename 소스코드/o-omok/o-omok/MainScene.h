#pragma once
#include "RunGame.h"
class MainScene
{
public:
	int stX = 3; // ������ġ
	int stY = 2;
	int ord = 1; // ���� ����
	RunGame flow;

	MainScene();
	~MainScene();

	void beginScreen();
	void selectFirst();
};

