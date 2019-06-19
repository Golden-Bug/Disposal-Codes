#include<stdio.h>
#include<stdlib.h>
void bestFit(int ProcessSize[],int BlockSize[],int m,int n)
{
	int allocation[n],i,j;
	for(int i=0;i<n;i++)
	{
		allocation[n]=-1;
	}
	for(int i=0;i<n;i++)
	{
		int BestIdx=0;
		for(int j=0;j<m;j++)
		if(BlockSize[j]>=ProcessSize[i])
		{
		{
			if(BestIdx==-1)
				BestIdx=j;
			else if(BlockSize[BestIdx]>BlockSize[j])
				BestIdx=j;
		}
		if(BestIdx!=0)
		{
			allocation[i]=BestIdx;
			BlockSize[BestIdx]-=ProcessSize[BestIdx];
		}
		}
	}
	printf("\n process no\t processSize\t Block No\n");
	for(int i=0;i<n;i++)
	{
		printf("\t%d\t\t%d\t",(i+1),ProcessSize[i]);
		if(allocation[i]!=-1)
		{
			allocation[i]=allocation[i]+1;
			printf("%d",allocation[i]);
			printf("\n");
	    }
			
		else
			printf("Not allocated");
	}
	
}
int main()
{
	int ProcessSize[4]={225,350,550,800};
	int BlockSize[4]={600,500,200,100};
	int m=4;
	int n=4;
	bestFit(ProcessSize,BlockSize,m,n);
}
	
	
