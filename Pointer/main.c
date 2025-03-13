/*
*  작성일 : 2025-03-13
*  작성자 : 김동훈
*  주제   : 포인터에 대한 이해
*/

/*
*  포인터가 무엇인가?
*  포인터는 주소이다.
*  변수의 정보 : 어떤 데이터를 저장하는가, 데이터의 크기는 어떻게 되는가?
*  컴퓨터의 입장 : 이름으로 변수를 호출한다. 주소를 기억한다.
*/

/*
*  변수의 선언
*  int number;   number 정수형 값을 저장할 수 있다. number의 주소를 갖고 있다.
*  주소연산자를 사용해서 변수에 들어있는 주소를 출력할 수 있다. &number;
*  주의할 점 : 주소 연산자는 변수가 선언되고 난 이후에 사용해야 한다.
* 
*  포인터 변수를 선언할 때 사용하는 기호
*  포인터 연산자 : int* pointerNumber;
*  포인터 변수가 선언되고 난 이후에 사용되는 기호
*  역참조 연산자 : *pointerNumber;
*/

/*
*  포인터 어디에서 사용하면 좋은가?
* 
*  컴퓨터 안에 메모리를 저장하는 영역. 메모리 주소로 저장을 하고 있었다.
*  주소를 알고 있으면 언제 어디서나 값을 가져올 수 있다.
*  
*  - 언제? 변수를 만들어 두고 사용을 했어야 한다. 프로그램 실행 중에 메모리를 할당하고 사용하는 방법 - 동적 할당
*  -어디서? 함수에서 변경된 값은 외부에 적용이 안된다. Call By Reference
*  
*/

/*
*   정리
*   컴퓨터의 주소를 사용 방법
*    1. 포인터 변수를 선언하는 방법   int* 포인터 변수 이름;
*    2.	변수로 부터 주소를 가져오는 방법 - 주소연산자  int number = 10;   &number;
*    3. 주소로 부터 값을 가져오는 방법  int*  numptr;     *numptr;
*/

#include <stdio.h>

// Call by Value vs Call by Reference

void CallValue(int number)
{
	number = 100;
}

void CallReference(int* numberPtr)
{
	//   ㅣ-Value     '=' R- Value
	//   int 주소          int
	// 16진수 0x019451ABC      10진수 정수
	// 두개의 타입이 다르다. 문법적으로 같게 만들어줘야 한다.
	*numberPtr = 100;
}

void SwapPreview(int numA, int numB)
{
	int temp; // 데이터를 임시 보관할 변수
	temp = numA;  // A 임시 보관
	numA = numB;  // A가 B의 값 변경
	numB = temp;  // B가 A의 값 변경

	// 미리 보기 형식
	printf("Swap을 하면 이런 결과가 나옵니다.\n");
	printf("변경된 numA의 값 : %d\n", numA);
	printf("변경된 numB의 값 : %d\n", numB);
}

// 외부에서 가져온 값을 변경하고 싶다.	-> 주소의 값을 변경한다.
void Swap(int* num1, int* num2)
{
	int* temp = num1;
	num1 = num2;
	num2 = temp;
}

int main()
{
	printf("포인터가 무엇인가? \n");

	// 실습 1. 포인터가 무엇인가
	int number = 10;
	printf("정수 출력 : %d\n", number);
    // 포인터를 출력
	printf("포인터 출력 : %p\n", &number);

	// 실습 2. 포인터 사용
	// * , &
	// 포인터 변수
	int* pointerNumber;    // 포인터 변수의 선언
	int num1 = 10;         // 변수의 선언 - 주소가 같이 저장
	pointerNumber = &num1; // 포인터 변수에 변수의 주소값을 대입
	printf("포인터 출력 : %p\n", pointerNumber);
	printf("정수 출력 : %d\n", *pointerNumber);

    // 연습문제. 포인터 실습
	
	// float형 변수를 선언하고 그 변수의 주소를 출력해보세요.
	// 주소에 들어있는 값을 역참조 연산자로 호출해보세요.

	float floatNum = 0.1f;
	float* floatPointer = &floatNum;
	// 주소값 출력
	// 0.1값을 가져오기;
	printf("주소값을 출력한다 : %p\n", &floatNum);
	printf("주소로 부터 값을 출력하기 : %f\n", *floatPointer);


	int num2 = 5;
	int* num2ptr = &num2;

	long long longNum = 100;
	long long* longNumptr = &longNum;

	printf("long long 예시\n");
	printf("주소로 부터 값을 출력한다 : %d\n", *longNumptr);

	char charNum = 'A';
	char* charNumptr = &charNum;

	printf("주소값을 출력한다 : %p\n", &charNum);
	printf("주소로 부터 값을 출력한다  : %c\n", *charNumptr);

	// Call by value , call by Reference

	printf("Call by Value, Call By Reference 예시\n");

	int exampleNumber = 10;
	int* exampleNumberPtr = &exampleNumber;
	CallValue(exampleNumber);
	printf("CallValue 실행 후 exampleNubmer의 값 : %d\n", exampleNumber);
	CallReference(exampleNumberPtr);
	printf("CallValue 실행 후 exampleNubmer의 값 : %d\n", exampleNumber);

	// swap을 구현해본다.
	// num1 , num2 , temp
	// 직전에 강화되어 있는 상태를 기억하고 싶습니다.
	// 롤백을 할 수 있도록 기능을 구현합니다.

	// 유저가 몰라야 하는 정보
	int weaponLv = 1;
	int weaponBaseAP = 10;
	int weight = 5;

	int weaponPower = weaponLv * weight + weaponBaseAP;

	int* saveWeaponData = &weaponPower;

	// 2가지 방식으로 weaponPower 접근을 할 수 있습니다.
	printf("무기 공격력 : %d\n", weaponPower);
	printf("무기 공격력 : %d\n", *saveWeaponData);


	// Swap 예제

	int numA = 50;
	int numB = 60;

	SwapPreview(numA, numB);

	printf("현재 numA, numB의 값\n");
	printf("numA : %d,  numB : %d\n", numA, numB);

	Swap(&numA, &numB);
	printf("Swap 실행 후 \n");
	printf("현재 numA, numB의 값\n");
	printf("numA : %d,  numB : %d\n", numA, numB);


}

