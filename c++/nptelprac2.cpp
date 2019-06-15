#include<stdio.h>
int main()
{
	int m,n;
	int a[50][50];
	scanf("%d%d",&m,&n);
	for(int i=0;i<m;++i)
	{
		for(int j=0;j<n;++j)
		{
			scanf("%d",&a[i][j]);
		}
	
	}
	for(int i=0;i<m;++i)
	{
		for(int j=0;j<n;++j)
		{
			if(j<=i)
			printf("%d",a[i][j]);
			
			else
			printf("0");
		}
		printf("\n");
	}
	return 0;
}
