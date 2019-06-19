#include<stdio.h>
#include<stdlib.h>
void findWaitingTime(int process[],int bt[],int wt[],int n,int quantam)
{
	int rem_bt[n];
	for(int i=0;i<n;i++)
	
		rem_bt[i]=bt[i];
	
	int t=0;
	
	
		
		
		
		for(int i=0;i<n;i++)
		{
			if(rem_bt[i]>0)
			{
				
				if(rem_bt[i]>quantam)
				{
					t+=quantam;
					rem_bt[i]-=quantam;
				}
				else
				{
					t=t+rem_bt[i];
					wt[i]=t-bt[i];
					rem_bt[i]=0;
				}
			}
			
		}
		
	
	
				
}
void findTurnAroundTime(int process[],int bt[],int wt[],int n,int tat[])
{
	for(int i=0;i<n;i++)
		tat[i]=bt[i]+wt[i];
}
void findAverageTime(int process[],int n,int quantam,int bt[])
{
	int wt[n],tat[n];
	int total_wt=0;
	int total_tat=0;
	findWaitingTime(process,bt,wt,n,quantam);
	findTurnAroundTime(process,bt,wt,n,tat);
	printf("\nprocess no\twaiting time\tturnaround time\tburst time\n");
	for(int i=0;i<n;i++)
	{
		total_wt=total_wt+wt[i];
		total_tat=total_tat+tat[i];
		printf("\t%d\t\t%d\t\t%d\t\t%d\t",(i+1),wt[i],tat[i],bt[i]);
		
	}
	float s=(float)total_wt/(float)n;
	int t=(int)total_tat/(int)n;
	printf("Average waiting time =%f",s);
	
	printf("Average TurnAroundTime=%d",t);
	printf("\n");
}
int main()
{
	int process[6]={0,3,2,0,70,9};
	int quantam=3;
	int n=6;
	int burst_time[6]={5,25,3,10,7,6};
	findAverageTime(process,n,quantam,burst_time);
	return 0;
}
