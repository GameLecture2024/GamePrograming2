/*
*  작성일 : 2025-03-24
*  작성자 : 김동훈
*  주제   : 문자열의 응용
*/

/*
*  문자열 : 배열로 이루어진 문자
*  string : char(acter) array
*/

/*
*  문자열 맵을 만들어 본다.
*/

#include "MyString.h"
#include "Player.h"

/*
*  " " 문자열의 배열
*  " " 갯수 + 1 크기가 지정되어 있다.
*  "apple"    a, p,p,l,e,'\0' 문자열의 종료를 의미한다.
*  "apple is"  / 00101010101010 문자열의 끝을 알려주기 위해서 '\0'
*/

#define STAGE_HEIGHT 5
#define STAGE_WIDTH  6 

// 가로의 길이가 더 크면 결과가 이상하게 출력된다.

char stage1[STAGE_HEIGHT][STAGE_WIDTH + 1] =
{
	"######",    // char 2차원 배열
	"#    #",
	"#    #",
	"#    #",
	"######",
};

char stage2[STAGE_HEIGHT][STAGE_WIDTH + 1] =
{
	"######",    // char 2차원 배열
	"#    #",
	"# # ##",
	"#    #",
	"######",
};


int main()
{
	//ArrayExample();

	// 1. 게임 시작  

	// 플레이할 캐릭터의 이름을 설정한다.	SetPlayerName
    // char*에 저장을 해서 원할 때 이 데이터를 호출한다. ShowPlayerInfo

	// int, double 주소 
	// 문자열(문자의 배열) 배열의 이름이 주소

	// 배열 - 포인터
	// 배열 포인터의 주소를 변경하면 안된다. 상수 포인터

	//char* playerName;
	//printf("플레이어의 이름을 입력해주세요\n");
	//
	//char input[50];
	//
	//scanf_s("%s", input, 50);
	//
	//playerName = input;
	//SetPlayerName(playerName);
	//printf("%s", playerName);

	// Player 코드

	Player player;
	Player* playerPtr = &player;
	char inputA[10] = "";
	printf("플레이어의 이름을 입력해주세요.\n");
	scanf_s("%s", inputA, 10);
	SetPlayer(&player, inputA);
	ShowPlayerInfo(&player);

	// 2차원 배열

	printf("\n");
	printf("맵 출력\n");

	// 가로x1줄 세로xn줄 출력

	for (int i = 0; i < STAGE_HEIGHT; i++)
	{
		printf("%s\n", stage2[i]);
	}


}