#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct dictionary{
	char alphabet;
	int frequency;
	int valid;
	struct dictionary* left;
	struct dictionary* right;
	struct dictionary* next;
};

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
				fprintf(fpOut,"null ");
			else if(move->left->valid==0)
				fprintf(fpOut, "n%d ", 2*lvl);
			else
				fprintf(fpOut, "%c ", move->left->alphabet);
			
			if(move->right==NULL)
				fprintf(fpOut, "null ");
			else if(move->left->valid==0)
				fprintf(fpOut, "n%d ", (2*lvl)+1);
			else
				fprintf(fpOut, "%c ", move->right->alphabet);
			
			fprintf(fpOut, "%d\n", move->frequency);
			
			
			strcat(code,"0");
			(*codeSize)+=1;
			status=Hoffman_Code_Gen(move->left, fpOut, fpOut2, code, codeSize, 2*(lvl));
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
	FILE 	*fpIn=NULL, *fpOut=NULL, *fpOut2=NULL;
	
	int 	i=0, freq=0,
			codeLength=-1;
	
	char	arrSize= 0, alpha=0;
	char 	code[20]={0};
	
	
	struct dictionary *moveNode=NULL, *headNode=NULL;	

	fpIn=fopen("frequency.txt","r");
	fpOut=fopen("tree.txt","w");
	fpOut2=fopen("codes.txt","w");
	if((fpIn==NULL))
	{
		printf("Files did not match!");
		return 0;
	}
	
	while(fscanf(fpIn, "%c %d ", &alpha, &freq)!=EOF)
	{
		i++;
		Insert_Sort_List(&headNode, &moveNode, alpha, freq, 1);
	}

	Hoffman_Pop(&headNode);
	
	Hoffman_Code_Gen(headNode, fpOut, fpOut2, code, &codeLength, -1);
	
	moveNode=headNode;

	if(headNode==NULL)
		printf("Error");
	else
		printf("Output is written in files tree.txt and codes.txt\n");

	fclose(fpIn);
	fclose(fpOut);
	fclose(fpOut2);
		
	return 0;
}
