//ARRAY SUM //
#include<stdio.h>
int main()
{
	int a[50],b[50][50];
	int i,k=1,least;
	int n,result,sump,sums;
	scanf("%d",&n);
	for(int j=0;j<n;++j)
	{
		scanf("%d",&a[j]);
		
	}
	for(i=1;i<n;++i)
	{
		for(int j=0;j<i;++j)
		{
		sump+=a[j];
		sums+=a[n-j+1];
         }
         b[i][k]=sump+sums;
         k++;
    }
    least=b[0][0];
    for(i=1;i<n;++i)
    {
    	for(k=1;k<n;++k)
    	{  
    	 
		 
    		if( least>b[i][k])
    		{
    			least=b[i][k];
    			printf("%d",i);
			}
		
		}
	}
    return 0;
}
