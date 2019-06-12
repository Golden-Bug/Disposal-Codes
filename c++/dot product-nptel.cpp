#include<stdio.h>
int main()
{
	int n,i,j,k=0,sum=0;
	int a[500],b[500],c[500][500],min[500];
	scanf("%d",&n);
	for(i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
	}
	for(j=0;j<n;++j)
	{
		scanf("%d",&a[j]);
	}
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)

{
	c[i][j]=a[i]*b[j];
	}	
 }
 min[0]=c[0][0];
  for(i=0;i<n;++i)
  {
  	for(j=0;j<n;++j)
  	{
	  
  		if(min[k]>c[i][j])
  		min[k]=c[i][j];
  		printf("%d",min[k]);
	  }
	  k++;
	    }
	    
	    for(k=0;k<n;++k)
	    {
	    	sum=sum+min[k];
	    
		}
		printf("%d",sum);
		return 0;
	}
