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
		// ���������� 1���� �����Ѵ� -> Stage1 �����´�.
		stagePtr->name = "Ȳȥ�� ��";
		stagePtr->map = stage1;
		break;
	case 2:
		stagePtr->name = "���� ��";
		stagePtr->map = stage2;
		break;
	default:
		printf("�߸��� �������� ��ȣ�Դϴ�.\n");
		break;
	}
}
