#include "2DimensionArray.h"
#include "Stage.h"

int main()
{
	//ShowLecture();
	STAGE stage1; // STAGEŸ���� �� ���� �̸��� stage1�� ����
	SetStage(&stage1, 1);
	STAGE stage2; // STAGEŸ���� �� ���� �̸��� stage1�� ����
	SetStage(&stage2, 2);
	printf("�������� �̸� ��� : %s\n", stage1.name);
	printf("�������� 1�� �� ���:\n");
	
	for (int i = 0; i < STAGE_COL; i++)
	{
		printf("%s\n", stage1.map[i]);
	}
	

	printf("�������� �̸� ��� : %s\n", stage2.name);

	printf("�������� 2�� �� ���:\n");

	for (int i = 0; i < STAGE_COL; i++)
	{
		printf("%s\n", stage2.map[i]);
	}
}