#include "FileHandler.h"

#define RANKFILEPATH "Rank.txt"

/*
*  1. FILE* �����ϼ���. ���, ���
*/

void SaveScore(char* name, int score)
{
	FILE* fp = fopen(RANKFILEPATH, "w"); // wt : write txt,  wb : write binary

	if (fp == NULL)
	{
		printf("��ο� ������ �������� �ʽ��ϴ�.");
		return;
	}

	fprintf(fp, "%s %d\n", name, score);

	// fputc, fputs, fprintf

	fclose(fp);
}

void LoadRank()
{
	FILE* fp = fopen(RANKFILEPATH, "r"); // wt : write txt,  wb : write binary

	if (fp == NULL)
	{
		printf("��ο� ������ �������� �ʽ��ϴ�.");
		return;
	}

	char name[4];
	int score;

	fscanf(fp, "%s %d\n", name, &score);
	printf("�̸� : %s, ���� : %d", name, score);

	// fgetc, fgets, fscanf

	fclose(fp);
}
