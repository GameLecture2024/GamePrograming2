#pragma once
#include <stdio.h>

void ShowLecture();

void Swap(int* a, int* b); // 함수의 인자에 어떤 경우에 포인터를 사용해야 할까? 

void IncreaseScore(int* score, int points); // score 주소, points 값

void IncreaseTemp(int score, int points);

void UpgradeWeapon(int* weaponLv, int baseAP, float* weight);

// 직접 함수이름을 만들어서 구현해보세요