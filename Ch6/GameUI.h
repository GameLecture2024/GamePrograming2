#pragma once

#include <stdio.h>	 // printf, scanf
#include <Windows.h> // �ܼ� ���� �Լ�
#include <conio.h>   // getch
#include <time.h>	 // time
#include <stdlib.h>  // srand rand
#include <stdbool.h> // True, false
#include "StructPointer.h"

/*
*  ������ ����ü
*  ������ �̸�
*  �������� ��ǥ
*  ������ ����
*  ������ ���ݷ� ��ȭ���ʽ�
*/

// �������� ��ǥ  �÷��̾��� ��ǥ ���ؼ� (itmeX, playerX ��, itemY playerY�� �Ѵ� ������)-> �������� ȹ���ߴ�.


void GameStart();

void InputPlayerKey(Player* playerPtr);
	
void GotoXY(int x, int y);

void ShowPlayerInfo(const Player* playerPtr);
