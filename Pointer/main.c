/*
*  �ۼ��� : 2025-03-13
*  �ۼ��� : �赿��
*  ����   : �����Ϳ� ���� ����
*/

/*
*  �����Ͱ� �����ΰ�?
*  �����ʹ� �ּ��̴�.
*  ������ ���� : � �����͸� �����ϴ°�, �������� ũ��� ��� �Ǵ°�?
*  ��ǻ���� ���� : �̸����� ������ ȣ���Ѵ�. �ּҸ� ����Ѵ�.
*/

/*
*  ������ ����
*  int number;   number ������ ���� ������ �� �ִ�. number�� �ּҸ� ���� �ִ�.
*  �ּҿ����ڸ� ����ؼ� ������ ����ִ� �ּҸ� ����� �� �ִ�. &number;
*  ������ �� : �ּ� �����ڴ� ������ ����ǰ� �� ���Ŀ� ����ؾ� �Ѵ�.
* 
*  ������ ������ ������ �� ����ϴ� ��ȣ
*  ������ ������ : int* pointerNumber;
*  ������ ������ ����ǰ� �� ���Ŀ� ���Ǵ� ��ȣ
*  ������ ������ : *pointerNumber;
*/

/*
*  ������ ��𿡼� ����ϸ� ������?
* 
*  ��ǻ�� �ȿ� �޸𸮸� �����ϴ� ����. �޸� �ּҷ� ������ �ϰ� �־���.
*  �ּҸ� �˰� ������ ���� ��𼭳� ���� ������ �� �ִ�.
*  
*  - ����? ������ ����� �ΰ� ����� �߾�� �Ѵ�. ���α׷� ���� �߿� �޸𸮸� �Ҵ��ϰ� ����ϴ� ��� - ���� �Ҵ�
*  -���? �Լ����� ����� ���� �ܺο� ������ �ȵȴ�. Call By Reference
*  
*/

/*
*   ����
*   ��ǻ���� �ּҸ� ��� ���
*    1. ������ ������ �����ϴ� ���   int* ������ ���� �̸�;
*    2.	������ ���� �ּҸ� �������� ��� - �ּҿ�����  int number = 10;   &number;
*    3. �ּҷ� ���� ���� �������� ���  int*  numptr;     *numptr;
*/

#include <stdio.h>

// Call by Value vs Call by Reference

void CallValue(int number)
{
	number = 100;
}

void CallReference(int* numberPtr)
{
	//   ��-Value     '=' R- Value
	//   int �ּ�          int
	// 16���� 0x019451ABC      10���� ����
	// �ΰ��� Ÿ���� �ٸ���. ���������� ���� �������� �Ѵ�.
	*numberPtr = 100;
}

void SwapPreview(int numA, int numB)
{
	int temp; // �����͸� �ӽ� ������ ����
	temp = numA;  // A �ӽ� ����
	numA = numB;  // A�� B�� �� ����
	numB = temp;  // B�� A�� �� ����

	// �̸� ���� ����
	printf("Swap�� �ϸ� �̷� ����� ���ɴϴ�.\n");
	printf("����� numA�� �� : %d\n", numA);
	printf("����� numB�� �� : %d\n", numB);
}

// �ܺο��� ������ ���� �����ϰ� �ʹ�.	-> �ּ��� ���� �����Ѵ�.
void Swap(int* num1, int* num2)
{
	int* temp = num1;
	num1 = num2;
	num2 = temp;
}

int main()
{
	printf("�����Ͱ� �����ΰ�? \n");

	// �ǽ� 1. �����Ͱ� �����ΰ�
	int number = 10;
	printf("���� ��� : %d\n", number);
    // �����͸� ���
	printf("������ ��� : %p\n", &number);

	// �ǽ� 2. ������ ���
	// * , &
	// ������ ����
	int* pointerNumber;    // ������ ������ ����
	int num1 = 10;         // ������ ���� - �ּҰ� ���� ����
	pointerNumber = &num1; // ������ ������ ������ �ּҰ��� ����
	printf("������ ��� : %p\n", pointerNumber);
	printf("���� ��� : %d\n", *pointerNumber);

    // ��������. ������ �ǽ�
	
	// float�� ������ �����ϰ� �� ������ �ּҸ� ����غ�����.
	// �ּҿ� ����ִ� ���� ������ �����ڷ� ȣ���غ�����.

	float floatNum = 0.1f;
	float* floatPointer = &floatNum;
	// �ּҰ� ���
	// 0.1���� ��������;
	printf("�ּҰ��� ����Ѵ� : %p\n", &floatNum);
	printf("�ּҷ� ���� ���� ����ϱ� : %f\n", *floatPointer);


	int num2 = 5;
	int* num2ptr = &num2;

	long long longNum = 100;
	long long* longNumptr = &longNum;

	printf("long long ����\n");
	printf("�ּҷ� ���� ���� ����Ѵ� : %d\n", *longNumptr);

	char charNum = 'A';
	char* charNumptr = &charNum;

	printf("�ּҰ��� ����Ѵ� : %p\n", &charNum);
	printf("�ּҷ� ���� ���� ����Ѵ�  : %c\n", *charNumptr);

	// Call by value , call by Reference

	printf("Call by Value, Call By Reference ����\n");

	int exampleNumber = 10;
	int* exampleNumberPtr = &exampleNumber;
	CallValue(exampleNumber);
	printf("CallValue ���� �� exampleNubmer�� �� : %d\n", exampleNumber);
	CallReference(exampleNumberPtr);
	printf("CallValue ���� �� exampleNubmer�� �� : %d\n", exampleNumber);

	// swap�� �����غ���.
	// num1 , num2 , temp
	// ������ ��ȭ�Ǿ� �ִ� ���¸� ����ϰ� �ͽ��ϴ�.
	// �ѹ��� �� �� �ֵ��� ����� �����մϴ�.

	// ������ ����� �ϴ� ����
	int weaponLv = 1;
	int weaponBaseAP = 10;
	int weight = 5;

	int weaponPower = weaponLv * weight + weaponBaseAP;

	int* saveWeaponData = &weaponPower;

	// 2���� ������� weaponPower ������ �� �� �ֽ��ϴ�.
	printf("���� ���ݷ� : %d\n", weaponPower);
	printf("���� ���ݷ� : %d\n", *saveWeaponData);


	// Swap ����

	int numA = 50;
	int numB = 60;

	SwapPreview(numA, numB);

	printf("���� numA, numB�� ��\n");
	printf("numA : %d,  numB : %d\n", numA, numB);

	Swap(&numA, &numB);
	printf("Swap ���� �� \n");
	printf("���� numA, numB�� ��\n");
	printf("numA : %d,  numB : %d\n", numA, numB);


}

