#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <windows.h>
#include <string.h>

struct dish
{
	int dishNo;
	char dishName[1000];
	int price;
}dishInformation[200];
int dishTotalNo; // ���ղ�Ʒ��

struct desk
{
	int peopleNoumber;
	int userDishNo[50];//���˲˵�����ı��� 
	int selectNo;//��˵����� 
	int totalPrize;
}maxDesk[200];

void tableinformationStorage();
void loadTableInformation();
void menuSave();
void loadMenuFile();
void customerInterface();
void administratorMenu();
void mainMenu();
void menuOutPut();
