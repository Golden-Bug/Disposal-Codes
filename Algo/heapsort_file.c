#include<stdio.h>
#include<string.h>

char A[1000][20];
int word=1;


void max_heapify(int n,int i)
{
	int l=i*2;
	int r=i*2+1;
	int larg=i;
	if(strcmp(A[l],A[larg])>0&&n>=l)
		larg=l;
	if(strcmp(A[r],A[larg])>0&&n>=r)
		larg=r;
	char t[20];
	if(larg!=i)
		{
			strcpy(t,A[larg]);
			strcpy(A[larg],A[i]);
			strcpy(A[i],t);
			max_heapify(n,larg);
		}
}

void heapsort()
{
	char t[20];
	int i;
	for(i=word;i>=1;i--)
	{
		strcpy(t,A[i]);
		strcpy(A[i],A[1]);
		strcpy(A[1],t);
		max_heapify(i-1,1);
	}
		
}

void write_in_file()
{
	FILE *fp=fopen("strings_out.txt","w");
	int i,j;
	for(i=1;i<=word;i++)
	{	
		j=0;
		while(A[i][j]!='\0')
		{
			fprintf(fp,"%c",A[i][j]);
			j++;
		}
		fprintf(fp,"%c",' ');
	}
	fclose(fp);
}

void build_max_heap()
{	
	int i;
	for(i=word/2;i>=1;i--)
		max_heapify(word,i);
}

void read_from_file()
{
	int l;
	FILE *fp=fopen("strings_in.txt","r");
	char c=fgetc(fp);
	while(c!=EOF)
	{
		l=0;
		A[word][l]=c;
		l++;
		c=fgetc(fp);
		while(c!=' '&&c!=EOF)
		{
			A[word][l]=c;
			l++;
			c=fgetc(fp);
		}
		c=fgetc(fp);
		word++;
	}
	word--;
	fclose(fp);
}

int main()
{
	read_from_file();
	build_max_heap();
	heapsort();
	write_in_file();
	return 0;
}
