/*
*  �ۼ��� : 2025-03-21
*  �ۼ��� : �赿��
*  ����   : ����ü�� ���� �����
*/

/*
*  ������ - �ּҸ� �̿��� �� �ְԵǾ���. 
*  1. ������ ���� �����ϴ� ��           int* numptr;
   2. ������ ���� �ּҸ� ȣ���ϴ� ��    int num; &num;
   3. �ּҿ��� ���� �����ϴ� ��		 *numptr;
*/	

/*
*  �����Ϳ� ������ 
*  �������� ���� ��� : �ڷ����� ũ�⸸ŭ �����Ѵ�.
*  �迭              : (������ �ּ� + i) i��° �ּҸ� ȣ���ϴ� ��
*/

/*
*  ����ü : ����� ���� �ڷ��� 
*/

/*
*  ���ӿ� ����� �Լ� ���� 
*  Player -  Item - Enemy 
*/

 /*
 *  ��� 
    1. �̵��� �����Ѵ�.
    2. ��ȣ�ۿ� ����
 */

#include "Player.h"

int main()
{
    // �÷��̾��� �⺻ �����͸� ����

    COORD playerPos = { 0 ,0 };
    Player player = {"���谡", playerPos };       // �̸�, ��ǥ

    COORD itemAPos = { 5, 5 };
    Item  itemA = { "������A", itemAPos, false };  // �̸�, ��ǥ, ȹ�� ����

    COORD itemBPos = { 10, 10 };
    Item itemB = { "������B", itemBPos, false };

    Item GameItems[2] = { itemA, itemB };         // item�迭�� �����ͼ� ����ϴ� �Լ�



    while (true)
    {
        system("cls");
        GetPlayerInput(&player);
        ShowPlayer(&player);

        GoXYCOORD(itemAPos);
        printf("��");

        InteractWithItem(&player, &GameItems[0]);   // �ּҿ� �����Ͱ� ������� �ʾҴ�. ->  Call by Value, Ref
        //ShowPlayerItemInfo(&itemA);
        ShowPlayerAllItemInfo(GameItems, 2);

        // �迭�� �Ű������� �޾ƿͼ� ������ �����Ϳ� �����Ѵ�.


        Sleep(100);
    }
}