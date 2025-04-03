/*
*  ��ǥ : ���� ����� �����Ѵ�.
* 
*  1.������ �����ͷ� �����ϼ���. �������� ���� �� �Ǵ�.
*  2.�������� �����ϼ���. �迭�� ������ �� �ְ� �ؾ��Ѵ�.
*/

/*
*  1. 2���� �迭 �Լ��� ǥ���غ�����. -   void �Լ� �̸�( char (*map)[���� +1]);
*  2. ���� ���� �ε� �ý����� ���ӿ� �����غ� �� ( ����ü, �Լ�, ������)]
*  3. ����� ���� ��� ���ϼ���. ��� �����ؾ����� �� �𸣰ڴٸ� ������ ���ּ���.
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
	printf("| ���� | ���� |    �̸�          |\n");
	printf("+------+------+------------------+\n");
	for (int i = 0; i < count; i++)
	{
		printf("| %4d | %4d | %-16s |\n", i + 1, shop[i].price, shop[i].name);
	}

	// �׵θ� �����.
	printf("+------+------+------------------+\n");

	_getch();
}

void ShowInventoryTable(Item invenotry[], int count)
{
	printf("������ �κ��丮\n");
	printf("+------+------+------------------+\n");
	printf("| ���� | ���� |    �̸�          |\n");
	printf("+------+------+------------------+\n");
	for (int i = 0; i < count; i++)
	{
		printf("| %4d | %4d | %-16s |\n", i + 1, invenotry[i].price, invenotry[i].name);
	}

	// �׵θ� �����.
	printf("+------+------+------------------+\n");

	_getch();
}

void BuyItem(Item item, Item inventory[], int* count) // item : ������ �ִ� ������ ������, inventory : �÷��̾ ������ �κ��丮, �κ��丮�� ���� ��ġ
{
	inventory[*count].price = item.price;
	strncpy(inventory[*count].name, item.name, NameLength);
	(*count)++;
}

void ShopPhase(Item shop[], Item inventory[], int count, int* inventoryCount, bool* gameQuit)
{
	printf("������ �����߽��ϴ�.\n");
	while (true)
	{
		printf("1_���� ����� Ȯ���Ѵ�. 2_�������� �����Ѵ�. 3_������ ������ 4_���� ����\n");		
		int input = 0;
		scanf("%d", &input);
		int itemIndex = 0;

		switch (input)
		{
		case 1: ShowShopTable(shop, count); break;
		case 2: 
			printf("������ ������ ��ȣ�� �Է����ּ���\n");
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

	AddShopData(Shop, &shopCount, "�ռҵ�", 100);
	AddShopData(Shop, &shopCount, "��������", 150);
	AddShopData(Shop, &shopCount, "���ҵ�", 200);
	AddShopData(Shop, &shopCount, "����������", 300);

	bool gameQuit = false; // gameQuit , "true"�� �Ǹ� ������ �����Ѵ�.

	while (1)
	{
		ShopPhase(Shop,Inventory,  shopCount, &inventoryCount, &gameQuit);

		ShowInventoryTable(Inventory, inventoryCount);

		if (gameQuit)
		{
			break;
		}
	}

	printf("������ ����Ǿ����ϴ�.\n");

}