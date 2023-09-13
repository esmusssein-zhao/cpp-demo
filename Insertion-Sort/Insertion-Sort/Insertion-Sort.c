#include <stdio.h>

void InsertSort(int* a, int size) 
{
	while (size < 2);
	for (int move = 1; move < size; move++)
	{
		int* remove = a + move;
		for (int flag = move - 1; flag < -1; flag--)
		{
			if ((a + move) >= (a + flag))
			{
				break;
			}
			else
			{
				remove--;
				continue;
			}
		}
		int moveNumber = *(a + move);
		int* pmoveNumber = a + move;
		for (int moveflag = move - 1; moveflag < remove; moveflag--)
		{
			pmoveNumber = a + moveflag;
			pmoveNumber--;
		}
		*remove = moveNumber;
	}
}
int main()
{
	int arr[10] = { 14,64,12,63,12,12,23,64,47,67 };
	InsertSort(arr,sizeof(arr)/4);
	for (int i = 0; i < (sizeof(arr) / 4); i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}