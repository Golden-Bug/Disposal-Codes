#include<stdio.h>
#include<stdlib.h>
int size=0;
int i ,a[50];
int n;
void display(int *a,int n)
{
	printf("Max Heap : ");
	for( i=0;i<n;i++)
		printf("%d ",a[i]);
}

void Insert_Max_Heap(int *a,int x)
{
	a[size]=x;
	size++;
	int i=size-1;
	while(a[(i-1)/2]<a[i]&&i>=0)
	{
		int t=a[(i-1)/2];
		a[(i-1)/2]=a[i];
		a[i]=t;
		i=(i-1)/2;
	}
}

int main()
{  printf("Enter the size you want to give : ");
	scanf("%d",&n);
	printf("Enter the numbers you want to give : ");
	for(i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
		Insert_Max_Heap(a,a[i]);
	}
	
 display(a,size);

	return 0;
}
