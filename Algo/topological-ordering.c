#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int matrix[10][10]= {0}, time = 0, n ,m;

struct vertex
{
	char name;
	char color[7];
	int discovered;
	int finished;
};
struct vertex v[10];

void input()
{
	char p, q, r, s;
	FILE *fp;
	fp = fopen("dfs-input.txt", "r");

	if(fp == NULL)
	{
		printf("File cannot open");
		exit(1);
	}
	fscanf(fp, "%d %d", &n, &m);

	while(fscanf(fp, "%c%c%c%c", &r, &p, &s, &q) != EOF)
	{
		matrix[p-97][q-97] = 1;
		v[p-97].name = p;
		v[q-97].name = q;
	}
		
	fclose(fp);
}


void DFS_VISIT(int i)
{
	int j;
    int x = i;
	strcpy(v[i].color, "grey");
	time = time+1;
	v[i].discovered = time;
	
	for(j=0; j<n; j++)
		if(matrix[i][j] == 1 && strcmp(v[j].color, "white") == 0)
			DFS_VISIT(j);

	time = time +1;
	strcpy(v[x].color, "black");
	v[x].finished = time;
}

void swap(int a, int b)
{
	int temp = b;
	b = a;
	a = temp;
}

void ordering()
{
	int i, j;
	for(i=0; i<n-1; i++)
	{
		for(j= i+1; j<n; j++)
		{
			if(v[i].finished < v[j].finished)
			{
				int temp = v[i].name;
				v[i].name = v[j].name;
				v[j].name = temp;

				int temp1 = v[i].discovered;
				v[i].discovered = v[j].discovered;
				v[j].discovered = temp1;

				int temp2 = v[i].finished;
				v[i].finished = v[j].finished;
				v[j].finished = temp2;
			}
		}
	}
}

void output()
{
	int i;
	FILE *fp;
	fp = fopen("topology-output.txt","w");
	for(i=0; i<n; i++)
		fprintf(fp, "%c%c", v[i].name, ' ');
    fclose(fp);
}


int main()
{
	int i, j;
	input();

	for(i=0; i<n; i++)
		strcpy(v[i].color, "white");
		
    for(i=0; i<n; i++)
    	if(strcmp(v[i].color, "white") == 0)
    		DFS_VISIT(i);

    ordering();
    output();
    
    return 0;
}

