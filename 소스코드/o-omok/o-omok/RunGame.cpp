#include "RunGame.h"
#include "ConsoleFunctions.h"
#include <cstdlib>
#include <ctime>
#include <stdio.h>

RunGame::RunGame()
{
	x = 5;
	y = 2;
	size_x = 19;
	size_y = 19;
	playSetX = 0;
	playSetY = 0;
}

void RunGame::printCheckerboard()
{
	system("cls");

	gotoxy(x, y);
	std::cout << bc[0];
	for (int i = 0; i < size_x - 2; i++)
	{
		std::cout << bc[1];
	}
	std::cout << bc[2];

	for (int i = 0; i < size_y - 2; i++)
	{
		gotoxy(x, y + i + 1);
		std::cout << bc[3];
		for (int j = 0; j < size_x - 2; j++)
		{
			std::cout << bc[4];
		}
		std::cout << bc[5];
	}

	gotoxy(x, y + 18);
	std::cout << bc[6];
	for (int i = 0; i < size_x - 2; i++)
	{
		std::cout << bc[7];
	}
	std::cout << bc[8];

	gotoxy(x + 44, y + 1);
	std::cout << "[w,a,s,d]Ű�� �����ϼ� �ֽ��ϴ�.";
	gotoxy(x + 44, y + 3);
	std::cout << "[����]Ű�� �����Ҽ� �ֽ��ϴ�.";
	gotoxy(x + 44, y + 5);
	std::cout << "<��� ���>";
	gotoxy(x + 44, y + 7);
	std::cout << "1. �¸�";
	gotoxy(x + 44, y + 8);
	std::cout << "2. �й�";
	gotoxy(x + 44, y + 9);
	std::cout << "3. ���º� (���� ��ƽ��ϴ�.)";
	gotoxy(x + 44, y + 11);
	std::cout << "[�ѹ��� ���ºο� ������ ���°� ����?]";

	gotoxy(x, y + 20);
	std::cout << "        ___                             ___           ___           ___           ___     ";
	gotoxy(x, y + 21);
	std::cout << "       /\\  \\                           /\\  \\         /\\__\\         /\\  \\         /\\__\\  ";
	gotoxy(x, y + 22);
	std::cout << "      /::\\  \\                         /::\\  \\       /::|  |       /::\\  \\       /:/  /   ";
	gotoxy(x, y + 23);
	std::cout << "     /:/\\:\\  \\                       /:/\\:\\  \\     /:|:|  |      /:/\\:\\  \\     /:/__/     ";
	gotoxy(x, y + 24);
	std::cout << "    /:/  \\:\\  \\                     /:/  \\:\\  \\   /:/|:|__|__   /:/  \\:\\  \\   /::\\__\\____ ";
	gotoxy(x, y + 25);
	std::cout << "   /:/__/ \\:\\__\\                   /:/__/ \\:\\__\\ /:/ |::::\\__\\ /:/__/ \\:\\__\\ /:/\\:::::\\__\\ ";
	gotoxy(x, y + 26);
	std::cout << "   \\:\\  \\ /:/  /                   \\:\\  \\ /:/  / \\/__/~~/:/  / \\:\\  \\ /:/  / \\/_|:|~~|~   ";
	gotoxy(x, y + 27);
	std::cout << "    \\:\\  /:/  /                     \\:\\  /:/  /        /:/  /   \\:\\  /:/  /     |:|  |    ";
	gotoxy(x, y + 28);
	std::cout << "     \\:\\/:/  /                       \\:\\/:/  /        /:/  /     \\:\\/:/  /      |:|  |    ";
	gotoxy(x, y + 29);
	std::cout << "      \\::/  /                         \\::/  /        /:/  /       \\::/  /       |:|  |    ";
	gotoxy(x, y + 30);
	std::cout << "       \\/__/                           \\/__/         \\/__/         \\/__/         \\|__|    ";
}

void RunGame::player(char chr[10], int _y, int _x) {
	gotoxy(x + _x * 2, y + _y);
	std::cout << chr; // ��
}

void RunGame::erase(int _y, int _x) {
	int eraX, eraY;
	eraX = playSetX + _x;
	eraY = playSetY + _y;

	if (bo[eraY + 2][eraX + 2] == 0) {
		if (eraX == 0 && eraY == 0) player(bc[0], eraY, eraX); // ������ Ȯ��
		else if (eraX == 18 && eraY == 0) player(bc[2], eraY, eraX);
		else if (eraX == 0 && eraY == 18) player(bc[6], eraY, eraX);
		else if (eraX == 18 && eraY == 18) player(bc[8], eraY, eraX);
		else if (eraY == 0) player(bc[1], eraY, eraX); // �𼭸� Ȯ��
		else if (eraX == 18) player(bc[5], eraY, eraX);
		else if (eraY == 18) player(bc[7], eraY, eraX);
		else if (eraX == 0) player(bc[3], eraY, eraX);
		else if (eraX >= 0 && eraY >= 0 && eraX <= 18 && eraY <= 18) player(bc[4], eraY, eraX);// �߾� ����
		else player(bc[9], eraY, eraX); // ����
	}
	else if (bo[eraY + 2][eraX + 2] == -1) {
		player(ww, eraY, eraX);
	}
	else if (bo[eraY + 2][eraX + 2] == 1) {
		player(bb, eraY, eraX);
	}
}

void RunGame::human(int ord)
{
	while (true)
	{
		player(chr, playSetY, playSetX);

		if (_kbhit())
		{
			char key = _getch();
			if (key == 'a')
			{
				erase(0, 0);
				if (playSetX > 0) playSetX -= 1;
			}
			else if (key == 's')
			{
				erase(0, 0);
				if (playSetY < 18) playSetY += 1;
			}
			else if (key == 'd')
			{
				erase(0, 0);
				if (playSetX < 18) playSetX += 1;
			}
			else if (key == 'w')
			{
				erase(0, 0);
				if (playSetY > 0)  playSetY -= 1;
			}
			else if (key == 13)
			{
				if (bo[playSetY + 2][playSetX + 2] == 0)
				{
					erase(0, 0);
					player(bb, playSetY, playSetX);
					bo[playSetY + 2][playSetX + 2] = ord;
					//ord *= -1;
					break;
				}
			}
		}
	}
}

void RunGame::automaton_v1(int ord)
{
	if (firstCheck())
	{
		/*Sleep(3000);
		std::cout << "yes";*/
		
		playSetX = rangeRand(5) + 7;
		playSetY = rangeRand(5) + 7;
		player(ww, playSetY, playSetX);
		bo[playSetY + 2][playSetX + 2] = ord;
	}
	else
	{
		//Sleep(1000);
		for (int i = 0; i < 19; i++)
		{
			for (int j = 0; j < 19; j++)
			{
				bo2[i + 2][j + 2] = 0;
			}
		}

		ch1(ord);
		ch1(ord * -1);
		//ch2(ord); // �� ���� ��
		ch2(ord * -1);
		
		for (int i = 0; i < 19; i++)
		{
			for (int j = 0; j < 19; j++)
			{
				if (bo[i + 2][j + 2] != 0) {
					bo2[i + 2][j + 2] = 0;
				}
			}
		}
		int bo2Max = bo2[2][2];
		int bo2cont = 0;
		for (int i = 0; i < 19; i++)
		{
			for (int j = 0; j < 19; j++)
			{
				if (bo2[i + 2][j + 2] == bo2Max) {
					bo2cont++;
				}
				else if (bo2[i + 2][j + 2] > bo2Max)
				{
					bo2Max = bo2[i + 2][j + 2];
					bo2cont = 1;
				}
			}
		}

		int num = rangeRand(bo2cont) + 1;
		int num2 = num;
		for (int i = 0; i < 19; i++)
		{
			for (int j = 0; j < 19; j++)
			{
				if (bo2[i + 2][j + 2] == bo2Max)
				{
					num--;
					if (num == 0) {
						player(ww, i, j);
						bo[i + 2][j + 2] = ord;
					}
				}
			}
		}

		/*gotoxy(x + 44, y + 20);
		std::cout << "bo2Max = " << bo2Max;
		gotoxy(x + 44, y + 21);
		std::cout << "bo2cont = " << bo2cont;
		gotoxy(x + 44, y + 22);
		std::cout << "num = " << num;
		gotoxy(x + 44, y + 23);
		std::cout << "num2 = " << num2;*/
	}
}



void RunGame::endCheck(int ord)
{
	//
	/*win(1);
	return;*/
	//
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (bo[i + 2][j + 2] == ord) {
				if ((bo[i + 2][j + 0] == bo[i + 2][j + 1]) && (bo[i + 2][j + 3] == bo[i + 2][j + 4]) && (bo[i + 2][j + 1] == ord) && (bo[i + 2][j + 3] == ord))
				{
					win(ord);
					return;
				}
				if ((bo[i + 0][j + 0] == bo[i + 1][j + 1]) && (bo[i + 3][j + 3] == bo[i + 4][j + 4]) && (bo[i + 1][j + 1] == ord) && (bo[i + 3][j + 3] == ord))
				{
					win(ord);
					return;
				}
				if ((bo[i + 0][j + 2] == bo[i + 1][j + 2]) && (bo[i + 3][j + 2] == bo[i + 4][j + 2]) && (bo[i + 1][j + 2] == ord) && (bo[i + 3][j + 2] == ord))
				{
					win(ord);
					return;
				}
				if ((bo[i + 0][j + 4] == bo[i + 1][j + 3]) && (bo[i + 3][j + 1] == bo[i + 4][j + 0]) && (bo[i + 1][j + 3] == ord) && (bo[i + 3][j + 1] == ord))
				{
					win(ord);
					return;
				}
			}
		}
	}
	int draw = 0;
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (bo[i + 2][j + 2] == 0) {
				draw = 1;
			}
		}
	}
	if (draw == 0) win(draw);
}

void RunGame::win(int ord)
{
	for (int i = 0; i < 11; i++)
	{
		gotoxy(x, y + 20 + i);
		std::cout << "                                                                                                    ";
	}
	//                 __                                         
	//                /  |                                        
	//   __   __   __ $$/  _______   _______    ______    ______  
	//  /  | /  | /  |/  |/       \ /       \  /      \  /      \ 
	//  $$ | $$ | $$ |$$ |$$$$$$$  |$$$$$$$  |/$$$$$$  |/$$$$$$  |
	//  $$ | $$ | $$ |$$ |$$ |  $$ |$$ |  $$ |$$    $$ |$$ |  $$/ 
	//  $$ \_$$ \_$$ |$$ |$$ |  $$ |$$ |  $$ |$$$$$$$$/ $$ |      
	//  $$   $$   $$/ $$ |$$ |  $$ |$$ |  $$ |$$       |$$ |      
	//   $$$$$/$$$$/  $$/ $$/   $$/ $$/   $$/  $$$$$$$/ $$/       
	//                                                            

	if (ord > 0)
	{
		//std::cout << "�¸�: �����մϴ�.";
		gotoxy(x, y + 20);
		std::cout << "                 __                                         ";
		gotoxy(x, y + 21);
		std::cout << "                /  |                                        ";
		gotoxy(x, y + 22);
		std::cout << "   __   __   __ $$/  _______   _______    ______    ______  ";
		gotoxy(x, y + 23);
		std::cout << "  /  | /  | /  |/  |/       \ /       \  /      \  /      \ ";
		gotoxy(x, y + 24);
		std::cout << "  $$ | $$ | $$ |$$ |$$$$$$$  |$$$$$$$  |/$$$$$$  |/$$$$$$  |";
		gotoxy(x, y + 25);
		std::cout << "  $$ | $$ | $$ |$$ |$$ |  $$ |$$ |  $$ |$$    $$ |$$ |  $$/ ";
		gotoxy(x, y + 26);
		std::cout << "  $$ \\_$$ \\_$$ |$$ |$$ |  $$ |$$ |  $$ |$$$$$$$$/ $$ |      ";
		gotoxy(x, y + 27);
		std::cout << "  $$   $$   $$/ $$ |$$ |  $$ |$$ |  $$ |$$       |$$ |      ";
		gotoxy(x, y + 28);
		std::cout << "   $$$$$/$$$$/  $$/ $$/   $$/ $$/   $$/  $$$$$$$/ $$/       ";
		gotoxy(x, y + 29);
		std::cout << "                                                            ";

		gotoxy(x + 44, y + 13);
		std::cout << "��������������������������������������������������������������������";
		gotoxy(x + 44, y + 14);
		std::cout << "���� ���ϵ帳�ϴ�.                ����";
		gotoxy(x + 44, y + 15);
		std::cout << "����                              ����";
		gotoxy(x + 44, y + 16);
		std::cout << "���� �¸� �ϼ̽��ϴ�.             ����";
		gotoxy(x + 44, y + 17);
		std::cout << "��������������������������������������������������������������������";
		gotoxy(x, y + 30);
	}
	else if (ord < 0)
	{
		//std::cout << "�й�: �ٽ� ������ ������.";
		//   __                                         
		//  /  |                                        
		//  $$ |  ______    _______   ______    ______  
		//  $$ | /      \  /       | /      \  /      \ 
		//  $$ |/$$$$$$  |/$$$$$$$/ /$$$$$$  |/$$$$$$  |
		//  $$ |$$ |  $$ |$$      \ $$    $$ |$$ |  $$/ 
		//  $$ |$$ \__$$ | $$$$$$  |$$$$$$$$/ $$ |      
		//  $$ |$$    $$/ /     $$/ $$       |$$ |      
		//  $$/  $$$$$$/  $$$$$$$/   $$$$$$$/ $$/       
		//                                              
		gotoxy(x, y + 20);
		std::cout << "   __                                         ";
		gotoxy(x, y + 21);
		std::cout << "  /  |                                        ";
		gotoxy(x, y + 22);
		std::cout << "  $$ |  ______    _______   ______    ______  ";
		gotoxy(x, y + 23);
		std::cout << "  $$ | /      \\  /       | /      \\  /      \\ ";
		gotoxy(x, y + 24);
		std::cout << "  $$ |/$$$$$$  |/$$$$$$$/ /$$$$$$  |/$$$$$$  |";
		gotoxy(x, y + 25);
		std::cout << "  $$ |$$ |  $$ |$$      \\ $$    $$ |$$ |  $$/ ";
		gotoxy(x, y + 26);
		std::cout << "  $$ |$$ \\__$$ | $$$$$$  |$$$$$$$$/ $$ |      ";
		gotoxy(x, y + 27);
		std::cout << "  $$ |$$    $$/ /     $$/ $$       |$$ |      ";
		gotoxy(x, y + 28);
		std::cout << "  $$/  $$$$$$/  $$$$$$$/   $$$$$$$/ $$/       ";
		gotoxy(x, y + 29);
		std::cout << "                                              ";

		gotoxy(x + 44, y + 13);
		std::cout << "��������������������������������������������������������������������";
		gotoxy(x + 44, y + 14);
		std::cout << "���� �ٽ� ������ ������.          ����";
		gotoxy(x + 44, y + 15);
		std::cout << "����                              ����";
		gotoxy(x + 44, y + 16);
		std::cout << "���� �й� �ϼ̽��ϴ�.             ����";
		gotoxy(x + 44, y + 17);
		std::cout << "��������������������������������������������������������������������";
		gotoxy(x, y + 30);
	}
	else if (ord == 0)
	{
		//std::cout << "���ºζ�� ����ϱ���.";
		// 1   __       __   ______   __       __  __                                                  __     
		// 2  /  |  _  /  | /      \\ /  |  _  /  |/  |                                                /  |    
		// 3  $$ | / \\ $$ |/$$$$$$  |$$ | / \\ $$ |$$ |        ______    ______    ______    ______   _$$ |_   
		// 4  $$ |/$  \\$$ |$$ |  $$ |$$ |/$  \\$$ |$$ |       /      \\  /      \\  /      \\  /      \\ / $$   |  
		// 5  $$ /$$$  $$ |$$ |  $$ |$$ /$$$  $$ |$$ |      /$$$$$$  |/$$$$$$  |/$$$$$$  | $$$$$$  |$$$$$$/   
		// 6  $$ $$/$$ $$ |$$ |  $$ |$$ $$/$$ $$ |$$/       $$ |  $$ |$$ |  $$/ $$    $$ | /    $$ |  $$ | __ 
		// 7  $$$$/  $$$$ |$$ \\__$$ |$$$$/  $$$$ | __       $$ \\__$$ |$$ |      $$$$$$$$/ /$$$$$$$ |  $$ |/  |
		// 8  $$$/    $$$ |$$    $$/ $$$/    $$$ |/  |      $$    $$ |$$ |      $$       |$$    $$ |  $$  $$/ 
		// 9  $$/      $$/  $$$$$$/  $$/      $$/ $$/        $$$$$$$ |$$/        $$$$$$$/  $$$$$$$/    $$$$/  
		//10                                                /  \\__$$ |                                        
		//11                                                $$    $$/                                         
		//13                                                 $$$$$$/                                          
		gotoxy(x, y + 20);
		std::cout << " __       __   ______   __       __  __                                                  __     ";
		gotoxy(x, y + 21);
		std::cout << "/  |  _  /  | /      \ /  |  _  /  |/  |                                                /  |    ";
		gotoxy(x, y + 22);
		std::cout << "$$ | / \\ $$ |/$$$$$$  |$$ | / \\ $$ |$$ |        ______    ______    ______    ______   _$$ |_   ";
		gotoxy(x, y + 23);
		std::cout << "$$ |/$  \\$$ |$$ |  $$ |$$ |/$  \\$$ |$$ |       /      \\  /      \\  /      \\  /      \\ / $$   |  ";
		gotoxy(x, y + 24);
		std::cout << "$$ /$$$  $$ |$$ |  $$ |$$ /$$$  $$ |$$ |      /$$$$$$  |/$$$$$$  |/$$$$$$  | $$$$$$  |$$$$$$/   ";
		gotoxy(x, y + 25);
		std::cout << "$$ $$/$$ $$ |$$ |  $$ |$$ $$/$$ $$ |$$/       $$ |  $$ |$$ |  $$/ $$    $$ | /    $$ |  $$ | __ ";
		gotoxy(x, y + 26);
		std::cout << "$$$$/  $$$$ |$$ \\__$$ |$$$$/  $$$$ | __       $$ \\__$$ |$$ |      $$$$$$$$/ /$$$$$$$ |  $$ |/  |";
		gotoxy(x, y + 27);
		std::cout << "$$$/    $$$ |$$    $$/ $$$/    $$$ |/  |      $$    $$ |$$ |      $$       |$$    $$ |  $$  $$/ ";
		gotoxy(x, y + 28);
		std::cout << "$$/      $$/  $$$$$$/  $$/      $$/ $$/        $$$$$$$ |$$/        $$$$$$$/  $$$$$$$/    $$$$/  ";
		gotoxy(x, y + 29);
		std::cout << "                                              /  \\__$$ |                                        ";
		gotoxy(x, y + 30);
		std::cout << "                                              $$    $$/                                         ";
		gotoxy(x, y + 31);
		std::cout << "                                               $$$$$$/                                          ";

		gotoxy(x + 44, y + 13);
		std::cout << "��������������������������������������������������������������������";
		gotoxy(x + 44, y + 14);
		std::cout << "���� ���ºζ��... ��...          ����";
		gotoxy(x + 44, y + 15);
		std::cout << "����                              ����";
		gotoxy(x + 44, y + 16);
		std::cout << "���� ����ϱ���!! (>_<)           ����";
		gotoxy(x + 44, y + 17);
		std::cout << "��������������������������������������������������������������������";
		gotoxy(x, y + 32);
	}
	Sleep(1000);
	std::cout << ">> �� â�� �������� �ƹ� Ű�� ��������.";
	while (true)
	{
		if (_kbhit()) break;
	}
	exit(0);
}

bool RunGame::firstCheck()
{
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (bo[i + 2][j + 2] != 0) {
				return false;
			}
		}
	}
	return true;
}

int RunGame::rangeRand(int rMax)
{
	srand((unsigned int)time(NULL));
	int num = rand();
	return (int)num % rMax;
}

void RunGame::ch1(int ord)
{
	int nonord = ord * -1;
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (bo[i + 2][j + 2] == ord) {
				bo2[i + 1][j + 1] += ord;
				bo2[i + 1][j + 2] += ord;
				bo2[i + 1][j + 3] += ord;
				bo2[i + 2][j + 3] += ord;
				bo2[i + 3][j + 3] += ord;
				bo2[i + 3][j + 2] += ord;
				bo2[i + 3][j + 1] += ord;
				bo2[i + 2][j + 1] += ord;
			}
		}
	}
}

void RunGame::ch2(int ord)
{
	int nonord = ord * -1;
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			bo2[i + 2][j + 2] += (ch2_2(ord, i, j, 0) + ch2_2(ord, i, j, 1) + ch2_2(ord, i, j, 2) + ch2_2(ord, i, j, 3) + ch2_2(ord, i, j, 4) + ch2_2(ord, i, j, 5) + ch2_2(ord, i, j, 6) + ch2_2(ord, i, j, 7)) * 6;
			//std::cout << ch2_2(ord, i, j, 0) << " ";
		}
	}
}
//0,0 [ ] 0,2 [ ] 0,4
//[ ] 1,1 1,2 1,3 [ ]
//2,0 2,1 [ ] 2,3 2,4
//[ ] 3,1 3,2 3,3 [ ]
//4,0 [ ] 4,2 [ ] 4,4
int RunGame::ch2_2(int ord, int y2, int x2, int ang)
{
	if (ang == 0) {
		if (bo[y2 + 0][x2 + 0] == ord && bo[y2 + 1][x2 + 1] == ord)
		{ 
			return 1; 
		}
		else
		{
			return 0;
		}
	}
	else if (ang == 1) {
		if (bo[y2 + 0][x2 + 2] == ord && bo[y2 + 1][x2 + 2] == ord)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if (ang == 2) {
		if (bo[y2 + 0][x2 + 4] == ord && bo[y2 + 1][x2 + 3] == ord)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if (ang == 3) {
		if (bo[y2 + 2][x2 + 4] == ord && bo[y2 + 2][x2 + 3] == ord)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if (ang == 4) {
		if (bo[y2 + 4][x2 + 4] == ord && bo[y2 + 3][x2 + 3] == ord)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if (ang == 5) {
		if (bo[y2 + 4][x2 + 2] == ord && bo[y2 + 3][x2 + 2] == ord)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if (ang == 6) {
		if (bo[y2 + 4][x2 + 0] == ord && bo[y2 + 3][x2 + 1] == ord)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if (ang == 7) {
		if (bo[y2 + 2][x2 + 0] == ord && bo[y2 + 2][x2 + 1] == ord)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}

void RunGame::PlayGame(int& ord)
{

	while (true)
	{
		if (ord > 0) {
			human(ord);
		}
		else if (ord < 0) {
			automaton_v1(ord);
			//human(ord); // [��� vs ��� (�÷��̾�2)]
		}

		endCheck(ord); // ���� üũ

		ord *= -1; // ���� �ٲ�

		//----[���� �׽�Ʈ ���]
		/*gotoxy(x + 44, y + 1);
		for (int i = 0; i < 19; i++)
		{
			gotoxy(x + 44, y + i);
			for (int j = 0; j < 19; j++)
			{
				if(bo[i + 2][j + 2] < 0) std::cout << bo[i + 2][j + 2];
				else if (bo[i + 2][j + 2] >= 0) std::cout << " " << bo[i + 2][j + 2];
			}
		}*/
		//----
		//----[automaton ���� �׽�Ʈ ���]
		//gotoxy(x + 44, y + 1);
		//for (int i = 0; i < 19; i++)
		//{
		//	gotoxy(x + 44, y + i);
		//	for (int j = 0; j < 19; j++)
		//	{
		//		printf("%2d", bo2[i + 2][j + 2]);
		//		//Sleep(50);
		//	}
		//}
		//----
	}
}
