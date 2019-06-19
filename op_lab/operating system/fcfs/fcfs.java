import java.io.*;
class fcfs
{
	public static void findWaitingTime(int process[],int n,int bt[],int wt[])
	{
			wt[0]=0;		
			for(int i=1;i<n;i++)
			wt[i]=bt[i-1]+wt[i-1];
	}
	public static void turnAroundTime(int process[],int n,int bt[],int wt[],int tat[])
	{
		for(int i=0;i<n;i++)
			tat[i]=wt[i]+bt[i];
	}
	public static void AverageTime(int process[],int n,int bt[])
	{
		int wt[]=new int[n],tat[]=new int[n];
		int total_wt=0;
		int total_tat=0;
		findWaitingTime(process,n,bt,wt);
		turnAroundTime(process,n,bt,wt,tat);
		System.out.printf("brust time"+" TurnAround Time");
		for(int i=0;i<n;i++)
		{
			total_wt=total_wt+wt[i];
			total_tat=total_tat+tat[i];
			System.out.printf("%d",(i+1));
			System.out.printf("	%d",bt[i]);
			System.out.printf("	%d",wt[i]);
			System.out.printf("	%d\n",tat[i]);
		}
		float s=(float)total_wt/(float)n;
		int t= total_tat/n;
		System.out.printf("Average waiting time=%f",s);
		
		
		System.out.printf("Average turnAround time=%d",t);
	}
	public static void main(String args[])
	{
		int process[]={1,2,3};
		int n=process.length;
		int burst_time[]={10,5,8};
		AverageTime(process,n,burst_time);
	}
}
		 
	
		
		
