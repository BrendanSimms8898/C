#include <stdio.h>
#include <stdlib.h>
int Samenum(int a[], int size)
{
	int i;
	int j;
	for (i = 1; i < size; i++)
	{
		for (j = i + 1; j < size; j++)
		{
	int array[3];
			if (a[i] == a[j])
			{
				printf("Error, two numbers are the same\n"), 0;
			}
		}
	}
	return 1;
}

int biggest_num(int array[])
{
	int i;
	for ( i = 1; i < 4; i++){
		if (array[0] < array[i])
		{
			array[0] = array[i];
		}
	}
	printf("%d is the largest number\n", array[0]);
}
int main(int argc, char *argv[3]){
	int array[3] = {atoi(argv[1]), atoi(argv[2]), atoi(argv[3])};
	int i;
	int n;
	for (i = 1; i < 4; i++)
		n = atoi(argv[i]);
		array[i] = n;

	if (Samenum(array, argc))
	{
		biggest_num(array);
	}
}
