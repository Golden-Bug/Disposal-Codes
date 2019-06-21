	#include<stdio.h>
	#include<stdlib.h>

	struct treenode
	{
		int data;
		struct treenode* lchild;
		struct treenode* rchild;
	};

	typedef struct treenode node;

	node *root=NULL;

	int isempty()
	{
		return root==NULL? 1:0;
	}

	node* makenode(int ele)
	{
		node *n = (node*) malloc(sizeof(node));
		n->lchild = n->rchild = NULL;
		n->data = ele;
		return n;
	}
	void fill(node* n)
	{
		int ele;
		if(n==NULL) return;

		printf("Enter left child of %d(-1 to skip): ",n->data);
		scanf("%d",&ele);

		if(ele!=-1)
		{
			n->lchild= makenode(ele);
			fill(n->lchild);
		}
		printf("Enter right child of %d(-1 to skip): ",n->data);
		scanf("%d",&ele);
		if(ele!=-1)
		{
			n->rchild= makenode(ele);
			fill(n->rchild);
		}
	}

	void maketree()
	{
		int ele;
		system("cls");

		printf("Enter Root Element: ");
		scanf("%d",&ele);

		root = makenode(ele);
		fill(root);
	}

    void inorder(node *start)
	{
		if(start==NULL) return;

		inorder(start->lchild);
		printf("\t%d",start->data);
		inorder(start->rchild);
	}

	void preorder(node *start)
	{
		if(start==NULL) return;

		printf("%d\t",start->data);
		preorder(start->lchild);
		preorder(start->rchild);
	}

	void postorder(node *start)
	{
		if(start==NULL) return;

		postorder(start->lchild);
		postorder(start->rchild);
		printf("%d\t",start->data);
	}
	void main()
	{
		int ch,ele;
		maketree();
		printf("Preorder traversal is: ");preorder(root);
		printf("\nPostorder traversal is: ");postorder(root);
    }
