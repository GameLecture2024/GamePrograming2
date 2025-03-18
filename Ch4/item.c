#include "Item.h"
#define ITEMALLCOUNT 6


void ShowAllItemInfo()
{
	// 아이템을 데이터 설정한다. (게임의 고유 데이터, 세이브 데이터)
	int itemCount[ITEMALLCOUNT]  = { 1,2,3,4,5 };
	int itemIndexs[ITEMALLCOUNT] = { 1,2,3,4,5 };
	int itemType[ITEMALLCOUNT]   = { 0,1,0,2,1 };             // 0 : 소비형 , 1: 장비형, 2: 퀘스트템
	char* itemName[ITEMALLCOUNT] = { "AAA","BBB","CCC","DDD","EEE" };
	printf("모든 아이템을 열람한다.\n");

	for (int i = 0; i < ITEMALLCOUNT; i++)
	{
		printf("아이템 번호 : %d, 아이템 이름 : %s, 아이템 수량 : %d, 아이템 타입 : %d \n", itemIndexs[i], itemName[i], itemCount[i], itemType[i]);
	}
}


// 아이템 이름 배열과 포인터를 이용해서 출력해보세요.

// 상수 포인터 

// 아이템 이름  - 문자열
// 아이템 설명  - 문자열
// 1번 인덱스에 있는 아이템의 이름과 설명을 출력하는 기능 구현

// 아이템 이름 1개 - 배열
// 배열(배열 - 배열)

void ItemExample()
{
	// 배열 타입으로 이름 선언하기
	//char itemName[10]
	// 포인터 타입으로 이름 선언하기
	//char* itemName
}
