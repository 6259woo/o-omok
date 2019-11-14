#pragma once

class RunGame
{
public:
	int x; // �ٵ��� ���� ��ġ
	int y;
	int bo[23][23] = {0}; // �ٵ��� ����
	int bo2[23][23] = { 0 }; // �˰��� ����ġ�Ǵ� ����
	int size_x; // ������
	int size_y;
	int playSetX; // �÷��̾��� Ŀ�� ��ġ
	int playSetY;

	char chr[10] = "��";
	char bb[10] = "��";
	char ww[10] = "��";
	char bc[10][10] = { "�� ","�� ","�� ","�� ","�� ","�� ","�� ","�� ","�� ","  " };

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