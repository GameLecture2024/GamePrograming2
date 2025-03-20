#include "StructPointer.h"

void Ch6Example()
{
	printf("Ch6\n");

	POS playerPos = { 5,5 };
	playerPos.posX = 3;
	playerPos.posY = 4;

	Player player1 = { "AAA", playerPos };

	//printf("플레이어의 이름 : %s, 플레이어의 현재 위치 : [%d,%d]", 
	//	player1.playerName, player1.playerPos.posX, player1.playerPos.posY);

	//ShowPlayerInfo1(player1);
	//ShowPlayerInfo2(&player1);
	ShowPlayerInfo3(&player1);
	ChangePlayerPos(&player1);
}

void ShowPlayerInfo1(Player player)
{
	printf("플레이어의 이름 : %s, 플레이어의 현재 위치 : [%d,%d]",
		player.playerName, player.playerPos.posX, player.playerPos.posY);
}

void ShowPlayerInfo2(const Player* playerPtr)
{
	printf("플레이어의 이름 : %s, 플레이어의 현재 위치 : [%d,%d]",
		(*playerPtr).playerName, (*playerPtr).playerPos.posX, (*playerPtr).playerPos.posY);
}

void ShowPlayerInfo3(const Player* playerPtr)
{
	printf("플레이어의 이름 : %s, 플레이어의 현재 위치 : [%d,%d]",
		playerPtr->playerName, playerPtr->playerPos.posX, playerPtr->playerPos.posY);
}

void ChangePlayerPos(Player* playerPtr)
{
	playerPtr->playerPos.posX += 1;
	playerPtr->playerPos.posY += 1;
}
