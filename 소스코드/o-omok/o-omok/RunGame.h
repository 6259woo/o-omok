#pragma once

class RunGame
{
public:
	int x; // 바둑판 시작 위치
	int y;
	int bo[23][23] = {0}; // 바둑판 상태
	int bo2[23][23] = { 0 }; // 알고리즘 가중치판단 상태
	int size_x; // 사이즈
	int size_y;
	int playSetX; // 플레이어의 커서 위치
	int playSetY;

	char chr[10] = "▣";
	char bb[10] = "○";
	char ww[10] = "●";
	char bc[10][10] = { "┌ ","┬ ","┐ ","├ ","┼ ","┤ ","└ ","┴ ","┘ ","  " };

	RunGame();

	void printCheckerboard();
	void PlayGame(int &ord);
	void player(char chr[10], int _y, int _x);
	void erase(int _y, int _x);
	void human(int ord = 1);
	void automaton_v1(int ord);
	void endCheck(int ord);
	void win(int ord);
	bool firstCheck();
	int rangeRand(int rMax);
	void ch1(int ord);
	void ch2(int ord);
	int ch2_2(int ord, int y2, int x2, int ang);
};