//Dijkstra's Algorithm for shortest path
#include<stdio.h>
#include<stdlib.h>

#define INFINITY 99999
#define MAX 10

void dijk(int g[MAX][MAX],int n,int sp);

int main()
{
   int g[MAX][MAX],n,i,j,sp;
   

  FILE *fp;
  fp=fopen("input_7.txt","r");
  fscanf(fp,"%d",&n);
  
   for(i=0;i<n;++i)
    {
    
      for(j=0;j<n;++j)
        {
         fscanf(fp,"%d",&g[i][j]);
        }
    }

    fscanf(fp,"%d",&sp);
   
   dijk(g,n,sp);
  fclose(fp);
    return 0;

}


void dijk(int g[MAX][MAX],int n,int sp)
{
  int cost[MAX][MAX], dis[MAX], pred[MAX];
  int visited[MAX],count, mindis,nextnode,i,j;
  
  //creating the cost matrix
  
  for(i=0;i<n;++i)
  {
    for(j=0;j<n;++j)
    {
      if(g[i][j]==0)
      cost[i][j]=INFINITY;
      else
      cost[i][j]=g[i][j];
    }
  }
  
  //initialising pred,dis and visited
    
      for(i=0;i<n;++i)
       {
         dis[i]=cost[sp][i];
         pred[i]=sp;
         visited[i]=0;
       }
       
       dis[sp]=0;
       visited[sp]=1;
       count=1;
       
       
     while(count<(n-1))
     {
       mindis=INFINITY;
        
        for(i=0;i<n;++i)
        {
            if(dis[i]<mindis && !visited[i])
            {
                     mindis=dis[i];
                     nextnode=i;
            
            }
        
        }
        
        visited[nextnode]=1;
     
         for(i=0;i<n;i++)
                if(!visited[i])
                    if(mindis+cost[nextnode][i]<dis[i])
                    {
                        dis[i]=mindis+cost[nextnode][i];
                        pred[i]=nextnode;
                    
         count++;
     
                    }

//printing the shortest path
 
   FILE *fp;
   fp=fopen("output_7.txt","a");
   for(i=0;i<n;i++)
        if(i!=sp)
        {
            fprintf(fp,"\nDistance of node%d=%d",i,dis[i]);
            fprintf(fp,"\nPath=%d",i);
            
            j=i;
            do
            {
                j=pred[j];
                fprintf(fp,"<-%d",j);
            }while(j!=sp);
        }

    fclose(fp);
     
    }


}


