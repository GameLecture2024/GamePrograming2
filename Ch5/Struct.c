#include "Struct.h"

void StructExample()
{   
	// 플레이어의 정보를 만들어본다. (1. 위치 값)

	struct Pos playerPos = { 1,1 };

	// 플레이어의 좌표를 출력해주세요     
	// 접근 연산자(.) 내부의 데이터에 접근할 수 있다.

	printf("[%d,%d]\n", playerPos.xPos, playerPos.yPos);

	Pos origin1 = { 0,0 };
	struct Circle myCircle = { origin1, 2.5 };

	printf("원점 : [%d,%d], 반지름 : %lf\n", myCircle.origin.xPos, myCircle.origin.yPos, myCircle.radius);

	CalculateCircleInfo(myCircle);



	char playerName[10] = "홍길동";
	Player myPlayer = { playerName, playerPos };

	// Player선언
	ShowPlayerCurrentPos(myPlayer);
}

void CalculateCircleInfo(Circle circle)
{
	// 호의 길이 2 * PI * R
	printf("호의 길이 : %lf\n", 2 * 3.14 * circle.radius);
	printf("원의 넓이 : %lf\n", 0.5 * 3.14 * circle.radius * circle.radius);
	printf("원점의 위치 : [%d,%d]\n", circle.origin.xPos, circle.origin.yPos);
}

void ShowPlayerCurrentPos(Player player)
{
	printf("플레이어의 이름 : %s\n", player.playerName);
}

void MovePlayer(Player player)
{
}
