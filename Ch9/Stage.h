#pragma once

/*
*  1. 2차원 배열을 많이 사용하는 것
*  2. 구조체 안에 이차원 배열을 포함시켜서 호출한다. 
*/

/*
*  여러분이 직접 맵을 만들어보세요. 벽, 몬스터, 아이템, 출구
*  int wallX, wallY playerX, playerY
*  map1[세로][가로] == '벽' -> 무엇인가 해라
*  _kbhit  GetAsyncKeyState(VK_LEFT)
*  map1[새로운 플레이어의 Y값][새로운 플레이어의 X값] = 벽 => 해당 코드를 실행하지 마세요.
   앞에 벽이 있습니다. BOOL , 각 벽을 구조체
*/

// (1) 스테이지 2개 만들기
// (2) Stage 구조체 선언, 이름
// (3) 함수 만들어서 2차원 배열을 호출 

// 세로 5 가로 6   "" +1
#define STAGE_COL 5
#define STAGE_ROW 6
#include <stdio.h>

//STAGE 이름 = "황혼의 숲";
//이름.name = "황혼의 숲"

/*
*  1차원 배열 선언 방법 :  타입* 이름;
*  2차원 배열 선언 방법 : [2][4]   [4][2] 다르기 때문에 아래처럼 표현할 수 없다. 
*  포인터 배열 선언 방법 : 타입** 이름; -> 포인터의 배열    char* name[10]
* 
*  2차원 배열 어떻게 표현하는가? 세로 : 주소 (포인터)  가로 : 배열
*  char (*map)[가로의 길이];
*/

typedef struct _STAGE
{
    char* name;
    char(*map)[STAGE_ROW +1];
    // 2차원 배열을 저장할 수 있는 타입 선언
}STAGE;

// 스테이지를 여러개 만든 다음에 선택한 스테이지를 화면에 출력하는 함수
void SetStage(STAGE* stagePtr, int index); 