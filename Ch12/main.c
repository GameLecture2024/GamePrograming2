/*
*  ���� �����
*  1. fopen() - fclose() - FILE* fp;
*  2. ���� fputc, fputs // fprintf() 
*  3. �ε� fgetc, fgets // fscanf()
*  4. ����ü�� �̿��ؼ� �����͸� �����ϰ� �ʹ�.  
*/

#include "Rank.h"

int main()
{
	printf("1. ������ �����ϴ� �Լ� ����\n");
	FileSaveTemp();
	printf("2. ������ �о���� �Լ� ����\n");
	FileLoadTemp();
	printf("3. ��ũ ����ü�� ����\n");

	Rank ranks[MAXPLAYER];
	int order = 0;
	AddRank(ranks, &order, "Bear", 100);
	AddRank(ranks, &order, "Candy", 150);
	AddRank(ranks, &order, "Dog", 250);
	AddRank(ranks, &order, "Dog", 75);
	
	//order = LoadRank(RANKFILEPATH, ranks);

	if (order < MAXPLAYER)
	{
		printf("���ο� �÷��̾��� �̸��� �Է��ϼ��� : \n");
		char newName[MAXLENGTH];
		int newScore;

		scanf("%49s", newName);
		printf("������ �Է��ϼ��� : \n");
		scanf("%d", &newScore);

		AddRank(ranks, &order, newName, newScore);
	}						 

	PrintRanking(ranks, order);

	FileSave(RANKFILEPATH, ranks, order);
}