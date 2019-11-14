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
	std::cout << "인공지능 오목 게임 [ O-OMOK ] 입니다.";
	gotoxy(stX + 25, stY + 18);
	std::cout << "----------------------------------------";

	setCursorType(CursorInput); // 커서 입력모드

	gotoxy(stX + 25, stY + 16);
	std::cout << "시작하시겠습니까? (y/n) >> ";
	char a;
	std::cin >> a;
	if (a == 'y' || a == 'Y') {
		gotoxy(stX + 25, stY + 16);
		std::cout << "그럼 [ O-OMOK ] 1초후 시작합니다.";
		Sleep(1000);
	}
	else
	{
		gotoxy(stX + 25, stY + 16);
		std::cout << "[ O-OMOK ]을 2초후 종료합니다.";
		Sleep(2000);
		exit(0);
	}
}

void MainScene::selectFirst()
{
	setCursorType(CursorInvisible); // 커서 안보이게
	gotoxy(stX + 25, stY + 16);
	std::cout << "난이도를 설정합니다. ([엔터]키로 선택)     ";

	//gotoxy(stX + 25, stY + 18);
	//std::cout << "----------> easy (선공) <----------"; // ord가 1
	//gotoxy(stX + 25, stY + 20);
	//std::cout << "            hard (후공)            "; // ord가 -1

	while (true)
	{
		if (ord > 0)
		{
			gotoxy(stX + 25, stY + 24);
			std::cout << "------------> easy (선공) <------------"; // ord가 1
			gotoxy(stX + 25, stY + 26);
			std::cout << "              hard (후공)              "; // ord가 -1
		}
		else if (ord < 0)
		{
			gotoxy(stX + 25, stY + 24);
			std::cout << "              easy (선공)              "; // ord가 1
			gotoxy(stX + 25, stY + 26);
			std::cout << "------------> hard (후공) <------------"; // ord가 -1
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
