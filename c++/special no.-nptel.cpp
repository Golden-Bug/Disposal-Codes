//special number //
#include<stdio.h>
int main()
{
	int n,count=0,s=0,i;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		if(n%i==0)
		{ 
	        while(i>0)
	        { 
	        printf("Loop entered\n");
	        	s=i%10;
	        	if(s==3 || s==5 || s==6)
	        {
					count++;
	        	break;
				}
	        	i=i/10;
			}
 		}
	}

//	printf("%d",count);
	return 0;
}
