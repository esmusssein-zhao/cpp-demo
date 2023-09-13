#include "order.h"
extern int Number_of_meals;
void tableinformationStorage()
{
	//存储 
	FILE* fp;
	fp = fopen("餐桌信息.txt", "w");

	if (fp == NULL)
	{
		printf("文件打开失败!\n");
		exit(0);
	}
	fwrite(maxDesk, sizeof(struct desk), 200, fp);//把菜品名给存储
	fprintf(fp, "\n%d", Number_of_meals);
	fclose(fp);//先保存
}
//加载餐桌信息
void loadTableInformation()
{
	int i;
	FILE* fp;
	fp = fopen("餐桌信息.txt", "r");
	if (fp == NULL)
	{
		printf("文件打开失败!\n");
		exit(0);
	}
	fread(maxDesk, sizeof(struct desk), 200, fp);
	fscanf(fp, "%d", &Number_of_meals);//读正在用餐的餐桌
	fclose(fp);
}
void menuSave()
{
	//读取 
	FILE* fp;
	fp = fopen("菜单.txt", "w");

	if (fp == NULL)
	{
		printf("文件打开失败!\n");
		exit(0);
	}
	fwrite(dishInformation, sizeof(struct dish), 200, fp);//把菜品名给存储
	fprintf(fp, "\n%d", dishTotalNo);
	fclose(fp);//先保存
	printf("文件保存成功！\n");
}
//加载菜单文件
void loadMenuFile()
{
	int i;
	FILE* fp;
	system("cls");
	fp = fopen("菜单.txt", "r");
	if (fp == NULL)
	{
		printf("文件打开失败!\n");
		exit(0);
	}
	fread(dishInformation, sizeof(struct dish), 200, fp);
	fscanf(fp, "%d", &dishTotalNo);
	fclose(fp);
	printf("数据读取成功！！！\n");
	Sleep(1000);
}
void customerInterface()
{
	int sel, n, x, i, j = 0;
	int flag;
	system("cls");
	printf("----------------------------------------\n");
	printf("|         欢迎来到*********餐厅        |\n");
	printf("----------------------------------------\n");
	printf("今日菜品有如下：\n");
	menuOutPut();
	//餐桌信息 
	printf("----------------------------------------\n");
	printf("|****          1.点餐              ****|\n");
	printf("|****          2.查询              ****|\n");
	printf("----------------------------------------\n");
	printf("|****          3.加菜              ****|\n");
	printf("|****          4.减菜              ****|\n");
	printf("|****          5.返回              ****|\n");
	printf("----------------------------------------\n");
	printf("请输入你的选择【1 to 5】：");
	scanf("%d", &sel);
	//判断是否输入错误
	while (sel != 1 && sel != 2 && sel != 3 && sel != 4 && sel != 5)
	{
		printf("输入错误，请重新再输入：");
		scanf("%d", &sel);
	}
	if (sel == 1)
	{
		printf("请你输入你当前所坐桌的桌号【1~199】：");
	tt:	scanf("%d", &n);
		//判断一下输入的桌号是否正确
		if (maxDesk[n].peopleNoumber != 0)
		{
			printf("餐桌已被使用，请输入你自己所处的餐桌位：");
			goto tt;
		}
		//先将餐桌的用餐额赋值为0
		maxDesk[n].totalPrize = 0;
		//将餐桌的book[]数组赋值为0，给他标记 
		printf("请你输入用餐人数：");
		scanf("%d", &maxDesk[n].peopleNoumber);
		printf("----------------------------------------\n");
	here:	printf("请你输入点菜的编码：");
		scanf("%d", &maxDesk[n].userDishNo[j]);
		//判断是否有此编码 
		flag = 1;//假设为不存在的状态 
		for (i = 0; i < dishTotalNo; i++)
			if (maxDesk[n].userDishNo[j] == dishInformation[i].dishNo)
				flag = 0;//寻找到就改变状态
		if (flag == 1)
		{
			printf("菜单编号不存在！！！\n");
			printf("请重新你输入点菜的编码：");
			goto here;
		}
		for (i = 0; i < dishTotalNo; i++) //查找菜品的金额
			if (maxDesk[n].userDishNo[j] == dishInformation[i].dishNo)
				maxDesk[n].totalPrize += dishInformation[i].price;
	here1: printf("是否需要继续点餐？ 1/0\n");
		int choiseAgain = 0;
		scanf("%d", &choiseAgain);
		if (choiseAgain != 0 && choiseAgain != 1)
		{
			printf("输入有误，请重新输入！！！\n");
			goto here1;
		}
		if (choiseAgain == 1)
		{
			j++;
			goto here;
		}
		if (choiseAgain == 0);
		printf("你当前所需要支付的金额：%d\n", maxDesk[n].totalPrize);
		printf("是否选择提交订单【1 or 2】:");
		scanf("%d", &sel);
		while (sel != 1 && sel != 2)
		{
			printf("输入错误，请重新再输入：");
			scanf("%d", &sel);
		}
		if (sel == 1)
		{
			Number_of_meals++;
			customerInterface();
		}
		else
			customerInterface();
	}
	else if (sel == 2)
	{
		printf("输入当前的所在桌位：");
		scanf("%d", &n);
		printf("%5s", "餐桌号码");
		printf("%15s", "餐桌人数");
		printf("%13s", "点菜道数");
		printf("%11s", "需付金额");
		printf("%20s", "所点菜品");
		printf("\n");
		printf("%4d号", n);
		printf("%11d人", maxDesk[n].peopleNoumber);
		printf("%11d道", maxDesk[n].selectNo);
		printf("%11dRmb", maxDesk[n].totalPrize);
		//找菜名 
		flag = 1;//标记一下，用来美化一下界面 
		for (x = 0; x < maxDesk[n].selectNo; x++)
			for (i = 0; i < dishTotalNo; i++)
				if (maxDesk[n].userDishNo[x] == dishInformation[i].dishNo)
				{
					if (flag == 1)
					{
						printf("%20s", dishInformation[i].dishName);
						flag = 0;
					}
					else
						printf(" %s", dishInformation[i].dishName);
				}
		printf("\n");
	}
	else if (sel == 3 || sel == 4)//客人查询自己餐桌的信息 
	{
		printf("输入当前的所在桌位：");
		scanf("%d", &n);
		printf("%5s", "餐桌号码");
		printf("%15s", "餐桌人数");
		printf("%13s", "点菜道数");
		printf("%11s", "需付金额");
		printf("%20s", "所点菜品");
		printf("\n");
		printf("%4d号", n);
		printf("%11d人", maxDesk[n].peopleNoumber);
		printf("%11d道", maxDesk[n].selectNo);
		printf("%11dRmb", maxDesk[n].totalPrize);
		//找菜名 
		flag = 1;//标记一下，用来美化一下界面 
		for (x = 0; x < maxDesk[n].selectNo; x++)
			for (i = 0; i < dishTotalNo; i++)
				if (maxDesk[n].userDishNo[x] == dishInformation[i].dishNo)
				{
					if (flag == 1)
					{
						printf("%20s", dishInformation[i].dishName);
						flag = 0;
					}
					else
						printf(" %s", dishInformation[i].dishName);
				}
		printf("\n");
		switch (sel)
		{	//加菜 
		case 3:
		{
			int c;
			printf("请输入您想添加菜的编码：");
		aaa:	scanf("%d", &maxDesk[n].userDishNo[j]);
			//判断是否有此编码 
			flag = 1;//假设为不存在的状态 
			for (i = 0; i < dishTotalNo; i++)
				if (maxDesk[n].userDishNo[j] == dishInformation[i].dishNo)
					flag = 0;//寻找到就改变状态
			if (flag == 1)
			{
				printf("菜单编号不存在！！！\n");
				printf("请重新输入菜的编码：");
				goto aaa;
			}
			maxDesk[n].selectNo++;//菜数增加 
			for (i = 0; i < dishTotalNo; i++) //查找菜品的金额
				if (maxDesk[n].userDishNo[j] == dishInformation[i].dishNo)
					maxDesk[n].totalPrize += dishInformation[i].price;

			//保存
			printf("是否选择提交订单【1 or 2】:");
			scanf("%d", &sel);
			while (sel != 1 && sel != 2)
			{
				printf("输入错误，请重新再输入：");
				scanf("%d", &sel);
			}
			if (sel == 1)
				customerInterface();
		}
		break;
		case 4:	//减菜 
		{
			int code;
			printf("请输入你想删去菜品的编码：");
			scanf("%d", &code);
			flag = 1;//给标记看是否能找到
			for (i = 0; i < maxDesk[n].selectNo; i++)
			{
				if (code == maxDesk[n].userDishNo[i])
				{
					flag = 0;
					int j;
					for (j = i; j < maxDesk[n].selectNo; j++)
					{
						if (j < maxDesk[n].selectNo - 1)
							maxDesk[n].userDishNo[j] = maxDesk[n].userDishNo[j + 1];
						if (j == maxDesk[n].selectNo - 1)
							maxDesk[n].userDishNo[j] = 0;
					}
				}
			}
			if (flag == 1)
				printf("您的订单中尚未添加该菜\n");
			else
			{
				maxDesk[n].selectNo--;//所点菜品数减去一道
				//再把所需要的金额减去所删去的菜品对应的价格
				for (i = 0; i < dishTotalNo; i++) //查找菜品的金额
					if (code == dishInformation[i].dishNo)
						maxDesk[n].totalPrize -= dishInformation[i].price;
			}
			printf("是否选择提交订单【1 or 2】:");
			scanf("%d", &sel);
			while (sel != 1 && sel != 2)
			{
				printf("输入错误，请重新再输入：");
				scanf("%d", &sel);
			}
			if (sel == 1)
				customerInterface();
		}
		break;
		}
	}
	else if (sel == 5)
	{
		customerInterface();
	}
	system("pause");
}
void administratorMenu()
{
	int n, sel, i, j, zhuohao, x;
	int name, flag;//用来标志 
	int password;//用来输入密码用 
	system("cls");
	printf("----------------------------------\n");
	printf("|       欢迎来到管理者系统界面   |\n");
	printf("----------------------------------\n");
	printf("|          1.添加菜品            |\n"); //ok 
	printf("|          2.删除菜品            |\n"); //ok 
	printf("|          3.结账删除            |\n");
	printf("|          4.查看订单            |\n");
	printf("|          5.返回上级            |\n");
	printf("----------------------------------\n");
	printf("已有菜品%d个：\n", dishTotalNo);
	menuOutPut();
	printf("请输入管理员登入密码：");
	scanf("%d", &password);
	if (password == 8848)
	{
		printf("恭喜你登入成功！！！\n");
		printf("请输入你的选择【1-5】：");
		scanf("%d", &j);
		if (j == 1)//添加菜品 
		{
			printf("请输入今日可增加添做的菜品数：");
			scanf("%d", &n);
			//getchar();
			//循环输入
			for (i = 0; i < n; i++)
			{
			it:	printf("----------------------------------------\n");
				printf("请输入第%d个菜品编码：", i + 1);
				scanf("%d", &dishInformation[dishTotalNo].dishNo);
				//来判断一下编码是否以存在
				flag = 1;//表示不存在 
				for (x = 0; x < dishTotalNo; x++)
					if (dishInformation[dishTotalNo].dishNo == dishInformation[x].dishNo)
						flag = !flag;

				//如果存在则返回
				if (flag == 0)
				{
					printf("此编码已经被其它的菜品所征用!\n");
					goto it;
				}
				getchar();
				printf("请输入第%d个菜品名：", i + 1);
				gets(dishInformation[dishTotalNo].dishName);
				printf("请输入价格：");
				scanf("%d", &dishInformation[dishTotalNo].price);
				dishTotalNo++;
				//getchar();
			}
			//输入菜品后存储 
			menuSave();//保存一下输入的 

			printf("是否需要核对今日菜单【1 or 2】：");

			scanf("%d", &sel);

			while (sel != 1 && sel != 2)
			{
				printf("输入错误，请重新再输入：");
				scanf("%d", &sel);
			}

			if (sel == 1)
				menuOutPut();

		}
		else if (j == 2)//删除菜品
		{
			getchar();
			printf("----------------------------------------\n");
			printf("输入要删除的菜品编码：");
			scanf("%d", &name);
			for (i = 0; i < dishTotalNo; i++)
			{
				if (name == dishInformation[i].dishNo)
				{
					if (i == 199)
					{
						//如果是int 或者 double  直接给0
						//如果是char 字符串 直接给"" 空串
						dishInformation[i].price = 0;
						strcpy(dishInformation[i].dishName, "");
					}
					else
					{
						//把 i+1到199的同学所有信息整体往前赋值
						int j;//定义局部变量
						for (j = i + 1; j <= 199; j++)
							dishInformation[j - 1] = dishInformation[j];
					}
					dishTotalNo--;
					printf("数据已经删除!\n");
					system("pause");
					menuSave();//需要调用保存函数 
				}
			}
		}
		else if (j == 3)
		{
			printf("--------------------------------------\n");
			printf("请输入结账走人的桌号：");
			scanf("%d", &i);
			//判断输入的桌号是否未结账并用过餐 
			while (maxDesk[i].totalPrize == 0)
			{
				printf("为查询到此餐桌用餐情况，请重新查询：");
				scanf("%d", &i);
			}
			//显示一下餐桌，并询问是否删除
			printf("%5s", "餐桌号码");
			printf("%15s", "餐桌人数");
			printf("%13s", "点菜道数");
			printf("%11s", "需付金额");
			printf("%20s", "所点菜品");
			printf("\n");

			printf("%4d号", i);
			printf("%11d人", maxDesk[i].peopleNoumber);
			printf("%11d道", maxDesk[i].selectNo);
			printf("%11dRmb", maxDesk[i].totalPrize);
			//找菜名
			flag = 1;
			for (x = 0; x < maxDesk[i].selectNo; x++)
				for (n = 0; n < dishTotalNo; n++)
					if (maxDesk[i].userDishNo[x] == dishInformation[n].dishNo)
					{
						if (flag == 1)
						{
							printf("%20s", dishInformation[n].dishName);
							flag = 0;
						}
						else
							printf(" %s", dishInformation[n].dishName);
					}
			printf("\n");
			printf("是否需要删除[1 or 2]:");
			scanf("%d", &sel);
			while (sel != 1 && sel != 2)
			{
				printf("输入错误，请重新再输入：");
				scanf("%d", &sel);
			}
			if (sel == 1)
			{
				maxDesk[i].peopleNoumber = 0;
				maxDesk[i].totalPrize = 0;
				for (n = 0; n < maxDesk[i].selectNo; i++)
					maxDesk[i].userDishNo[n] = 0;
				maxDesk[i].selectNo = 0;
				Number_of_meals--;
			}
			tableinformationStorage();
			loadTableInformation();
		}
		else if (j == 4)
		{
			system("cls");
			printf("当前还有%d桌:\n", Number_of_meals);
			printf("%5s", "餐桌号码");
			printf("%15s", "餐桌人数");
			printf("%13s", "点菜道数");
			printf("%11s", "需付金额");
			printf("%20s", "所点菜品");
			printf("\n");
			printf("-------------------------------------------------------------------------\n");
			for (i = 0; i < 200; i++)
			{
				if (maxDesk[i].totalPrize != 0)
				{
					printf("%4d号", i);
					printf("%11d人", maxDesk[i].peopleNoumber);
					printf("%11d道", maxDesk[i].selectNo);
					printf("%11dRmb", maxDesk[i].totalPrize);
					//找菜名 
					flag = 1;
					for (x = 0; x < maxDesk[i].selectNo; x++)
						for (n = 0; n < dishTotalNo; n++)
							if (maxDesk[i].userDishNo[x] == dishInformation[n].dishNo)
							{
								if (flag == 1)
								{
									printf("%20s", dishInformation[n].dishName);
									flag = 0;
								}
								else
									printf(" %s", dishInformation[n].dishName);
							}
					printf("\n");
				}
			}
		}
		else if (j == 5)
		{
			mainMenu();
		}
		system("pause");
	}
	else
	{
		printf("密码输入错误\n");
		system("pause");
	}
}
void menuOutPut()
{
	int i;
	printf("%-15s", "编码");
	printf("%-15s", "菜名");
	printf("%-5s", "价格");
	printf("\n");

	for (i = 0; i < dishTotalNo; i++)
	{
		printf("%-15d", dishInformation[i].dishNo);
		printf("%-15s", dishInformation[i].dishName);
		printf("%-5d", dishInformation[i].price);
		printf("\n");
	}
	system("pause");
}
void mainMenu()
{
	int select;
	system("cls");
	printf("----------------------------------------\n");
	printf("|         欢迎来到*********餐厅        |\n");
	printf("----------------------------------------\n");
	printf("请问你是餐厅管理者还是点餐者【1 or 2】：\n");
	scanf("%d", &select);
	//选择是管理员还是顾客
	//判断是否输入错误 
	while (select != 1 && select != 2)
	{
		printf("输入错误，请重新再输入：");
		scanf("%d", &select);
	}
	switch (select)
	{
	case 1:
		administratorMenu(); 
		mainMenu(); 
		break;
	case 2:
		customerInterface(); 
		mainMenu(); 
		break;
	}
}
