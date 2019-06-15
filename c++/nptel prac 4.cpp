// DIGITS //
#include<stdio.h>
#include<string.h>
int main()
{
    int n,k,s;
    int flag0=0,flag1=0,flag2=0;
    scanf("%d",&n);
    k=n;
    while(n>0)
    {
    	s=n%10;
    	if(s==1)
    	flag1++;
    else if(s==0)
    	flag0++;
    else if(s!=0 || s!=1)
    flag2=1;
    n=n\10;
	}
	if(flag2==1)
	printf("NO");
	 if(flag1==1)
	printf("YES");
     if(flag0==1)
	printf("YES");
	
	return 0;
}
 
 

