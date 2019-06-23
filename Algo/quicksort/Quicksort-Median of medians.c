#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int findMedian(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
   {
       		key = arr[i];
       		j = i-1;
 
      		while (j >= 0 && arr[j] > key)
      		{
        	   arr[j+1] = arr[j];
        	   j = j-1;
       		}
       		arr[j+1] = key;
   }
    return arr[n/2];   
}
 

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int l, int r, int x)
{
 
    int i;
    for (i=l; i<r; i++)
        if (arr[i] == x)
           break;
    swap(&arr[i], &arr[r]);
 
   
    i = l;
    int j;
    for (j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
	swap(&arr[i], &arr[r]);
    return i;
}
 

int kthSmallest(int arr[], int l, int r, int k)
{
 
    if (k > 0 && k <= r - l + 1)
    {
        int n = r-l+1; 
 
        int y = (int)(ceil(n/5));
        int i, median[y]; 
        for (i=0; i<n/5; i++)
            median[i] = findMedian(arr+l+i*5, 5);
        if (i*5 < n) 
        {
            median[i] = findMedian(arr+l+i*5, n%5);
            i++;
        }
 
        int medOfMed = (i == 1)? median[i-1]:kthSmallest(median, 0, i-1, i/2);
 
        int pos = partition(arr, l, r, medOfMed);
 

        if (pos-l == k-1)
            return arr[pos];
        if (pos-l > k-1) 
		return kthSmallest(arr, l, pos-1, k);
 
        return kthSmallest(arr, pos+1, r, k-pos+l-1);
    }
 

    return 0;
}
 

void quickSort(int arr[], int l, int h)
{
    if (l < h)
    {
       
        int n = h-l+1;
 
     
        int med = kthSmallest(arr, l, h, n/2);
 
     
        int p = partition(arr, l, h, med);
 

        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, h);
    }
}


void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d    ",arr[i]);
    printf("\n");
}

int main()
{

    int i, count, number[50000];
    clock_t tic = clock();

    printf("\nEnter the number of elements you want randomly generated and sorted: ");
    scanf("%d",&count);
    
    
    int lower = 1, upper = 1000;
    srand(time(0));
    
    int k;
    for (k = 0; k < count; k++)
     {
        int num = (rand() % (upper - lower + 1)) + lower;
        number[k] = num;
     }
    
    quickSort(number,0,count-1);

   printf("The sorted elements are: ");
   for(i=0;i<count;i++)
      printf(" %d ",number[i]);
    
    
    
    clock_t toc = clock();

    printf("\nTime taken to sort the elements: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);

    return 0;
}
