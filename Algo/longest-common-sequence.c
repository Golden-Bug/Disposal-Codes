#include<stdio.h>
char A[50]= "ATCCGACAAC", B[50]= "ATCGCATCTT", check[20][20];

void backtrack(int i, int j)
{
	if(i==0 || j==0)
		return;
	if(check[i][j] == 'x')
	{
		backtrack(i-1, j-1);
		printf("%c", A[i-1]);
	}
	else if(check[i][j] == 'y')
		backtrack(i-1, j);
	else
		backtrack(i, j-1);
}


int main()
{
	int n=10, m=10, matrix[15][15], i, j;
     
    for(i=0; i<m; i++)
    	matrix[i][0] = 0;
    for(j=0; j<n; j++)
    	matrix[0][j] = 0;

    for(i=1; i<=m; i++)
    {
    	for(j=1; j<=n; j++)
    	{
    		if(A[i-1] == B[j-1])
    		{
    			matrix[i][j] = matrix[i-1][j-1] + 1;
    			check[i][j] = 'x';
    		}
    		else if(matrix[i-1][j] >= matrix[i][j-1])
    		{
    			matrix[i][j] = matrix[i-1][j];
    			check[i][j] = 'y';
    		}
    		else
    		{
    			matrix[i][j] = matrix[i][j-1];
    			check[i][j] = 'z';
    		}
    	}
    }

   /* for(i=0; i<=m; i++)
    {
    	for(j=0; j<=n; j++)
    	{
    		printf("%d ", matrix[i][j]);
    	}
    	printf("\n");
    }*/
   printf("The longest common path is: "); 
   backtrack(m,n);
   printf("\n");
   return 0;
}