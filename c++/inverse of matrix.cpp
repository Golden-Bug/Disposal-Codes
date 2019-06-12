// inverse of a matrix //
#include<stdio.h>
#include<math.h>
 float determinant(float [][50], float);
 void cofactor(float [][50], float);
 void transpose(float [][50], float[][50], float);
 
 int main()
 {
 	 float a[50][50];
 	 float k,d;
 	 int i,j;
 	 printf("enter the order of matrix");
 	 scanf("%f",&k);
 	 printf("enter the numbers");
 	 for(i=0;i<k;++i)
 	 {
 	 	for(j=0;j<k;++j)
 	 	{
		  
 	 	scanf("%f",&a[i][j]);
	    }
     }
     
     d=determinant(a,k);
     if(d==0)
     printf("Matrix not possible");
     else
     cofactor(a,k);
 }
     
     
   float determinant(float a[][50],float k)
    
   {
   	float s=1,det=0, b[50][50];
   	int i,j,m,n,c;
   	 
   	 if(k==1)
   	 {
   	 	return a[0][0];
   	 	
		}
   	
   	else
   	{
   		det=0;
   		for(c=0;c<k;++c)
   		{
   			
   		  m=0;
		  n=0;
		  
		  for(i=0;i<k;++i)
		  {
		  	for(j=0;j<k;++j)
		  	{
		  	  b[i][j]=0;
		  	  if(i!=0 && j!=c)
		  	  {
				
		  	  b[m][n]=a[i][j];
		  	  if(n<(k-2))
		  	  n++;
		  	  else
		  	  {
		  	  	n=0;
		  	  	m++;
					}
				}
		  	  
		  	  
			  }
		  }
			 	
   		det=det+s*(a[0][c]*determinant(b,k-1));
   		s=-1*s;
   			
   			
		   }
	   }
   return (det);
	 }  
     
     void cofactor(float num[50][50], float f)
     {
     	int i,j,p,n,m,q;
 float b[50][50], fac[50][50];
     	for(p=0;p<f;p++)
     	
     	{
     		for(q=0;q<f;q++)
     		{
     			m=0;
     			n=0;
     			for(i=0;i<f;i++)
     			{
     				for(j=0;j<f;++j)
     				{
     					if(i!=p && j!=q)
     					{
     						b[m][n]=num[i][j];
     						if(n<(f-2))
     						n++;
     						else
     						{
							 
							 n=0;
     						m++;
     						
							 }
						 }
					 }
				 }
			fac[q][p]=pow(-1,q+p)*determinant(b,f-1);	 
		}
			 
     		
		 }
     	
     	transpose(num,fac,f); 
	
	 }
     
     void traspose( float num[50][50], float fac[50][50], float f)
     {
     	
     	int i,j;
    float b[5][50] ,inverse[50][50],d;
    for(i=0;i<f;i++)
    {
    	for(j=0;j<f;j++)
    	{
    		b[i][j]=fac[j][i];
    		
		}
}
    d=determinant(num,f);
    for(i=0;i<f;++i)
    {
    	for(j=0;j<f;++j)
    	{
    		inverse[i][j]=b[i][j]/d;
		}
	}
    printf("the inverse of a matrix is ");
    
    for(i=0;i<f;++i)
    {
    	for(j=0;j<f;++j)
    	{
    	printf("%d",inverse[i][j]);
		}
		printf("\n");
	}
    
	 }
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
 
