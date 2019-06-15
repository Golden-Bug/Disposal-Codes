#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sys/time.h" 

int mpartition(int *array, int size)
{
	int i =0, j, k, l, b[10000] = {0}, MoM, sum = 0;
	while((i+1)*5 < size)
	{
		j = i*5;
		k = j;
		int l = 0;
		while(l < 5 && j < size)
		{
			b[l] = array[j];
			j++;
			l++;
		}
		MoM = median(b, 5);
		sum += MoM;
		i++;
	}
	return MoM;
}

int median(int *array, int n)
{
	int i, key, j, Median;
	for(i = 1; i < 3; i++)
	{
		key = array[i];
		j = i - 1;
		while(j >= 0 && array[j] > key)
		{
			array[j+1] = array[j];
			j--;
		}
		array[j] = array[key];
	}
	Median = array[j];
	return Median;
}

void printRandoms(int *array, int n)
{
    int i;
    int lower=1;
    int upper=1000;
    for (i = 0; i < n; i++)
	 {
         array[i] = (rand() %(upper - lower + 1)) + lower;
    }
}

int main()
{
	int array[50], i, count, median;
	
	printf("Enter the size of the list: ");
   scanf("%d", &count);

   printRandoms(array, count);
   srand(time(0));
   
	printf("List is:\n");
	for(i=0; i<count; i++)
	  printf("%d\n",array[i]);
	
	median = mpartition(array, count);
	printf("median= %d",median);
	return 0;
}


