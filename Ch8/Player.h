#pragma once

#include <stdio.h>
#include <string.h>

#define NAMELENGTH 50

// 구조체
// Player
// char name[이름의 최대 길이]

typedef struct 
{
	char name[NAMELENGTH];
}Player;


void SetPlayerName(char* playerNamePtr);	// 플레이어 이름을 정해준다.(주소를 전달해줘야 한다)

void SetPlayer(Player* player, const char* name); // Player* 

void ShowPlayerInfo(Player* player);