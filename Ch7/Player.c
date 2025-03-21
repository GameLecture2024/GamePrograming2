#include "Player.h"

void GetPlayerInput(Player* playerPtr)
{
	if (_kbhit())
	{
		if (GetAsyncKeyState(VK_LEFT))
		{
			// player의 pos값의 x값을 변경한다.
			playerPtr->pos.X -= 1;
		}
		else if (GetAsyncKeyState(VK_RIGHT))
		{
			// player의 pos값의 x값을 변경한다.
			playerPtr->pos.X += 1;
		}
		else if (GetAsyncKeyState(VK_UP))
		{
			// player의 pos값의 y값을 변경한다.
			playerPtr->pos.Y -= 1;
		}
		else if (GetAsyncKeyState(VK_DOWN))
		{
			// player의 pos값의 y값을 변경한다.
			playerPtr->pos.Y += 1;
		}
	}
}

// Windows.h // 

void ShowPlayer(const Player* playerPtr)
{
	// x,y좌표로 이동해서 printf한다.
	GoXYCOORD(playerPtr->pos);
	printf("★");
}

void InteractWithItem(Player* playerPtr, Item* itemPtr)
{
	// player, Item 좌표 각각의 x,y비교해서 두 좌표가 같으면 Item안에 있는 HasItem True변경해주는 코드를 작성

	// 1. player주소로 부터 좌표 가져온다.  playerPtr->pos COORD
	// 2. item주소로 부터 좌표 가져온다.	 itemPtr->pos	 COORD

	if (ComPareCOORD(playerPtr->pos, itemPtr->pos))	  // player, Item 좌표 각각의 x,y비교해서 두 좌표가 같으면
	{
		itemPtr->hasItem = true;
		
	}

}

void ShowPlayerItemInfo(Item* itemPtr)
{
    // 모든 아이템을 탐색해서 HasItemTrue인 녀석들만 정보를 보여줘

	if (itemPtr->hasItem)
	{
		printf(" %s 아이템을 획득했습니다. \n", itemPtr->itemName);
	}
}

void ShowPlayerAllItemInfo(Item* itemArray, int length)
{
	for (int i = 0; i < length; i++)
	{
		//(itemArray + i) // 배열의 시작 주소에서 i 데이터 크기만 더해라
			            // item. hasitem == true 실행
		                // itemArray[i]   ,  (itemArray + i)
		if ((itemArray+i)->hasItem == true)
		{
			printf(" %s 아이템을 보유하고 있습니다. \n", (itemArray+i)->itemName);
		}
		else
		{
			printf(" %s 아이템 미보유 상태입니다. \n", (itemArray + i)->itemName);
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
	// pos1.X pos2.X 비교  - if >
	// pos1.Y pos2.Y 비교  - if >
	// 둘다 같으면 true	  - &&
	// 아니면 false 반환	  - return true, false
	
	if (pos1.X == pos2.X && pos1.Y == pos2.Y)
	{
		return true;
	}
	else
	{
		return false;
	}	
}



