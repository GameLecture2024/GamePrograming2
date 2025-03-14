#include "lecture.h"
#pragma once

// ���� ����
int GameScore = 0;

void ShowLecture()
{
	printf("���� ���� 1\n");

	// ������ �����ϰ� �ּҸ� ����غ�����.
	int num1 = 10;
	int* numptr = &num1;          // �ּ�	  =  ��

	printf("���� ��� : %d \n", num1);
	printf("�ּҸ� ��� : %p \n\n", numptr);

	printf("���� �ǽ� 1\n"); // �� ������ ���� �����ϴ� �Լ��� �����Ѵ�.
	
	// int* 2�� �ʿ��ϴ�. - int�� �ּҰ� 2�� �ʿ��ϴ�.
	int numA = 5;
	int numB = 6;
	printf("numA�� �� : %d, numB�� �� : %d\n", numA, numB);
	Swap(&numA, &numB);
	printf("numA�� �� : %d, numB�� �� : %d\n\n", numA, numB);

	printf("���� ���� 1\n"); // ������ ȹ���ϴ� �ý����� ���� // Ư�� �ൿ,  �ð��� ���� ����
	
	IncreaseScore(&GameScore, 10);
	IncreaseTemp(GameScore, 10);
	printf("���� ���� : %d", GameScore);

	printf("���� �ǽ� 2\n");

	// ���� 3���� �����غ�����
	float weight = 1.5f;
	int weaponLv = 1;
	int baseAP = 10;

	// ���� ���ݷ��� ������Ű�� �Լ�
	// ���� �Լ��� ������ �� ������?
	printf("����ġ : %f, ���� : %d, �⺻ ���ݷ� : %d\n", weight, weaponLv, baseAP);
	UpgradeWeapon(&weaponLv, baseAP, &weight);
	printf("����ġ : %f, ���� : %d, �⺻ ���ݷ� : %d\n", weight, weaponLv, baseAP);

	// ����
	// �Լ��� �̿��ؼ� ���� �����Ѵ�. �ּҸ� �̿��ؼ� ���� ������ �� �ִ�.
	// ���� �ּҸ� ����ұ�? 1. �ܺ��� ���� �����ؾ� �� �� 2. �����;� �� ������ Ÿ���� �ʹ� Ŭ �� �ּҸ����� ������ �� �ִ�.(�迭, ����ü)

	// �������� ������ ������Ű�� �Լ��� ����� ������

	// �÷��̾��� ��ǥ�� �̵���Ű�� �Լ��� ����� ������
}

void Swap(int* a, int* b)
{
	int temp = *a;	  // a�� �ּ��ε�, �ּҷ� ���� ���� �������� ������(&) temp�� ����.5���ڰ� ����.
	*a = *b;          // *�����ͺ��� = �� : a�� �ּҿ� ���� �����ض�. 
	*b = temp;				  // *b : b�� �ּҿ� ����Ǿ� �ִ� ���� �ҷ��Ͷ�
	                  // 1.(*b -> 6) 2. *a = 6 3. numA = 6  
}

void IncreaseScore(int* score, int points)
{
    // GameScore �ּҸ� �޾ƿԽ��ϴ�. 
	// *�ּ� ���� = ��;  �ܺο� �ִ� GameScore ���� ����ȴ�.

	*score += points;
}

void IncreaseTemp(int score, int points)
{
	score += points;
}

void UpgradeWeapon(int* weaponLv, int baseAP, float* weight)
{
	// ������ 1���� ��Ų��.
	// ����ġ�� Ư�� �������� �����Ѵ�.

	*weaponLv += 4;
	if (*weaponLv % 5 == 0)
	{
		*weight = *weight * 1.5f;
	}
	
	printf("���� ���� ���ݷ� : %f\n", (*weaponLv) * (*weight) + baseAP);
}
