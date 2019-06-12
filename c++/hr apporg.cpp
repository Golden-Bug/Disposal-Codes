#include<stdio.h>

int main() {
    int s; 
    int t; 
    scanf("%i %i", &s, &t);
    int a; 
    int b; 
    scanf("%i %i", &a, &b);
    int m; 
    int n; 
    scanf("%i %i", &m, &n);
     int x=0;
     int y=0;
    int app[m];
    for(int i=0;i<m;++i)
    {
    	scanf("%d",&app[i]);
	}
	int org[n];
	for(int j=0;j<n;++j)
	{
		scanf("%d",&org[j]);
	}
	 for( int i=0;i<m;++i)
	 {
	 	if((a-app[i])>=(s-a))
	 	{
	 		x++;
		 }
	 }for( int j=0;j<n;++j)
	 {
     if((org[j-t])<=(b-t))
	 
	 	{
	 		y++;
		 }
	 }
	 printf("%d",&x);
	 printf("%d",&y);
	 return 0;
}

