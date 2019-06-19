class Firstfit
{
	static void firstfit(int blockSize[],int m,int processSize[],int n)
	{
		int allocation[]=new int[n];
		for(int i=0;i<allocation.length;i++)
		{
			allocation[i]=-1;
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(blockSize[j]>=processSize[i])
				{
					allocation[i]=j;
					blockSize[j] -= processSize[i];
					break;
				}
			}
		}
	

		System.out.println("\nProcess No\tProcess size\t\tBlock No.\t\t\tBlockSize");
		for(int i=0;i<n;i++)
		{
			System.out.println(" "+(i+1)+"\t\t"+processSize[i]+"\n\t"+blockSize[i]+"\t\t");
			if(allocation[i]!=-1)
			{
				System.out.println(allocation[i]+1);
			}
			else 
			{
				System.out.println("Not allocated");
			}
			System.out.println();
		}
	}
	public static void main(String[] args)
	{
		int blockSize[]={200 ,300 ,450 ,180 ,600};
		int processSize[]={180 , 210 , 400 ,200};
		int m=blockSize.length;
		int n=processSize.length;
		firstfit(blockSize, m, processSize, n);
	}
}

		

			
			
			
