#include "Struct.h"

void StructExample()
{   
	// �÷��̾��� ������ ������. (1. ��ġ ��)

	struct Pos playerPos = { 1,1 };

	// �÷��̾��� ��ǥ�� ������ּ���     
	// ���� ������(.) ������ �����Ϳ� ������ �� �ִ�.

	printf("[%d,%d]\n", playerPos.xPos, playerPos.yPos);

	Pos origin1 = { 0,0 };
	struct Circle myCircle = { origin1, 2.5 };

	printf("���� : [%d,%d], ������ : %lf\n", myCircle.origin.xPos, myCircle.origin.yPos, myCircle.radius);

	CalculateCircleInfo(myCircle);



	char playerName[10] = "ȫ�浿";
	Player myPlayer = { playerName, playerPos };

	// Player����
	ShowPlayerCurrentPos(myPlayer);
}

void CalculateCircleInfo(Circle circle)
{
	// ȣ�� ���� 2 * PI * R
	printf("ȣ�� ���� : %lf\n", 2 * 3.14 * circle.radius);
	printf("���� ���� : %lf\n", 0.5 * 3.14 * circle.radius * circle.radius);
	printf("������ ��ġ : [%d,%d]\n", circle.origin.xPos, circle.origin.yPos);
}

void ShowPlayerCurrentPos(Player player)
{
	printf("�÷��̾��� �̸� : %s\n", player.playerName);
}

void MovePlayer(Player player)
{
}
