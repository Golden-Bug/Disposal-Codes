#include<stdio.h>
	int a[50], i, n;
int heapSize;

int MaxHeapify(int* A, int i)
{
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  int largest;

  if(l <= heapSize && A[l] > A[i])
    largest = l;
  else
    largest = i;
  if(r <= heapSize && A[r] > A[largest])
    largest = r;
  if(largest != i)
    {
      int temp = A[i];
      A[i] = A[largest];
      A[largest] = temp;
      MaxHeapify(A, largest);
    }
    return 0;
}

int BuildMaxHeap(int* A)
{
  heapSize = n - 1;
  int i;
  for(i = (n - 1) / 2; i >= 0; i--)
    MaxHeapify(A, i);
    return 0;
}

void HeapSort(int* A)
{
  BuildMaxHeap(A);
  int i;
  for(i = n - 1; i > 0; i--)
    {
      int temp = A[heapSize];
      A[heapSize] = A[0];
      A[0] = temp;
      heapSize--;
      MaxHeapify(A, 0);
    }
}
int main()
{

	printf("Enter the size you want to give : ");
	scanf("%d",&n);
	printf("Enter the numbers you want to give : ");
	for(i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
	}
	HeapSort(a);
 
  for(i = 0; i < n; i++)
    printf("%d ",a[i]);
  return 0;
	
} 

