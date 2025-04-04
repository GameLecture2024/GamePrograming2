#include "2DimensionArray.h"

void ShowLecture()
{
	printf("2차원 배열\n");

	int arr1[4][2] = {
		{0,1},
		{1,1},
		{1,0},
		{1,1}
	};

	int arr2[2][4] = {
		{0,1,1,0},
		{1,0,0,0}
	};

	// arr1의 총 개수 = 가로 * 세로
	
	printf("%d ", arr1[0][0]);
	printf("%d\n", arr1[0][1]);
	printf("%d ", arr1[1][0]);
	printf("%d\n", arr1[1][1]);
	printf("%d ", arr1[2][0]);
	printf("%d\n", arr1[2][1]);
	printf("%d ", arr1[3][0]);
	printf("%d\n", arr1[3][1]);

	printf("반복문으로 표현한 2차원 배열 \n");

	// for 반복문으로 표현해보자.
	// 가로만 1차원 배열이라고 생각하고 반복문으로 표현해본다.

	for (int c = 0; c < COL; c++)
	{
		for (int r = 0; r < ROW; r++)
		{
			printf("%d ", arr1[c][r]);
		}
		printf("\n");
	}

	// 변수
	// 매직 넘버 : 심볼릭 상수, 전처리문 
	// const COL_SIZE 

	printf("arr2 배열 출력\n");
	for (int c = 0; c < 2; c++)
	{
		for (int r = 0; r < 4; r++)
		{
			printf("%d ", arr2[c][r]);
		}
		printf("\n");
	}

	// char[][]      char (*ptr)[길이];
	// 문자를 데이터 타입으로 하는 2차원 배열을 만들어보세요.
	// 맵 만들어보세요. 4 x 5 맵을 만들어보세요. '#' 

	//printf("공백문자의 숫자 정의 : %c", ' ');

	char map1[4][5] =
	{
		{'#','#','#','#','#'},    // "#####" 주소
		{'#',' ',' ',' ','#'},
		{'#',' ',' ',' ','#'},
		{'#','#','#','#','#'},
	};

	int   sampleArr[4];          // sampleArr - int 포인터형

	//char* map2[4];               // char* 포인터 배열  char**

	char stage1[5][6 + 1] =
	{
		"######",    // '#','#','#','#','#','#' '\0'  "" 문자열의 끝 
		"#    #",
		"#    #",
		"#    #",
		"######",
	};

	printf("stage1 출력 \n");

	for (int c = 0; c < 5; c++)
	{
		for (int r = 0; r < 7; r++)
		{
			printf("%c", stage1[c][r]);
		}
		printf("\n");
	}


	printf("map1 출력 \n");
	for (int c = 0; c < 4; c++)
	{
		for (int r = 0; r < 5; r++)
		{
			printf("%c", map1[c][r]);
		}
		printf("\n");
	}
}