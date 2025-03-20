#include "GameUI.h"
#pragma once

/*
*  ���� ��ǥ : �÷��̾��� ��ǥ�� Ű����κ��� �Է¹޾� ����Ǵ� �Լ��� �����
* 
*  1. �÷��̾� ��ǥ ���� - ����ü ����
*  2. Ű���带 �Է¹޴� �Լ� - �÷��̾� ��ǥ�� �Ű� ������ �޴� �Լ� Player*
*  3. Ŀ�� ��ġ�� �����ؼ� UI�� ����Ѵ�.
*/

void GameStart()
{
	// �÷��̾��� ������ �Է�
	POS    playerPos = { 0, 0 };
	Player myPlayer = { "�÷��̾�", playerPos };

	while (true)
	{
		  // 1. ������ �Է��� �޽��ϴ�.
		  // 2. ����� ������ ȭ�鿡 ����Ѵ�.
		  // 3. sleep(100)
		   
		InputPlayerKey(&myPlayer);
		ShowPlayerInfo(&myPlayer);
		Sleep(100);
	}
}

void InputPlayerKey(Player* playerPtr)
{
	system("cls");

	if (_kbhit())   // Ű���带 �Է����� �� true,  false
	{
		if (GetAsyncKeyState(VK_LEFT))          // Ű������ ���� Ű x��ǥ�� -1
		{
			// playerPtr����ؼ� x��ǥ�� -1
			playerPtr->playerPos.posX -= 1;
		}
		else if (GetAsyncKeyState(VK_RIGHT))
		{
			playerPtr->playerPos.posX += 1;
		}
		else if (GetAsyncKeyState(VK_UP))
		{
			// y��ǥ�� -1
			playerPtr->playerPos.posY -= 1;
		}
		else if (GetAsyncKeyState(VK_DOWN))
		{
			// y��ǥ�� +1
			playerPtr->playerPos.posY += 1;
		}
	}
}

void GotoXY(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void ShowPlayerInfo(const Player* playerPtr)
{
	GotoXY(50, 1);                // x ������ 50  y �Ʒ��� 1
	printf("�÷��̾��� ����");

	GotoXY(50, 3);
	printf("�÷��̾��� �̸� : %s", playerPtr->playerName);

	GotoXY(50, 4);
	printf("�÷��̾��� ��ġ : (%d, %d)", playerPtr->playerPos.posX, playerPtr->playerPos.posY);

	GotoXY(playerPtr->playerPos.posX, playerPtr->playerPos.posY);
	printf("��");

	int itemX = 5;
	int itemY = 5;

	GotoXY(itemX, itemY);
	printf("@");

}
