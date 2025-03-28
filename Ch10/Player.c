#include "Player.h"
#pragma once

void GetPlayerName(Player player)
{
	printf("%s", player.name);
}

void SetPlayerName(Player* playerPtr)
{
	printf("�÷��̾��� �̸��� �ۼ����ּ���\n");
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

void SetPlayerRace(Player* playerPtr)
{
	printf("�÷��̾��� ������ �������ּ���\n");
	printf("1_Human 2_ORC 3_TROLL\n");
	int inputNumber = -1;
	scanf_s("%d", &inputNumber);

	switch (inputNumber)
	{
	case 1 :
		playerPtr->race = HUMAN;
		return;
	case 2:
		playerPtr->race = ORC;
		return;
	case 3:
		playerPtr->race = TROLL;
		return;
	default:
		SetPlayerRace(playerPtr);
	}

	
}

void SetPlayer(Player* playerPtr)
{
	SetPlayerName(playerPtr);
	SetPlayerRace(playerPtr);

	printf("�÷��̾� ������ �Ϸ�Ǿ����ϴ�.\n �����Ϸ��� �ƹ� ��ư�̳� �Է����ּ���\n");
	_getch();
	system("cls");
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

void ShowPlayerInfo(Player* playerPtr, COORD uiPos)
{
	GoToXY(uiPos.X, uiPos.Y);
	printf("�÷��̾��� ����");
	GoToXY(uiPos.X, uiPos.Y + 1);
	printf("�̸� : %s", playerPtr->name);
	GoToXY(uiPos.X, uiPos.Y + 2);
	printf("��ǥ : [%d,%d]", playerPtr->pos.X, playerPtr->pos.Y);
	GoToXY(uiPos.X, uiPos.Y + 3);
	printf("%������ �ش��ϴ� ���ڸ� ����Ѵ� (1 : Human 2 : ORC 3 : TROLL) : %d", playerPtr->race);
}

