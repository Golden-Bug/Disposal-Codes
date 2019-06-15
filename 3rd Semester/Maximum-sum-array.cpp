b#include<stdio.h>
#include<stdlib.h>

int max2(int a,int b)
{ return (a>b)? a : b;}

int max(int a, int b, int c)
{
	return max2(max2(a,b),c);
}

int maxsubarrcrs(int arr[50],int l, int h)
{
	int m=(l+h)/2;
	int i,sum=0;
	int lsum,rsum,tsum;
	lsum=(-10000);
	rsum=(-10000);
	for(i=m;i>=1;--i)
	{
		sum=sum+arr[i];
		if(sum>lsum)
		{
			lsum=sum;
		}
	}
	
	sum=0;
		for(i=m+1;i<=h;++i)
	{
		sum=sum+arr[i];
		if(sum>rsum)
		{
			rsum=sum;
		}
	}
	
	tsum=lsum+rsum;
	return tsum;
		
}

int maxsubarrlist(int arr[50], int l, int h)
{
	int m;
	if(l==h)
	{
		return arr[l];
	}
	
	m=(l+h)/2;
	return max(maxsubarrlist(arr,l,m),maxsubarrlist(arr,m+1,h),maxsubarrcrs(arr,l,h));
}
 

int main()
{
	int arr[50];
	int n,i;
	printf("Enter the size of array\n");
	scanf("%d",&n);
	printf("Enter the elements of array : \n");
	for(i=0;i<n;++i)
	{
		scanf("%d",&arr[i]);
	}
	int maxsum;
	maxsum=maxsubarrlist(arr,0,n-1);
	printf("The maxsum is %d\n ",maxsum);
	return 0;
}

























