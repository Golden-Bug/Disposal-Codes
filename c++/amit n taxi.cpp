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
	printf("TAXI");
	else 
	printf("WALK");
	return 0;
	}
