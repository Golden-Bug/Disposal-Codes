//MANUPULATING ARRAYS //
#include<stdio.h>  
int main()
{
	int a[50],n,k, i, l;
	int max=a[0];
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
		
	}
	for(l=0;l<k;++l)
	
  { 
  	int max=a[0];
  	for(i=1;i<n;++i)
  {
  	if(max<a[i])
  	max=a[i];
  	 }
  for(i=0;i<n;++i)
  {
  	a[i]=max-a[i];
  
  	
  }
  
  }
  for(i=0; i<n; ++i)
  {
     printf("%d\t ", a[i]);
  }
   return 0;
	
	}
