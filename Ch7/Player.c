#include "Player.h"

void GetPlayerInput(Player* playerPtr)
{
	if (_kbhit())
	{
		if (GetAsyncKeyState(VK_LEFT))
		{
			// player�� pos���� x���� �����Ѵ�.
			playerPtr->pos.X -= 1;
		}
		else if (GetAsyncKeyState(VK_RIGHT))
		{
			// player�� pos���� x���� �����Ѵ�.
			playerPtr->pos.X += 1;
		}
		else if (GetAsyncKeyState(VK_UP))
		{
			// player�� pos���� y���� �����Ѵ�.
			playerPtr->pos.Y -= 1;
		}
		else if (GetAsyncKeyState(VK_DOWN))
		{
			// player�� pos���� y���� �����Ѵ�.
			playerPtr->pos.Y += 1;
		}
	}
}

// Windows.h // 

void ShowPlayer(const Player* playerPtr)
{
	// x,y��ǥ�� �̵��ؼ� printf�Ѵ�.
	GoXYCOORD(playerPtr->pos);
	printf("��");
}

void InteractWithItem(Player* playerPtr, Item* itemPtr)
{
	// player, Item ��ǥ ������ x,y���ؼ� �� ��ǥ�� ������ Item�ȿ� �ִ� HasItem True�������ִ� �ڵ带 �ۼ�

	// 1. player�ּҷ� ���� ��ǥ �����´�.  playerPtr->pos COORD
	// 2. item�ּҷ� ���� ��ǥ �����´�.	 itemPtr->pos	 COORD

	if (ComPareCOORD(playerPtr->pos, itemPtr->pos))	  // player, Item ��ǥ ������ x,y���ؼ� �� ��ǥ�� ������
	{
		itemPtr->hasItem = true;
		
	}

}

void ShowPlayerItemInfo(Item* itemPtr)
{
    // ��� �������� Ž���ؼ� HasItemTrue�� �༮�鸸 ������ ������

	if (itemPtr->hasItem)
	{
		printf(" %s �������� ȹ���߽��ϴ�. \n", itemPtr->itemName);
	}
}

void ShowPlayerAllItemInfo(Item* itemArray, int length)
{
	for (int i = 0; i < length; i++)
	{
		//(itemArray + i) // �迭�� ���� �ּҿ��� i ������ ũ�⸸ ���ض�
			            // item. hasitem == true ����
		                // itemArray[i]   ,  (itemArray + i)
		if ((itemArray+i)->hasItem == true)
		{
			printf(" %s �������� �����ϰ� �ֽ��ϴ�. \n", (itemArray+i)->itemName);
		}
		else
		{
			printf(" %s ������ �̺��� �����Դϴ�. \n", (itemArray + i)->itemName);
		}
	}
}

void GoXY(int posX, int posY)
{
	COORD pos = { posX, posY };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void GoXYCOORD(COORD pos)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

BOOL ComPareCOORD(COORD pos1, COORD pos2)
{
	// pos1.X pos2.X ��  - if >
	// pos1.Y pos2.Y ��  - if >
	// �Ѵ� ������ true	  - &&
	// �ƴϸ� false ��ȯ	  - return true, false
	
	if (pos1.X == pos2.X && pos1.Y == pos2.Y)
	{
		return true;
	}
	else
	{
		return false;
	}	
}



