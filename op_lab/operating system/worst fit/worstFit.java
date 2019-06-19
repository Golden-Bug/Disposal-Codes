import java.io.*;
class worstFit 
{
	static void WorstFit(int BlockSize[],int m,int processSize[],int n)
	{
		int allocation[]=new int[n];
		
		for(int i=0;i<allocation.length;i++)
		allocation[i]=-1;
		
		for(int i=0;i<n;i++)
		{
			int worstIdx=-1;
		
			for(int j=0;j<m;j++)
			{
				if(BlockSize[j]>=processSize[i])
				{
					if(worstIdx==-1)
						worstIdx=j;
					else if(BlockSize[worstIdx]<BlockSize[j])
						worstIdx=j;
				}
			}
			if(worstIdx!=-1)
			{
				allocation[i]=worstIdx;
				BlockSize[worstIdx] -=processSize[i];
			}
		}
		System.out.println("\n process no\tBlock Size\t process Size");
		for(int i=0;i<n;i++)
		{
			System.out.print(" "+(i+1)+"\t\t"+processSize[i]+"\t\t");
			if(allocation[i]!=-1)
				System.out.print(allocation[i]+1);
			else 
				System.out.println("Not allocated");
			System.out.println();
		}
	}
	public static void main(String args[])
	{
		int processSize[]={100,500,300,600};
		int BlockSize[]={212,117,256,350};
		int m=processSize.length;
		int n=BlockSize.length;
		WorstFit(BlockSize,m,processSize,n);
	}
}		
			
			
		
