/*
*  파일 입출력
*  1. fopen() - fclose() - FILE* fp;
*  2. 저장 fputc, fputs // fprintf() 
*  3. 로드 fgetc, fgets // fscanf()
*  4. 구조체를 이용해서 데이터를 저장하고 싶다.  
*/

#include "Rank.h"
#include <stdlib.h>
#include <conio.h>

int main()
{
	Rank ranks[MAXPLAYER];
	int order = 0;
	//AddRank(ranks, &order, "Bear", 100);
	//AddRank(ranks, &order, "Candy", 150);
	//AddRank(ranks, &order, "Dog", 250);
	//AddRank(ranks, &order, "Dog", 75);
	
	// 1. 데이터 파일을 로드하는 화면을 구성한다.

	printf("데이터를 불러오는 중입니다.\n");

	for (int i = 0; i < 10; i++)
	{
		printf("...");
		Sleep(100);
	}

	printf("................\n");
	Sleep(1000);
	order = LoadRank(RANKFILEPATH, ranks);
	printf("로딩이 완료되었습니다. 키를 입력해주세요.\n");
	_getch(); // 키보드 문자 입력을 받는 함수 conio.h
	system("cls");

	int firstRank = 0;

	while (1)
	{
		printf("1_랭킹 추가 2_랭킹 확인 3_프로그램 종료 4_랭킹 데이터 삭제 5_1위의 정보를 출력");
		int input = 0;
		scanf("%d", &input);

		switch (input)
		{
			case 1: AddRankData(ranks, &order); break;
			case 2: PrintRanking(ranks, order); break;
			case 3: FileSave(RANKFILEPATH, ranks, order);  return;
			case 4: DeleteRankData(ranks, &order, 0); break;
			case 5: 
				firstRank = FindMaxIndex(ranks, order);
				printf("랭킹 1위의 이름 : %s, 점수 : %d\n", ranks[firstRank].name, ranks[firstRank].score);
				break;
			default: 
				printf("잘못된 입력입니다. 키를 입력해주세요.\n");
				_getch();
				system("cls");
					break;
		}
	}

	
}