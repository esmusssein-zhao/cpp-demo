#include "order.h"
int Number_of_meals = 0;//正在用餐桌数
int main()
{
	loadTableInformation();
	loadMenuFile();
	mainMenu();
	system("pause");
	return 0;
}