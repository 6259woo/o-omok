#include "MainScene.h"
#include "ConsoleFunctions.h"

MainScene::MainScene()
{

}

MainScene::~MainScene()
{
}

void MainScene::beginScreen()
{
	system("cls");
	setSize(102, 38);
	setCursorType(CursorInvisible);

	gotoxy(stX, stY);
	std::cout << "//        ___                             ___           ___           ___           ___     ";
	gotoxy(stX, stY + 1);
	std::cout << "//       /\\  \\                           /\\  \\         /\\__\\         /\\  \\         /\\__\\  ";
	gotoxy(stX, stY + 2);
	std::cout << "//      /::\\  \\                         /::\\  \\       /::|  |       /::\\  \\       /:/  /   ";
	gotoxy(stX, stY + 3);
	std::cout << "//     /:/\\:\\  \\                       /:/\\:\\  \\     /:|:|  |      /:/\\:\\  \\     /:/__/     ";
	gotoxy(stX, stY + 4);
	std::cout << "//    /:/  \\:\\  \\                     /:/  \\:\\  \\   /:/|:|__|__   /:/  \\:\\  \\   /::\\__\\____ ";
	gotoxy(stX, stY + 5);
	std::cout << "//   /:/__/ \\:\\__\\                   /:/__/ \\:\\__\\ /:/ |::::\\__\\ /:/__/ \\:\\__\\ /:/\\:::::\\__\\ ";
	gotoxy(stX, stY + 6);
	std::cout << "//   \\:\\  \\ /:/  /                   \\:\\  \\ /:/  / \\/__/~~/:/  / \\:\\  \\ /:/  / \\/_|:|~~|~   ";
	gotoxy(stX, stY + 7);
	std::cout << "//    \\:\\  /:/  /                     \\:\\  /:/  /        /:/  /   \\:\\  /:/  /     |:|  |    ";
	gotoxy(stX, stY + 8);
	std::cout << "//     \\:\\/:/  /                       \\:\\/:/  /        /:/  /     \\:\\/:/  /      |:|  |    ";
	gotoxy(stX, stY + 9);
	std::cout << "//      \\::/  /                         \\::/  /        /:/  /       \\::/  /       |:|  |    ";
	gotoxy(stX, stY + 10);
	std::cout << "//       \\/__/                           \\/__/         \\/__/         \\/__/         \\|__|    ";


	//        ___                             ___           ___           ___           ___     
	//       /\  \                           /\  \         /\__\         /\  \         /\__\    
	//      /::\  \                         /::\  \       /::|  |       /::\  \       /:/  /    
	//     /:/\:\  \                       /:/\:\  \     /:|:|  |      /:/\:\  \     /:/__/     
	//    /:/  \:\  \                     /:/  \:\  \   /:/|:|__|__   /:/  \:\  \   /::\__\____ 
	//   /:/__/ \:\__\                   /:/__/ \:\__\ /:/ |::::\__\ /:/__/ \:\__\ /:/\:::::\__\
	//   \:\  \ /:/  /                   \:\  \ /:/  / \/__/~~/:/  / \:\  \ /:/  / \/_|:|~~|~   
	//    \:\  /:/  /                     \:\  /:/  /        /:/  /   \:\  /:/  /     |:|  |    
	//     \:\/:/  /                       \:\/:/  /        /:/  /     \:\/:/  /      |:|  |    
	//      \::/  /                         \::/  /        /:/  /       \::/  /       |:|  |    
	//       \/__/                           \/__/         \/__/         \/__/         \|__|    



	gotoxy(stX + 25, stY + 13);
	std::cout << "---------------[ O-OMOK ]---------------";
	gotoxy(stX+25, stY + 15);
	std::cout << "�ΰ����� ���� ���� [ O-OMOK ] �Դϴ�.";
	gotoxy(stX + 25, stY + 18);
	std::cout << "----------------------------------------";

	setCursorType(CursorInput); // Ŀ�� �Է¸��

	gotoxy(stX + 25, stY + 16);
	std::cout << "�����Ͻðڽ��ϱ�? (y/n) >> ";
	char a;
	std::cin >> a;
	if (a == 'y' || a == 'Y') {
		gotoxy(stX + 25, stY + 16);
		std::cout << "�׷� [ O-OMOK ] 1���� �����մϴ�.";
		Sleep(1000);
	}
	else
	{
		gotoxy(stX + 25, stY + 16);
		std::cout << "[ O-OMOK ]�� 2���� �����մϴ�.";
		Sleep(2000);
		exit(0);
	}
}

void MainScene::selectFirst()
{
	setCursorType(CursorInvisible); // Ŀ�� �Ⱥ��̰�
	gotoxy(stX + 25, stY + 16);
	std::cout << "���̵��� �����մϴ�. ([����]Ű�� ����)     ";

	//gotoxy(stX + 25, stY + 18);
	//std::cout << "----------> easy (����) <----------"; // ord�� 1
	//gotoxy(stX + 25, stY + 20);
	//std::cout << "            hard (�İ�)            "; // ord�� -1

	while (true)
	{
		if (ord > 0)
		{
			gotoxy(stX + 25, stY + 24);
			std::cout << "------------> easy (����) <------------"; // ord�� 1
			gotoxy(stX + 25, stY + 26);
			std::cout << "              hard (�İ�)              "; // ord�� -1
		}
		else if (ord < 0)
		{
			gotoxy(stX + 25, stY + 24);
			std::cout << "              easy (����)              "; // ord�� 1
			gotoxy(stX + 25, stY + 26);
			std::cout << "------------> hard (�İ�) <------------"; // ord�� -1
		}

		if (_kbhit())
		{
			char key = _getch();
			if (key == 13)
			{
				break;
			}
			else
			{
				ord *= -1;
			}
		}

		/*gotoxy(stx + 25, sty + 30);
		std::cout << "ord = " << ord << "   ";*/
	}
	
}
