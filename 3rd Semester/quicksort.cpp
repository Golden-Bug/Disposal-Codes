
#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sys/time.h" 

struct timeval time_start, time_end;
                             struct timezone tz; 
                             long int cpu_time=0;
                             int t1=0,t2=0;



void quicksort(int number[25],int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
            i++;
         while(number[j]>number[pivot])
            j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);

   }
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
 


int main(){
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
                            /* printf("t2=%d",t2);*/
    cpu_time= ((time_end.tv_sec*1000000)+ time_end.tv_usec)-((time_start.tv_sec*1000000)+time_start.tv_usec);
   printf("Order of Sorted elements: ");
   for(i=0;i<count;i++)
      printf(" %d",number[i]);
     
	    printf("\nCPU time for your_function = %ld microsecs.= %9.6f secs.\n",cpu_time,(float)cpu_time/1000000);
 
      
   return 0;
}












