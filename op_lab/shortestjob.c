


#include<stdio.h>
#include<stdlib.h>
void sort(int at[],int p[],int bt[],int N)
{ int temp,temp1,temp2;
   int i,j;
  for (i = 0; i < N; ++i)
        {

            for (j = i + 1; j < N; ++j)
            {

                if (bt[i]>bt[j])
                {

                    temp= bt[i];
                    bt[i] = bt[j];
                    bt[j] = temp;

                    temp1=at[i];
                    at[i]=at[j];
                    at[j]=temp1;

                    temp2=p[i];
                    p[i]=p[j];
                    p[j]=temp2;

                }

            }

        }

}
void waiting_time(int at[],int bt[],int wt[],int N)
{
    int i;
  wt[0]=0;
  int sum=bt[0]+at[0];
  for(i=1;i<N;i++)
  { if(sum>=at[i])
    {
    wt[i]=sum-at[i];
    sum=sum+bt[i];
    }
    else{wt[i]=0;
         sum=at[i];}
   }
}
void completion_time(int at[],int bt[],int ct[],int N)
{
    int i;
  int sum=0;
  for(i=0;i<N;i++)
  { if(sum>=at[i])
    {sum=sum+bt[i];
    ct[i]=sum;}
    else{sum=at[i];
         sum=sum+bt[i];
         ct[i]=sum;
         }
   }
}
void turn_around(int at[],int ct[],int tat[],int N)
{
    int i;
  for(i=0;i<N;i++){
    tat[i]=ct[i]-at[i];
  }
}
void main(){
  int at[10],bt[10],ct[10],wt[10],tat[10],p[10],N;
  int i;
  printf("Enter the number of process");
  scanf("%d",&N);
  for(i=0;i<N;i++)
  { printf("enter p%d arrival time",i);
    scanf("%d",&at[i]);
    p[i]=i;
    printf("enter p%d burst time",i);
    scanf("%d",&bt[i]);
  }
  sort(at,p,bt,N);
  waiting_time(at,bt,wt,N);
  completion_time(at,bt,ct,N);
  turn_around(at,ct,tat,N);

  printf("P.NO\tTWT\tCT\tTAT\n");
  for(i=0;i<N;i++){
    printf("%d\t%d\t%d\t%d\n",p[i],wt[i],ct[i],tat[i]);
  }

}

