#include "order.h"
extern int Number_of_meals;
void tableinformationStorage()
{
	//�洢 
	FILE* fp;
	fp = fopen("������Ϣ.txt", "w");

	if (fp == NULL)
	{
		printf("�ļ���ʧ��!\n");
		exit(0);
	}
	fwrite(maxDesk, sizeof(struct desk), 200, fp);//�Ѳ�Ʒ�����洢
	fprintf(fp, "\n%d", Number_of_meals);
	fclose(fp);//�ȱ���
}
//���ز�����Ϣ
void loadTableInformation()
{
	int i;
	FILE* fp;
	fp = fopen("������Ϣ.txt", "r");
	if (fp == NULL)
	{
		printf("�ļ���ʧ��!\n");
		exit(0);
	}
	fread(maxDesk, sizeof(struct desk), 200, fp);
	fscanf(fp, "%d", &Number_of_meals);//�������ò͵Ĳ���
	fclose(fp);
}
void menuSave()
{
	//��ȡ 
	FILE* fp;
	fp = fopen("�˵�.txt", "w");

	if (fp == NULL)
	{
		printf("�ļ���ʧ��!\n");
		exit(0);
	}
	fwrite(dishInformation, sizeof(struct dish), 200, fp);//�Ѳ�Ʒ�����洢
	fprintf(fp, "\n%d", dishTotalNo);
	fclose(fp);//�ȱ���
	printf("�ļ�����ɹ���\n");
}
//���ز˵��ļ�
void loadMenuFile()
{
	int i;
	FILE* fp;
	system("cls");
	fp = fopen("�˵�.txt", "r");
	if (fp == NULL)
	{
		printf("�ļ���ʧ��!\n");
		exit(0);
	}
	fread(dishInformation, sizeof(struct dish), 200, fp);
	fscanf(fp, "%d", &dishTotalNo);
	fclose(fp);
	printf("���ݶ�ȡ�ɹ�������\n");
	Sleep(1000);
}
void customerInterface()
{
	int sel, n, x, i, j = 0;
	int flag;
	system("cls");
	printf("----------------------------------------\n");
	printf("|         ��ӭ����*********����        |\n");
	printf("----------------------------------------\n");
	printf("���ղ�Ʒ�����£�\n");
	menuOutPut();
	//������Ϣ 
	printf("----------------------------------------\n");
	printf("|****          1.���              ****|\n");
	printf("|****          2.��ѯ              ****|\n");
	printf("----------------------------------------\n");
	printf("|****          3.�Ӳ�              ****|\n");
	printf("|****          4.����              ****|\n");
	printf("|****          5.����              ****|\n");
	printf("----------------------------------------\n");
	printf("���������ѡ��1 to 5����");
	scanf("%d", &sel);
	//�ж��Ƿ��������
	while (sel != 1 && sel != 2 && sel != 3 && sel != 4 && sel != 5)
	{
		printf("������������������룺");
		scanf("%d", &sel);
	}
	if (sel == 1)
	{
		printf("���������㵱ǰ�����������š�1~199����");
	tt:	scanf("%d", &n);
		//�ж�һ������������Ƿ���ȷ
		if (maxDesk[n].peopleNoumber != 0)
		{
			printf("�����ѱ�ʹ�ã����������Լ������Ĳ���λ��");
			goto tt;
		}
		//�Ƚ��������òͶֵΪ0
		maxDesk[n].totalPrize = 0;
		//��������book[]���鸳ֵΪ0��������� 
		printf("���������ò�������");
		scanf("%d", &maxDesk[n].peopleNoumber);
		printf("----------------------------------------\n");
	here:	printf("���������˵ı��룺");
		scanf("%d", &maxDesk[n].userDishNo[j]);
		//�ж��Ƿ��д˱��� 
		flag = 1;//����Ϊ�����ڵ�״̬ 
		for (i = 0; i < dishTotalNo; i++)
			if (maxDesk[n].userDishNo[j] == dishInformation[i].dishNo)
				flag = 0;//Ѱ�ҵ��͸ı�״̬
		if (flag == 1)
		{
			printf("�˵���Ų����ڣ�����\n");
			printf("�������������˵ı��룺");
			goto here;
		}
		for (i = 0; i < dishTotalNo; i++) //���Ҳ�Ʒ�Ľ��
			if (maxDesk[n].userDishNo[j] == dishInformation[i].dishNo)
				maxDesk[n].totalPrize += dishInformation[i].price;
	here1: printf("�Ƿ���Ҫ������ͣ� 1/0\n");
		int choiseAgain = 0;
		scanf("%d", &choiseAgain);
		if (choiseAgain != 0 && choiseAgain != 1)
		{
			printf("�����������������룡����\n");
			goto here1;
		}
		if (choiseAgain == 1)
		{
			j++;
			goto here;
		}
		if (choiseAgain == 0);
		printf("�㵱ǰ����Ҫ֧���Ľ�%d\n", maxDesk[n].totalPrize);
		printf("�Ƿ�ѡ���ύ������1 or 2��:");
		scanf("%d", &sel);
		while (sel != 1 && sel != 2)
		{
			printf("������������������룺");
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
		printf("���뵱ǰ��������λ��");
		scanf("%d", &n);
		printf("%5s", "��������");
		printf("%15s", "��������");
		printf("%13s", "��˵���");
		printf("%11s", "�踶���");
		printf("%20s", "�����Ʒ");
		printf("\n");
		printf("%4d��", n);
		printf("%11d��", maxDesk[n].peopleNoumber);
		printf("%11d��", maxDesk[n].selectNo);
		printf("%11dRmb", maxDesk[n].totalPrize);
		//�Ҳ��� 
		flag = 1;//���һ�£���������һ�½��� 
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
	else if (sel == 3 || sel == 4)//���˲�ѯ�Լ���������Ϣ 
	{
		printf("���뵱ǰ��������λ��");
		scanf("%d", &n);
		printf("%5s", "��������");
		printf("%15s", "��������");
		printf("%13s", "��˵���");
		printf("%11s", "�踶���");
		printf("%20s", "�����Ʒ");
		printf("\n");
		printf("%4d��", n);
		printf("%11d��", maxDesk[n].peopleNoumber);
		printf("%11d��", maxDesk[n].selectNo);
		printf("%11dRmb", maxDesk[n].totalPrize);
		//�Ҳ��� 
		flag = 1;//���һ�£���������һ�½��� 
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
		{	//�Ӳ� 
		case 3:
		{
			int c;
			printf("������������Ӳ˵ı��룺");
		aaa:	scanf("%d", &maxDesk[n].userDishNo[j]);
			//�ж��Ƿ��д˱��� 
			flag = 1;//����Ϊ�����ڵ�״̬ 
			for (i = 0; i < dishTotalNo; i++)
				if (maxDesk[n].userDishNo[j] == dishInformation[i].dishNo)
					flag = 0;//Ѱ�ҵ��͸ı�״̬
			if (flag == 1)
			{
				printf("�˵���Ų����ڣ�����\n");
				printf("����������˵ı��룺");
				goto aaa;
			}
			maxDesk[n].selectNo++;//�������� 
			for (i = 0; i < dishTotalNo; i++) //���Ҳ�Ʒ�Ľ��
				if (maxDesk[n].userDishNo[j] == dishInformation[i].dishNo)
					maxDesk[n].totalPrize += dishInformation[i].price;

			//����
			printf("�Ƿ�ѡ���ύ������1 or 2��:");
			scanf("%d", &sel);
			while (sel != 1 && sel != 2)
			{
				printf("������������������룺");
				scanf("%d", &sel);
			}
			if (sel == 1)
				customerInterface();
		}
		break;
		case 4:	//���� 
		{
			int code;
			printf("����������ɾȥ��Ʒ�ı��룺");
			scanf("%d", &code);
			flag = 1;//����ǿ��Ƿ����ҵ�
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
				printf("���Ķ�������δ��Ӹò�\n");
			else
			{
				maxDesk[n].selectNo--;//�����Ʒ����ȥһ��
				//�ٰ�����Ҫ�Ľ���ȥ��ɾȥ�Ĳ�Ʒ��Ӧ�ļ۸�
				for (i = 0; i < dishTotalNo; i++) //���Ҳ�Ʒ�Ľ��
					if (code == dishInformation[i].dishNo)
						maxDesk[n].totalPrize -= dishInformation[i].price;
			}
			printf("�Ƿ�ѡ���ύ������1 or 2��:");
			scanf("%d", &sel);
			while (sel != 1 && sel != 2)
			{
				printf("������������������룺");
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
	int name, flag;//������־ 
	int password;//�������������� 
	system("cls");
	printf("----------------------------------\n");
	printf("|       ��ӭ����������ϵͳ����   |\n");
	printf("----------------------------------\n");
	printf("|          1.��Ӳ�Ʒ            |\n"); //ok 
	printf("|          2.ɾ����Ʒ            |\n"); //ok 
	printf("|          3.����ɾ��            |\n");
	printf("|          4.�鿴����            |\n");
	printf("|          5.�����ϼ�            |\n");
	printf("----------------------------------\n");
	printf("���в�Ʒ%d����\n", dishTotalNo);
	menuOutPut();
	printf("���������Ա�������룺");
	scanf("%d", &password);
	if (password == 8848)
	{
		printf("��ϲ�����ɹ�������\n");
		printf("���������ѡ��1-5����");
		scanf("%d", &j);
		if (j == 1)//��Ӳ�Ʒ 
		{
			printf("��������տ����������Ĳ�Ʒ����");
			scanf("%d", &n);
			//getchar();
			//ѭ������
			for (i = 0; i < n; i++)
			{
			it:	printf("----------------------------------------\n");
				printf("�������%d����Ʒ���룺", i + 1);
				scanf("%d", &dishInformation[dishTotalNo].dishNo);
				//���ж�һ�±����Ƿ��Դ���
				flag = 1;//��ʾ������ 
				for (x = 0; x < dishTotalNo; x++)
					if (dishInformation[dishTotalNo].dishNo == dishInformation[x].dishNo)
						flag = !flag;

				//��������򷵻�
				if (flag == 0)
				{
					printf("�˱����Ѿ��������Ĳ�Ʒ������!\n");
					goto it;
				}
				getchar();
				printf("�������%d����Ʒ����", i + 1);
				gets(dishInformation[dishTotalNo].dishName);
				printf("������۸�");
				scanf("%d", &dishInformation[dishTotalNo].price);
				dishTotalNo++;
				//getchar();
			}
			//�����Ʒ��洢 
			menuSave();//����һ������� 

			printf("�Ƿ���Ҫ�˶Խ��ղ˵���1 or 2����");

			scanf("%d", &sel);

			while (sel != 1 && sel != 2)
			{
				printf("������������������룺");
				scanf("%d", &sel);
			}

			if (sel == 1)
				menuOutPut();

		}
		else if (j == 2)//ɾ����Ʒ
		{
			getchar();
			printf("----------------------------------------\n");
			printf("����Ҫɾ���Ĳ�Ʒ���룺");
			scanf("%d", &name);
			for (i = 0; i < dishTotalNo; i++)
			{
				if (name == dishInformation[i].dishNo)
				{
					if (i == 199)
					{
						//�����int ���� double  ֱ�Ӹ�0
						//�����char �ַ��� ֱ�Ӹ�"" �մ�
						dishInformation[i].price = 0;
						strcpy(dishInformation[i].dishName, "");
					}
					else
					{
						//�� i+1��199��ͬѧ������Ϣ������ǰ��ֵ
						int j;//����ֲ�����
						for (j = i + 1; j <= 199; j++)
							dishInformation[j - 1] = dishInformation[j];
					}
					dishTotalNo--;
					printf("�����Ѿ�ɾ��!\n");
					system("pause");
					menuSave();//��Ҫ���ñ��溯�� 
				}
			}
		}
		else if (j == 3)
		{
			printf("--------------------------------------\n");
			printf("������������˵����ţ�");
			scanf("%d", &i);
			//�ж�����������Ƿ�δ���˲��ù��� 
			while (maxDesk[i].totalPrize == 0)
			{
				printf("Ϊ��ѯ���˲����ò�����������²�ѯ��");
				scanf("%d", &i);
			}
			//��ʾһ�²�������ѯ���Ƿ�ɾ��
			printf("%5s", "��������");
			printf("%15s", "��������");
			printf("%13s", "��˵���");
			printf("%11s", "�踶���");
			printf("%20s", "�����Ʒ");
			printf("\n");

			printf("%4d��", i);
			printf("%11d��", maxDesk[i].peopleNoumber);
			printf("%11d��", maxDesk[i].selectNo);
			printf("%11dRmb", maxDesk[i].totalPrize);
			//�Ҳ���
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
			printf("�Ƿ���Ҫɾ��[1 or 2]:");
			scanf("%d", &sel);
			while (sel != 1 && sel != 2)
			{
				printf("������������������룺");
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
			printf("��ǰ����%d��:\n", Number_of_meals);
			printf("%5s", "��������");
			printf("%15s", "��������");
			printf("%13s", "��˵���");
			printf("%11s", "�踶���");
			printf("%20s", "�����Ʒ");
			printf("\n");
			printf("-------------------------------------------------------------------------\n");
			for (i = 0; i < 200; i++)
			{
				if (maxDesk[i].totalPrize != 0)
				{
					printf("%4d��", i);
					printf("%11d��", maxDesk[i].peopleNoumber);
					printf("%11d��", maxDesk[i].selectNo);
					printf("%11dRmb", maxDesk[i].totalPrize);
					//�Ҳ��� 
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
		printf("�����������\n");
		system("pause");
	}
}
void menuOutPut()
{
	int i;
	printf("%-15s", "����");
	printf("%-15s", "����");
	printf("%-5s", "�۸�");
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
	printf("|         ��ӭ����*********����        |\n");
	printf("----------------------------------------\n");
	printf("�������ǲ��������߻��ǵ���ߡ�1 or 2����\n");
	scanf("%d", &select);
	//ѡ���ǹ���Ա���ǹ˿�
	//�ж��Ƿ�������� 
	while (select != 1 && select != 2)
	{
		printf("������������������룺");
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
