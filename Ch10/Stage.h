#pragma once

#define STAGE_WIDTH 20
#define STAGE_HEIGHT 20

char Stage1[STAGE_HEIGHT][STAGE_WIDTH + 1];
char Stage2[STAGE_HEIGHT][STAGE_WIDTH + 1];

typedef struct _StagePOS
{
	int X;
	int Y;
}STAGEPOS;

typedef struct _STAGE
{
	char* name;
	char(*stage)[STAGE_WIDTH + 1];
	STAGEPOS stagepos;
}STAGE;