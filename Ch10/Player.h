#pragma once

/*
*  ������ 
   enum  �̸�;
   �̸��� �����Ѵ�. ���ڿ� �̸��� �����Ų��. const double PI = 3.14; �ɺ��� ���

   ���� : const int ONE; TWO; THREE; �������� ��ȣ
          const int ONE: TWo; THREE; 
       
*/

#include "ConsoleGame.h"

// ������ �ڸ����� �̿��ؼ� ������ ǥ���� �մϴ�.
// 00 0000 0000   (�ĺ���ȣ)(������ ����)(�ε��� ��ȣ)

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
	char* name; // �̸��� �������ų� �����Ѵ�.
	COORD pos;  // �÷��̾��� ��ǥ�� �����ϴ� �Լ� 
	RACE  race; // �÷��̾ ������ ����
}Player;


void GetPlayerName(Player player);
void SetPlayerName(Player* playerPtr);
void SetPlayerInput(Player* playerPtr);
void SetPlayerRace(Player* playerPtr);

void SetPlayer(Player* playerPtr);

void SelectColor(COLOR color);

void ShowPlayerInfo(Player* playerPtr, COORD uiPos);
