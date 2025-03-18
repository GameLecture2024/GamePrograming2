/*
*  작성일 : 2025-03-18
*  작성자 : 김동훈
*  주제   : 배열과 포인터
*/

/*
*  1. 배열(Array) : 왜,언제,어떻게 사용하는가?
*  예시 :    성적표, (국어,영어,수학)
*  사용 목적  : 하나의 변수로 같은 타입의 변수를 표현할 수 있다. 
*/

/*
*   문자(character) - '단어', 'a' 'p' 'p' 'l' 'e' 
*/

#include <stdio.h>
#include "Item.h"

int main()
{
	printf("배열과 포인터\n\n");

	printf("배열 예시 : 성적표 만들기\n");
	int scoreA = 80;    // 국어
	int scoreB = 60;	// 영어
	int scoreC = 40;	// 수학

	// 변수 : '데이터 타입'으로 선언한 저장소 - 메모리의 저장된 크기, 010101해석하는 방법, 시작하는 메모리 주소
	// 같은 타입의 변수를 하나의 이름으로 표현하는 방법 : 배열

	int scores[3] = { 80,60,40 }; // 배열을 선언 : int데이터 타입을 3개 저장하는 scores이름의 변수     

	scores[0]; // (scores주소 + 0) = 자기 자신
	scores[1]; // (scores주소 + 1) = 2번째 원소
	scores[2];

	printf("성적을 순서대로 출력하세요\n");
	for (int i = 0; i < 3; i++)
	{		
		printf("점수 : %d \n", scores[i]);
	}

	//printf("국어 : %d, 영어 : %d, 수학 : %d\n", scoreA, scoreB, scoreC);
	
	// 아이템 정의
	// 아이템 이름(문자열), 아이템 갯수, 아이템 Index
    
	char item1Name[10] = "AAA";	 // char A x 3 - 문자들의 배열 - 문자열
	int  item1Count = 1;
	int  itemIndex = 1;

	printf("예시\n\n");
	printf("아이템1번의 정보 \n");
	printf("아이템 번호 : %d, 아이템 이름 : %s, 아이템 수량 : %d\n", itemIndex, item1Name, item1Count);

	// 아이템을 데이터 설정한다. (게임의 고유 데이터, 세이브 데이터)
	ShowAllItemInfo();

	printf("문자열에 대한 이해 \n\n");

	// 사과(apple) 문자로 출력해보기
	char char1 = 'a';
	char char2 = 'p';
	char char3 = 'p';
	char char4 = 'l';
	char char5 = 'e';

	// appleis 띄어쓰기
	// apple is red
	// 문자열에서 마지막에 공백문자를 사용해서 이 문장이 끝났음을 알린다.
	printf("%c%c%c%c%c\n", char1, char2, char3, char4, char5);

	char chars[5] = { 'a','p','p','l','e' };   // "apple"

	for (int i = 0; i < 5; i++)
	{
		printf("%c", chars[i]);
	}

	printf("\n\n");
	char scoreName[10] = "국어"; // 포인터의 의미가 숨겨져있습니다.	16진수 주소로 저장하고 있었다.

	printf("%s\n", scoreName);   // string

	char scoreName2[10] = "English"; // 배열을 선언했을 때 저장할 공간이 남으면 어떻게 되는가? int -> 0

	printf("%c\n", scoreName2[0]);
	printf("%c\n", scoreName2[1]);
	printf("%c\n", scoreName2[2]);
	printf("%c\n", scoreName2[3]);
	printf("%c\n", scoreName2[4]);
	printf("%c\n", scoreName2[5]);
	printf("%d\n", scoreName2[6]);

	// "국어" - 문자열       메모리 주소| 국    |   어    | 
	// 메모리의 첫번째 주소를 알고, 메모리의 크기를 알면 글자를 한번에 출력할 수 있다.
	// "국" 문자 주소로 저장이 되어 있다.
	// 배열도 포인터 주소이다.
	
	char* scorePtr = "Math";
	printf("이름 : %s\n", scorePtr);
	printf("%c", *(scorePtr + 0)); // Math   "M"시작 주소 - scorePtr(1바이트)
	printf("%c", *(scorePtr + 1));
	printf("%c", *(scorePtr + 2));
	printf("%c", *(scorePtr + 3));

	// 왜 배열은 주소로 데이터를 저장하고 있을까?
	// 최대한의 효율로 메모리를 사용하기 위해서이다.
	// 주소 +1 2 3 4 5 ( 50단어)
	printf("\n\n");
	int number[10]; // 4x10    16바이트

	// 데이터의 이름을 표현하는 방법
	// 단어의 배열을 표현하는 방법

	char itemName[10] = "이름";
	char* itemNamePtr = "이름2";
	
	printf("%s , %s", itemName, itemNamePtr);

}