/*
*  ���� �����
*  1. fopen() - fclose() - FILE* fp;
*  2. ���� fputc, fputs // fprintf() 
*  3. �ε� fgetc, fgets // fscanf()
*  4. ����ü�� �̿��ؼ� �����͸� �����ϰ� �ʹ�.  
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
	
	// 1. ������ ������ �ε��ϴ� ȭ���� �����Ѵ�.

	printf("�����͸� �ҷ����� ���Դϴ�.\n");

	for (int i = 0; i < 10; i++)
	{
		printf("...");
		Sleep(100);
	}

	printf("................\n");
	Sleep(1000);
	order = LoadRank(RANKFILEPATH, ranks);
	printf("�ε��� �Ϸ�Ǿ����ϴ�. Ű�� �Է����ּ���.\n");
	_getch(); // Ű���� ���� �Է��� �޴� �Լ� conio.h
	system("cls");

	int firstRank = 0;

	while (1)
	{
		printf("1_��ŷ �߰� 2_��ŷ Ȯ�� 3_���α׷� ���� 4_��ŷ ������ ���� 5_1���� ������ ���");
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
				printf("��ŷ 1���� �̸� : %s, ���� : %d\n", ranks[firstRank].name, ranks[firstRank].score);
				break;
			default: 
				printf("�߸��� �Է��Դϴ�. Ű�� �Է����ּ���.\n");
				_getch();
				system("cls");
					break;
		}
	}

	
}