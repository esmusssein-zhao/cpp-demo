#include "order.h"
int Number_of_meals = 0;//�����ò�����
int main()
{
	loadTableInformation();
	loadMenuFile();
	mainMenu();
	system("pause");
	return 0;
}