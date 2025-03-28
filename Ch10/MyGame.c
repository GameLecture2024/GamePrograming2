#pragma once

#include "MyGame.h"

void GameStart()
{
	 // 플레이어를 설정해주세요 - 이름, 종족, 좌표 
	 
	 Player player;
	 COORD playerPos = { 10, 10 };
	 SetPlayer(&player);

	 // 스테이지 출력
	 COORD stagePos = { 20, 0 };
	 ShowStage(Stage1, stagePos);

	 player.pos = PlusCOORD(playerPos, stagePos);

	 // 반복해서 실행되는 게임 로직 UI 출력  , 플레이어 조작, 
	 // ShowPlayerUIInfo(&player);

	 // 배열  배열 인덱스
	 // 배열[인덱스]

	 COORD UserInterfacePos = { 60,0 };

	 while (true)
	 {
		  // 1. 플레이어 이동

		 GoToXY(player.pos.X, player.pos.Y);
		 printf("  ");

		 SetPlayerInput(&player);
		 GoToXY(player.pos.X, player.pos.Y);
		 printf("★");

		 // 2. Stage 특별한 문자와 값이 같으면 다음 스테이지로 이동하라

		 COORD playerStagePos = { player.pos.X - stagePos.X, player.pos.Y - stagePos.Y };

		 if (CanMoveStage(Stage1, playerStagePos, '@'))
		 {
			 NextStage(Stage2, stagePos);
			 player.pos = PlusCOORD(playerPos, stagePos);	// 스테이지 이동했을 때 어디서 시작할 건가
		 }

		 // 3. 플레이어의 정보 UI 출력 
		 ShowPlayerInfo(&player, UserInterfacePos);

		 Sleep(100);
	 }
}




// ---------------------- 프로그램 진입점 // 
int main()
{
	GameStart();
}