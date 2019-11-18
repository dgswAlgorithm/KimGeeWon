#include <stdio.h>

int main()
{
	int data[] = { 0, 0, 1, 0, 1, 1, 0, 1, 1, 1 };
	int data_leng = sizeof(data) / sizeof(int);

	int check = 0;
	int finIndex = 0;

	int count[10] = { 0 };
	int fin[10] = { 0 };
	int j = 0;

	int beforeIndex = 0;
	int index = 0;
	
	

	for (int i = 0; i < data_leng; i++)
	{
		if (data[i] == 1)
		{
			count[index]++;
			fin[index]++;
		}
		else
		{
			fin[index] += count[beforeIndex];

			beforeIndex = index;
			index = i;
		}
		if (i == 9)
		{
			fin[index] += count[beforeIndex];
		}
	}

	for (int i = 0; i < data_leng; i++)
	{
		if (i == 9)
			break;

		if (fin[check] > fin[i + 1])
		{
			finIndex = check;
		}
		else
			check = i;
	}


	printf("변경 전: \n");
	for (int i = 0; i < data_leng; i++)
	{
		printf("%d, ", data[i]);
	}

	printf("\n\n");

	data[finIndex] = 1;

	printf("바뀐 index: %d\n", finIndex);
	printf("변경 후: \n");

	for (int i = 0; i < data_leng; i++)
	{
		printf("%d, ", data[i]);
	}

	printf("\n\n");
}