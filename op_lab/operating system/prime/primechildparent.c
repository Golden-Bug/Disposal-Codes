#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/wait.h>
int A[10000];
int k=0;
void display()
 {
   for(int i=0;i<=k;i++)
    {
      printf("%d ",A[i]);
    }
   printf("\n");
 }
void findprime(int l,int h)
 {
   int j=0;
   for(int i=l;i<h;i++)
    {
      int flag=0;
      for(int j=2;j<=i;j++)
       {
         if(i%j==0)
         {
           flag=1;
         }
       }
      if(flag==0 && i!=1)
        {
          A[++k]=i;
          j=j+1;
        }
    }
 }
int main()
{
  int M;
  scanf("%d",&M);//the max number in action
  int i,j,N;//declaration of variables
 scanf("%d",&N);//process in action
 int l =1;
 if(M/N>=1)
 {
 for(int i=0;i<N;i++)
  {
    int pid =fork();
    if(pid==-1)
    {
      //Error handling
    }
   else if(pid==0)
     {
        wait(NULL);
        printf("Child %d sleeping(%d)\n",i,i);
        findprime(l,l+M/N);
        printf("\n");
        l=l+M/N;	
     }
   else
    {
        printf("Parent process is %d\n",i);
        display();
    }
  }
  for(i=0; i<N; i++){
    wait(NULL);
    printf("Got %d done\n",i+1);
  }
 }

 return 0;
}
