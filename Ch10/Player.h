#pragma once

/*
*  열거형 
   enum  이름;
   이름을 나열한다. 숫자에 이름을 적용시킨다. const double PI = 3.14; 심볼릭 상수

   이유 : const int ONE; TWO; THREE; 아이템의 번호
          const int ONE: TWo; THREE; 
       
*/

#include "ConsoleGame.h"

// 숫자의 자리수를 이용해서 성질을 표현을 합니다.
// 00 0000 0000   (식별번호)(데이터 성질)(인덱스 번호)

typedef enum _COLOR
{
	RED, GREEN, BLUE
}COLOR;

typedef enum _Race
{
   HUMAN = 1, ORC, TROLL
}RACE;

typedef struct _Player
{
	char* name; // 이름을 가져오거나 설정한다.
	COORD pos;  // 플레이어의 좌표를 변경하는 함수 
	RACE  race; // 플레이어가 선택한 종족
}Player;


void GetPlayerName(Player player);
void SetPlayerName(Player* playerPtr);
void SetPlayerInput(Player* playerPtr);
void SetPlayerRace(Player* playerPtr);

void SetPlayer(Player* playerPtr);

void SelectColor(COLOR color);

void ShowPlayerInfo(Player* playerPtr, COORD uiPos);
