// amit and taxi //
#include<stdio.h>
int main()
{
	float n,v1,v2;
	float s, w;
	scanf("%f %f %f",&n,&v1,&v2);
	s=(2*n)/v2;
	w=(1.414*n)/v1;
	if(s>w)
	printf("WALK");
	else 
	printf("TAXI");
	return 0;
	}
