#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sys/time.h" 

void printRandoms(int *, int);
int mpartition(int *, int);
int median(int *, int);
void quicksort(int *, int, int);
int partition(int *, int, int);


struct timeval time_start, time_end;
                             struct timezone tz; 
                             long int cpu_time=0;
                             int t1=0,t2=0;
                             

int main()
{
   int i, count, number[10000]= {0};
   
   printf("Enter the size of the list: ");
   scanf("%d", &count);

   printRandoms(number, count);
   srand(time(0));
 
    printf("The list is:\n");
    for(i = 0;i<count;++i)
    {
    	printf("%d\t",number[i]);
	}

    t1=gettimeofday(&time_start,&tz); 
    quicksort(number,0,count-1);
    t2=gettimeofday(&time_end,&tz); 
                            
    printf("Order of Sorted elements: ");
    for(i=0;i<count;i++)
      printf(" %d",number[i]);
     
     
    cpu_time= ((time_end.tv_sec*1000000)+ time_end.tv_usec)-((time_start.tv_sec*1000000)+time_start.tv_usec);
   
	    printf("\nCPU time for your_function = %ld microsecs.= %9.6f secs.\n",cpu_time,(float)cpu_time/1000000);
 
      
   return 0;
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

int partition(int *array, int down, int up)
{
	int i, j, k, pivot, size;
	size = sizeof(array)/sizeof(array[0]);
	printf("size of array: %d", size);
	k = mpartition(array, size);
	pivot = array[k];
	j = up+1;
	i = down-1;
   do
	{
	do
	{
	    i++;	
	}while(array[i] < pivot && i <= up);
	do
	{	
	   	j--;
	}while(array[j] > pivot);
	

	  if(i < j)
     {
        int temp = array[i];
		array[i] = array[j];
		array[j] = temp;	  	
	 }	
	}while(i < j);
	array[k] = array[j];
	array[j] = pivot;
	return j;
}


void quicksort(int *array, int down, int up)
{
  if(down < up)
  {
  	int pivot = partition(array, down, up);
  	quicksort(array, down, pivot-1);
  	quicksort(array, pivot+1, up);
  }
}



