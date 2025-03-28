#pragma once

#include "MyGame.h"

void GameStart()
{
	 // �÷��̾ �������ּ��� - �̸�, ����, ��ǥ 
	 
	 Player player;
	 COORD playerPos = { 10, 10 };
	 SetPlayer(&player);

	 // �������� ���
	 COORD stagePos = { 20, 0 };
	 ShowStage(Stage1, stagePos);

	 player.pos = PlusCOORD(playerPos, stagePos);

	 // �ݺ��ؼ� ����Ǵ� ���� ���� UI ���  , �÷��̾� ����, 
	 // ShowPlayerUIInfo(&player);

	 // �迭  �迭 �ε���
	 // �迭[�ε���]

	 COORD UserInterfacePos = { 60,0 };

	 while (true)
	 {
		  // 1. �÷��̾� �̵�

		 GoToXY(player.pos.X, player.pos.Y);
		 printf("  ");

		 SetPlayerInput(&player);
		 GoToXY(player.pos.X, player.pos.Y);
		 printf("��");

		 // 2. Stage Ư���� ���ڿ� ���� ������ ���� ���������� �̵��϶�

		 COORD playerStagePos = { player.pos.X - stagePos.X, player.pos.Y - stagePos.Y };

		 if (CanMoveStage(Stage1, playerStagePos, '@'))
		 {
			 NextStage(Stage2, stagePos);
			 player.pos = PlusCOORD(playerPos, stagePos);	// �������� �̵����� �� ��� ������ �ǰ�
		 }

		 // 3. �÷��̾��� ���� UI ��� 
		 ShowPlayerInfo(&player, UserInterfacePos);

		 Sleep(100);
	 }
}




// ---------------------- ���α׷� ������ // 
int main()
{
	GameStart();
}