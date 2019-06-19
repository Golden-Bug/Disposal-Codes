import java.io.*;
class bestFit 
{
	public static void BestFit(int BlockSize[],int m,int processSize[],int n)
	{
		int allocation[]=new int[n];
		for(int i=0;i<allocation.length;i++)
		allocation[i]=-1;
		for(int i=0;i<n;i++)
		{
			int BestIdx=-1;
			for(int j=0;j<m;j++)
			{
				if(BlockSize[j]>=processSize[i])
				{
					if(BestIdx==-1)
						BestIdx=j;
					else if(BlockSize[BestIdx]>BlockSize[j])
						BestIdx=j;
				}
			}
			if(BestIdx!=-1)
			{
				allocation[i]=BestIdx;
				BlockSize[BestIdx] -=processSize[i];
			}
		}
		System.out.println("\n process no\t Block size\t Block no");
		for(int i=0;i<n;i++)
		{
			System.out.print(" "+(i+1)+"\t\t"+processSize[i]+"\t\t");
			if(allocation[i]!=-1)
				System.out.print(allocation[i]+1);
			else 
				System.out.print("Not available");
			System.out.println();
		}
	}
	public static void main(String args[])
	{
		int processSize[]={100,500,300,600};
		int BlockSize[]={212,117,256,350};
		int m=processSize.length;
		int n=BlockSize.length;
		BestFit(BlockSize,m,processSize,n);
	}
}
			
