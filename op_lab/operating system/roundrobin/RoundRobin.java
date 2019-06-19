import java.io.*;
public class RoundRobin
{	
	public static void findwaitingTime(int process[],int bt[],int wt[],int quantam,int n)
	{
		int rem_bt[]=new int[n];
		for(int i=0;i<n;i++)
			rem_bt[i]=bt[i];
		int t=0;
		while(true)
		{
			boolean done=true;
			for(int i=0;i<n;i++)
			if(rem_bt[i]>0)
			{
				done=false;
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
			if(done==true)
			break;
		}
	}
	public static void findturnaroundTime(int process[],int bt[],int wt[],int n,int tat[])
	{
		for(int i=0;i<n;i++)
		tat[i]=bt[i]+wt[i];
	}
	public static void findaverageTime(int process[],int n,int bt[],int quantam)
	{
		int wt[]=new int[n],tat[]=new int[n];
		int total_wt=0;
		int total_tat=0;
		findwaitingTime(process,bt,wt,quantam,n);
		findturnaroundTime(process,bt,wt,n,tat);
		System.out.println("Burst time"+"waiting Time"+"TurnAround Time");
		for(int i=0;i<n;i++)
		{
			total_wt=total_wt+wt[i];
			total_tat=total_tat+tat[i];
			System.out.printf("%d",(i+1));
			System.out.printf("	%d",wt[i]);
			System.out.printf("	%d",bt[i]);
			System.out.printf("	%d\n",tat[i]);
		}
		float s=(float)total_wt/(float)n;
		int t=total_tat/n;
		System.out.printf("Average waiting Time=%f",s);
		System.out.printf("Average TurnAround time=%d",t);
	}
	public static void main(String args[])
	{
		int process[]={1,2,3};
		int  n=process.length;
		int burst_time[]={8,6,7};
		int quantam=2;
		findaverageTime(process,n,burst_time,quantam);
	}
}

		
