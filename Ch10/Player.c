#include "Player.h"
#pragma once

void GetPlayerName(Player player)
{
	printf("%s", player.name);
}

void SetPlayerName(Player* playerPtr)
{
	char* inputName = malloc(sizeof(inputName));
	scanf_s("%s", inputName, 10); // '\0'

	(*playerPtr).name = inputName;
}

void SetPlayerInput(Player* playerPtr)
{
	// �÷��̾��� �Է��� �Ǻ��Ѵ�. 4���� return
	// ���� enum   0 : ����, 1 : ������ 2 : ���� 3: �Ʒ���
	// enum ��

	if (_kbhit)
	{
		if (GetAsyncKeyState(VK_LEFT))
		{
			(*playerPtr).pos.X -= 1;
	    }
		else if (GetAsyncKeyState(VK_RIGHT))
		{
			(*playerPtr).pos.X += 1;
		}
		else if (GetAsyncKeyState(VK_UP))
		{
			(*playerPtr).pos.Y -= 1;
		}
		else if (GetAsyncKeyState(VK_DOWN))
		{
			(*playerPtr).pos.Y += 1;
		}
	}
}



void SelectColor(COLOR color)
{
	switch (color)
	{
	case RED:
		printf("RED �Դϴ�.");
		break;
	case GREEN:
		printf("Green �Դϴ�.");
		break;
	case BLUE:
		printf("Blue �Դϴ�.");
		break;
	}
}

void ShowPlayerInfo(Player* playerPtr)
{
    // �̸�, ��ǥ, ����

	Player tempPlayer = *playerPtr;

	if (playerPtr == NULL)
	{
		return;
	}

	printf("%s ", playerPtr->name);
	//GetPlayerName(*playerPtr);
	//GetPlayerPos(*playerPtr);
	//GetPlayerRace(*playerPtr);
}