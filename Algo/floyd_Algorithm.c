#include<stdio.h>
int min(int,int);
void floyds(int p[10][10],int n)
{
 int i,j,k;
 for(k=0;k<n;k++)
  for(i=0;i<n;i++)
   for(j=0;j<n;j++)
    if(i==j)
     p[i][j]=0;
    else
     p[i][j]=min(p[i][j],p[i][k]+p[k][j]);
}
int min(int a,int b)
{
 if(a<b)
  return(a);
 else
  return(b);
}
void main()
{
 int p[10][10]= {{0,3,8, 999,-4}, {999,0,999,1,7}, {999,4,0,999,0}, {1,999,-5,0,999}, {999,999,0,6,0}}, n=5,i,j;
 printf("\n Matrix of input data:\n");
 for(i=0;i<n;i++)
 {
  for(j=0;j<n;j++)
   printf("%d \t",p[i][j]);
  printf("\n");
 }


 floyds(p,n);
 printf("\nn Transitive closure:\n");
 for(i=0;i<n;i++)
 {
  for(j=0;j<n;j++)
   printf("%d \t",p[i][j]);
  printf("\n");
 }
 printf("\n The shortest paths are:\n");
 for(i=0;i<n;i++)
  for(j=0;j<n;j++)
  {
   if(i!=j)
    printf("\n (%d,%d>) = %d",i,j,p[i][j]);
  }
}
