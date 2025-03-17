#pragma once

// 시작할 때 인벤토리 크기 4칸입니다.
// 특정 이벤트를 통해 최대 크기를 n칸으로 증가시키고 싶습니다.
// scanf()로 함수 구현하기 
//  1번. 인벤토리 최대 크기 증가   2번. 현재 인벤토리의 수 

// 전역 포인터 변수

#include <stdio.h>

extern int* inventoryPtr;

void ShowInventoryCount(int* inventory);

void IncreaseInventoryCount(int* inventory, int increaseCount);

void InventoryExample();
