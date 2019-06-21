#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inp(int n,int** x)
{ int i,j;
	for( i=0;i<n;i++)
		for( j=0;j<n;j++)
			x[i][j]=rand()%10;
}

void display(int n,int** x)
{ int i,j;
	for( i=0;i<n;i++)
	{	
		for( j=0;j<n;j++)
			printf("%d\t",x[i][j]);
		printf("\n");
	}
}

void MatrixMultiply(int n, int** A, int Ar1, int Ac1, int** B, int Br1, int Bc1, int **C, int Cr1, int Cc1)
{
	if(n == 1)
	{
		C[Cr1][Cc1] += A[Ar1][Ac1] * B[Br1][Bc1]	;
	}
	else
	{
		MatrixMultiply(n/2, A, Ar1, Ac1,B, Br1, Bc1, C, Cr1, Cc1);
		MatrixMultiply(n/2, A, Ar1, Ac1+n/2, B, Br1+n/2, Bc1, C, Cr1, Cc1);

		MatrixMultiply(n/2, A, Ar1, Ac1, B, Br1, Bc1+n/2, C, Cr1, Cc1+n/2);	
		MatrixMultiply(n/2, A, Ar1, Ac1+n/2, B, Br1+n/2, Bc1+n/2, C, Cr1, Cc1+n/2);

		MatrixMultiply(n/2, A, Ar1+n/2, Ac1, B, Br1, Bc1, C, Cr1+n/2, Cc1);	
		MatrixMultiply(n/2, A, Ar1+n/2, Ac1+n/2, B, Br1+n/2, Bc1, C, Cr1+n/2, Cc1);

		MatrixMultiply(n/2, A, Ar1+n/2, Ac1, B, Br1, Bc1+n/2, C, Cr1+n/2, Cc1+n/2);	
		MatrixMultiply(n/2, A, Ar1+n/2, Ac1+n/2, B, Br1+n/2, Bc1+n/2, C, Cr1+n/2, Cc1+n/2);
	}

}

int main()
{
	int n,i,j;
	printf("Dimension of matrices : ");
	scanf("%d", &n);


	int **A = (int **)malloc(n * sizeof(int *));
	for ( i=0; i<n; i++)
		A[i] = (int *)malloc(n * sizeof(int));
	
	int **B = (int **)malloc(n * sizeof(int *));
	for ( i=0; i<n; i++)
		B[i] = (int *)malloc(n * sizeof(int));

	int **C = (int **)malloc(n * sizeof(int *));
	for ( i=0; i<n; i++)
		C[i] = (int *)malloc(n * sizeof(int));


	srand(time(0));	
	inp(n,A);
	inp(n,B);
	for( i=0 ; i<n ; i++)
		for( j=0 ; j<n ; j++)
			C[i][j] = 0;


	MatrixMultiply(n , A, 0, 0, B, 0, 0, C, 0, 0);


	printf("\nMatrix A:\n");
	display(n,A);
	printf("\nMatrix B:\n");
	display(n,B);
	printf("\nMatrix A x B:\n");
	display(n,C);
	

	return 0;
}
