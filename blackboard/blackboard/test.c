#define _CRT_SECURE_NO_WARNINGS 1

#include<math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void requestLineInfo(char* buf, int len)
{
	int flagLen = 0;
	int flag = 0;
	char method[5];
	char url[20];
	char http[10];
	memset(method, 0, sizeof(method));
	memset(url, 0, sizeof(url));
	memset(http, 0, sizeof(http));
	//请求方法
	while (!isspace(buf[flagLen]) && buf[flagLen] != '\0')
	{
		method[flag++] = buf[flagLen++];
	}
	flag = 0; 
	++flagLen;
	while (!isspace(buf[flagLen]) && buf[flagLen] != '\0')
	{
		url[flag++] = buf[flagLen++];
	}
	flag = 0;
	++flagLen;
	while (!isspace(buf[flagLen]) && buf[flagLen] != '\0')
	{
		http[flag++] = buf[flagLen++];
	}
	printf("请求方法为：%s\n", method);
	printf("请求方法为：%s\n", url);
	printf("请求方法为：%s\n", http);
}

void requestHeadInfo(char* buf, int len)
{
	int flag = 0;
	char infoName[20];
	char info[100];
	memset(infoName, 0, sizeof(infoName));
	memset(info, 0, sizeof(info));
	while (flag<len && buf[flag] != ':')
	{
			infoName[flag] = buf[flag];
			++flag;
	}
	int flagLen = 0;
	++flag;
	while (flag < len)
	{
		info[flagLen++] = buf[flag++];
	}
	printf("name:%s    ", infoName);
	printf("info:%s    ", info);

}

void Serial_SendString(char* String)
{
	while (*String != '\0')
	{
		//Serial_SendByte(*String);
		printf("%c\n", *String);
		++String;
	}

}

void tss(int* a)
{
	int n = sizeof(a) / sizeof(a[0]);
	printf("%d\n", n);
}
#define change(a,b) a=a^b;b=a^b;a=a^b


typedef enum
{
	a = 0,
	b,
	c,

}aa;

power(a, b)
{
	printf("%d,%d", a, b);
}

power2(a, b)
double; int;
{
	printf("%d,%d", a, b);
}
//char* getInfo(char* arr, int len)
//{
//	if (!header(arr))
//		error();
//	int size = arr[2];
//
//
//
//}


int main()
{
	char a = 3;
	int b = a;
	printf("%d\n", b);
	//int a[] = { 1,24,5,6,7,8,9 };
	//int n = sizeof(a);
	//printf("%d\n", n);
	//tss(a);
	//char buf[100] = { "User-Agent: Mozilla/5.0 (Windows NT 5.1; rv:10.0.2) Gecko/20100101 Firefox/10.0.2" };
	//requestHeadInfo(buf, sizeof(buf));
	return 0;
}





//void test(int arr[])
//{
//	printf("%d", sizeof(arr) / sizeof(arr[0]));
//}
//enum colar
//{
//	red=1,
//	green=2,
//	blue=2
//};
//union 
//{
//	int a1;
//	char b1;
//}a;
//#include <stdio.h>
//union A
//{
//	unsigned int a;
//	char b;
//};
//void my_strcpy(char* lhs, const char* rhs)
//{
//	char* l = lhs;
//	while (*lhs++ = *rhs++)
//	{
//		;
//	}
//	lhs = l;
//}
	/*char* rhs = "hello world!";
	char* lhs = malloc(20);
	my_strcpy(lhs, rhs);
	printf("%s", lhs);
	free(lhs);*/
	/*union A a1;
	a1.a = 1;
	printf("%d", a1.b);*/
	/*a.a1 = 10;
	a.b1 = 1;
	printf("%d", a.b1);*/
	/*
	int arr[5] = { 1,2,3,4,5 };
	int* a = arr + 1;
	int* c = 1 + arr;
	int b = 1[arr];
	int d = arr[1];
	printf("%d",b);
	printf("\n");
	printf("%d",d);
	*/
	/*const int x = 1;
	int* p = &x;
	const int* cp = &x;
	return 0;*/
	//int i;
	//int count = 0;
	//float sum = 0;
	//float average = 0;
	//float A[4];
	//for (i = 0; i < 4; i++)
	//{
	//	scanf_s("请输入数字:%f", &A[i]);
	//}
	//	
	//for (i = 0; i < 4; i++)
	//{
	//	sum += A[i];
	//}
	//average = sum / 4;
	//for (i = 0; i < 4; i++)
	//{
	//	if (A[i] > average)
	//	count++;
	//}
	//	
	//printf("平均值是: %.2f\n",average);
	//printf("大于平均值的数有%d个",count);
	//char a[2] = { ' ',' '};
	//printf(" %c", a[0], a[2]);
	//unsigned u = 10;
	//int a = -84;
	//printf("%d", a + u);
	//return 0;
	/*int arr[4] = { 1 };
	test(arr);*/
	/*char arr1[] = "abc";
	char arr2[] = "abc";
	if (arr1 == arr2)
	{
		printf("same");
	}
	else
	{
		printf("different");
	}
	size_t*/