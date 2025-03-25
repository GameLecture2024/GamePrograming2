#include "Stage.h"

char stage1[STAGE_COL][STAGE_ROW + 1] =
{
	"######",   // '\0'
	"#    #",
	"#    #",
	"#    #",
	"######"
};

char stage2[STAGE_COL][STAGE_ROW + 1] =
{
	"######",   // '\0'
	"#   ##",
	"# #  #",
	"##   #",
	"######"
};

void SetStage(STAGE* stagePtr, int index)
{
	switch (index)
	{
	case 1:
		// 스테이지를 1번을 선택한다 -> Stage1 가져온다.
		stagePtr->name = "황혼의 숲";
		stagePtr->map = stage1;
		break;
	case 2:
		stagePtr->name = "버섯 숲";
		stagePtr->map = stage2;
		break;
	default:
		printf("잘못된 스테이지 번호입니다.\n");
		break;
	}
}
