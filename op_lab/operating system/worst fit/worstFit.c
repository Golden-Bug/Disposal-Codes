#include<stdio.h>
#include<stdlib.h>
void WorstFit(int processSize[],int blockSize[],int m,int n)
{
	int allocation[n];
	for(int i=0;i<n;i++)
	
	{
		int WorstIdx=0;
		for(int j=0;j<n;j++)
		{
			if(blockSize[j]>=processSize[i])
			{
				if(blockSize[WorstIdx]==-1)
					WorstIdx=j;
				else if(blockSize[WorstIdx]<blockSize[j])
					WorstIdx=j;
			}
		}
		if(WorstIdx!=-1)
		{
			allocation[i]=WorstIdx;
			blockSize[WorstIdx]-=processSize[WorstIdx];
		}
	}
	printf("process no\t process size\tblock no\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\t\t%d\t\t",(i+1),processSize[i]);
		if(allocation[i]!=-1)
		{
			allocation[i]=allocation[i]+1;
			printf("%d\n",allocation[i]);
		}
		else
		{
			printf("Not available");
		}
	}
}
int main()
{
	int processSize[3]={2,3,4};
	int blockSize[3]={5,7,2};
	int m=5;
	int n=5;
	WorstFit(processSize,blockSize,m,n);
}
	
		
