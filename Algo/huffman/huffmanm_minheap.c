#include <stdio.h>
#include <string.h>
#include<stdlib.h>

struct dictionary
{
	char alphabet;
	int frequency;
	int valid;
	struct dictionary* left;
	struct dictionary* right;
	struct dictionary* next;
};

void Min_Heapify(struct dictionary*  arr[], int root, int n)
{
	
	int left= 2*root+1,
 		right= 2*root+2,
 		smallest= root;
 		
	struct dictionary *temp= NULL;
	
	
	if((left<n) && ((arr[smallest]->frequency)>arr[left]->frequency))
		smallest= left;
	if((right<n) && ((arr[smallest]->frequency)>arr[right]->frequency))
		smallest= right;  
	
	if(smallest!= root)
	{
		temp= arr[root];
		arr[root]= arr[smallest];
		arr[smallest]= temp;
		Min_Heapify(arr, smallest, n);
	}
}

struct dictionary* newNode(char alpha, int freq, int val)
{
	struct dictionary* ptr=NULL;
	ptr=(struct dictionary*)malloc(sizeof(struct dictionary));
	ptr->alphabet=alpha;
	ptr->frequency=freq;
	ptr->valid=val;
	ptr->next=ptr->right=ptr->left=NULL;
	return ptr;
}

int Heap_To_PQueue(struct dictionary * arr[], int n)
{
	int i=0, j=0, k=n;
	struct dictionary *tmp=NULL, *tmp1=NULL, *tmp2=NULL;
	
	for(i=0; i<n-1; i++)
	{
		
		for (j = k / 2 - 1; j >= 0; j--)
			Min_Heapify((arr+i), j, k);
		tmp1=arr[i];
		
		k--;
		i++;
		for (j = k / 2 - 1; j >= 0; j--)
			Min_Heapify(arr+i, j, k);
		i--;
		
		tmp2=arr[i+1];	
		
		tmp=newNode(0, tmp1->frequency+tmp2->frequency, 0);
		tmp->left=tmp1;
		tmp->right=tmp2;
		arr[i+1]=tmp;	
	}
	
	printf("Frequency= %d ", arr[i]->frequency);
	return i;
}

int Insert_Sort_List(struct dictionary **head, struct dictionary **ptr, char alpha, int freq, int val)
{
	struct dictionary *moveHead=NULL, *tmpNode=NULL;
	int pos=0;
	moveHead=*head;
	if(*head==NULL)
	{
		*head=newNode(alpha, freq, val);
		*ptr=*head;
		return pos;
	}
	
	if(freq<moveHead->frequency)
		{
			tmpNode=newNode(alpha, freq, val);
			tmpNode->next=moveHead;
			*head=tmpNode;
			*ptr=*head;
			return 0;
		}
		
	
	while(moveHead->next!=NULL)
	{
		pos++;
		if(freq<moveHead->next->frequency)
		{
			break;
		}
		moveHead=moveHead->next;
	}
	
	tmpNode=newNode(alpha, freq, val);
	tmpNode->next=moveHead->next;
	moveHead->next=tmpNode;
	*ptr=tmpNode;

	return 0;
}

int Hoffman_Pop(struct dictionary **head)
{
	struct dictionary *tmp=NULL, *tmp1=NULL, *tmp2=NULL;
	
	if(*head==NULL)
		return 0;
	else
	{
		while((*head)->next!=NULL)
		{
			tmp1=*head;
			tmp2=(*head)->next;
			*head=tmp2->next;
			Insert_Sort_List(head, &tmp,  0, tmp1->frequency+tmp2->frequency, 0);
			tmp->left=tmp1;
			tmp->right=tmp2;
		}
		return 1;
	}
}

int Hoffman_Code_Gen(struct dictionary *move, FILE *fpOut, FILE *fpOut2, char code[], int *codeSize, int lvl)
{
	int status=0;
	
	if(move==NULL)
		return -1;
	else
	{
		if(move->valid==1)
		{
			fprintf(fpOut,"%c null null %d\n", move->alphabet, move->frequency);
			fprintf(fpOut2,"%c %s\n", move->alphabet, code);
			return 1;
		}
		else
		{
			fprintf(fpOut, "n%d ",(lvl));
			
			if(move->left==NULL)
				fprintf(fpOut,"NULL ");
			else
				fprintf(fpOut, "n%d ", 2*lvl);
			
			if(move->right==NULL)
				fprintf(fpOut, "NULL ");
			else
				fprintf(fpOut, "n%d ", (2*lvl)+1);
			
			fprintf(fpOut, "%d\n", move->frequency);
			
			
			strcat(code,"0");
			(*codeSize)+=1;
			status=Hoffman_Code_Gen(move->left, fpOut, fpOut2, code, codeSize, 2*lvl);
			code[(*codeSize)]='\0';
			(*codeSize)-=1;
			
			
			strcat(code,"1");
			(*codeSize)+=1;
			status=Hoffman_Code_Gen(move->right, fpOut, fpOut2, code, codeSize, 2*lvl+1);
			code[(*codeSize)]='\0';
			(*codeSize)-=1;
		}
	}
}

int main(int argc, char *argv[])
{
	FILE *fpIn=NULL, *fpOut=NULL, *fpOut2=NULL;
	
	int i=0, freq=0, arrSize=0,
			codeLength=1;
	
	char alpha=0;
	char code[20]="0";
	
	struct dictionary * arrList[20], *headNode=NULL;

	fpIn=fopen("frequency.txt","r");
	fpOut=fopen("tree.txt","w");
	fpOut2=fopen("codes.txt","w");
	if((fpIn==NULL))
	{
		printf("Files did not match!");
		return 0;
	}
	
	i=0;
	while(fscanf(fpIn, "%c %d ", &alpha, &freq)!=EOF)
	{
		arrList[i]=newNode(alpha, freq, 1);
		i++;
	}
	arrSize=i;

	headNode=arrList[Heap_To_PQueue(arrList, arrSize)];
	
	Hoffman_Code_Gen(headNode, fpOut, fpOut2, code, &codeLength, 1);
	
	
	
	if(arrSize==0)
		printf("Error!!");
	else
		printf("Output is written in tree.txt and codes.txt");

	fclose(fpIn);
	fclose(fpOut);
	fclose(fpOut2);
		
	return 0;
}
