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
int dishTotalNo; // 今日菜品数

struct desk
{
	int peopleNoumber;
	int userDishNo[50];//个人菜单的里的编码 
	int selectNo;//点菜的数量 
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
