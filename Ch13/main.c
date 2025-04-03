/*
*  목표 : 상점 기능을 구현한다.
* 
*  1.상점을 데이터로 정의하세요. 아이템을 복수 개 판다.
*  2.아이템을 정의하세요. 배열로 접근할 수 있게 해야한다.
*/

/*
*  1. 2차원 배열 함수로 표현해보세요. -   void 함수 이름( char (*map)[길이 +1]);
*  2. 파일 저장 로드 시스템을 게임에 적용해볼 것 ( 구조체, 함수, 포인터)]
*  3. 만들고 싶은 기능 정하세요. 어떻게 구현해야할지 잘 모르겠다면 질문을 해주세요.
*/

#define NameLength 20

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <conio.h>

typedef struct
{
	char name[NameLength];
	int  price;
}Item;

void AddShopData(Item shop[], int* shopCount, const char* name, int price)
{	
	strncpy(shop[*shopCount].name, name, NameLength);
	shop[*shopCount].price = price;
	(*shopCount)++;
}

void ShowShopTable(Item shop[], int count)
{
	printf("+------+------+------------------+\n");
	printf("| 순서 | 가격 |    이름          |\n");
	printf("+------+------+------------------+\n");
	for (int i = 0; i < count; i++)
	{
		printf("| %4d | %4d | %-16s |\n", i + 1, shop[i].price, shop[i].name);
	}

	// 테두리 만든다.
	printf("+------+------+------------------+\n");

	_getch();
}

void ShowInventoryTable(Item invenotry[], int count)
{
	printf("유저의 인벤토리\n");
	printf("+------+------+------------------+\n");
	printf("| 순서 | 가격 |    이름          |\n");
	printf("+------+------+------------------+\n");
	for (int i = 0; i < count; i++)
	{
		printf("| %4d | %4d | %-16s |\n", i + 1, invenotry[i].price, invenotry[i].name);
	}

	// 테두리 만든다.
	printf("+------+------+------------------+\n");

	_getch();
}

void BuyItem(Item item, Item inventory[], int* count) // item : 상점에 있는 구매할 아이템, inventory : 플레이어가 저장할 인벤토리, 인벤토리의 저장 위치
{
	inventory[*count].price = item.price;
	strncpy(inventory[*count].name, item.name, NameLength);
	(*count)++;
}

void ShopPhase(Item shop[], Item inventory[], int count, int* inventoryCount, bool* gameQuit)
{
	printf("상점에 진입했습니다.\n");
	while (true)
	{
		printf("1_상점 목록을 확인한다. 2_아이템을 구입한다. 3_상점을 떠난다 4_게임 종료\n");		
		int input = 0;
		scanf("%d", &input);
		int itemIndex = 0;

		switch (input)
		{
		case 1: ShowShopTable(shop, count); break;
		case 2: 
			printf("구입할 아이템 번호를 입력해주세요\n");
			scanf("%d", &itemIndex);
			BuyItem(shop[itemIndex - 1], inventory, inventoryCount);			
			break;
		case 3: return;
		case 4: *gameQuit = true; return;
		}
	}
}



int main()
{
	Item Shop[10];
	int shopCount = 0;
	Item Inventory[10];
	int inventoryCount = 0;

	AddShopData(Shop, &shopCount, "롱소드", 100);
	AddShopData(Shop, &shopCount, "나무방패", 150);
	AddShopData(Shop, &shopCount, "숏소드", 200);
	AddShopData(Shop, &shopCount, "나무지팡이", 300);

	bool gameQuit = false; // gameQuit , "true"가 되면 게임을 종료한다.

	while (1)
	{
		ShopPhase(Shop,Inventory,  shopCount, &inventoryCount, &gameQuit);

		ShowInventoryTable(Inventory, inventoryCount);

		if (gameQuit)
		{
			break;
		}
	}

	printf("게임이 종료되었습니다.\n");

}