#include<stdio.h>
#include<stdlib.h>

typedef struct bst
{
 int info;
 int height;
 struct bst *left;
 struct bst *right;
}node;

typedef node* root;

int set_height(root r)
{
 int left_h = -1;
 int right_h = -1;
 if(r->left)
  left_h = r->left->height;
 if(r->right)
  right_h = r->right->height;
 if(left_h >= right_h)
  r->height = left_h+1;
 else
  r->height = right_h+1;
 return r->height;
}

int compare(int data1, int data2)
{
 if(data1<data2)
  return -1;
 if(data1>data2)
  return 1;
 else
  return 0;
}

void rotate_LL(root *r)
{
 node *r1, *r2 = *r,*t1,*t2,*t3;

 r1 = r2->left;
 t1 = r1->left;
 t2 = r1->right;
 t3 = r2->right;

 r1->right = r2;
 r2->left = t2;

 set_height(r1);
 set_height(r2);

 *r = r1;
}

void rotate_RL(root *r)
{
 node *r1,*r2, *r3=*r,*t1,*t2,*t3,*t4;

 r1 = r3->left;
 r2 = r1->right;
 t2 = r2->left;
 t3 = r2->right;

 r1->right = t2;
 r3->left = t3;
 r2->left = r1;
 r2->right = r3;

 set_height(r1);
 set_height(r2);
 set_height(r3);

 *r = r2;
}

void rotate_LR(root *r)
{
 node *r1=*r, *r2,*r3,*t1,*t2,*t3,*t4;

 r3 = r1->right;
 r2 = r3->left;
 t2 = r2->left;
 t3 = r2->right;

    r1->right = t2;
    r3->left = t3;
    r2->left = r1;
    r2->right = r3;

    set_height(r1);
    set_height(r2);
    set_height(r3);

    *r = r2;
}

void rotate_RR(root *r)
{
 node *r1=*r,*r2,*t1,*t2,*t3;

 r2 = r1->right;
 t1 = r1->left;
 t2 = r2->left;
 t3 = r2->right;

 r1->right = t2;
 r2->left = r1;

 set_height(r1);
 set_height(r2);

 *r = r2;
}

int find_rotation_type(int parent_data, int child_data, int data)
{
 if(compare(data, parent_data)<0) /* inserting left*/
 {
  if(compare(data, child_data)<0)
   return 1;
  else if(compare(data, child_data)==0)
   return 0;
  else
   return 2;
 }
 else
 {
  if(compare(data, child_data)>0)
   return 4;
  else if(compare(data, child_data)==0)
   return 0;
  else
   return 3;
 }
}

void do_rotation(root *r, int rotation_type)
{
 if(rotation_type == 1)
  rotate_LL(r);
 else if(rotation_type == 2)
  rotate_RL(r);
 else if(rotation_type == 3)
  rotate_LR(r);
 else if(rotation_type == 4)
  rotate_RR(r);
 else
  printf("invalid rotation type \n");
}

int insert(root *r, int data)
{
 node *n, *root = *r;
 int left_h = -1, right_h = -1;
 int diff,rotation_type;

 if(root == NULL)
 {
  n = (node *)malloc(sizeof(node));
  n->info = data;
  n->height = 0;
  n->left = n->right = NULL;
  *r = n;
  return 0;
 }
 if(root->left)
  left_h = root->left->height;
 if(root->right)
  right_h = root->right->height;

 if(compare(data, root->info)<0)
 {
  left_h = insert(&(root->left), data);
  rotation_type = find_rotation_type(root->info, root->left->info, data);
 }
 else if(compare(data, root->info)>0)
 {
  right_h = insert(&(root->right), data);
  rotation_type = find_rotation_type(root->info, root->right->info, data);
 }
 else
 {
  printf("\n\t Duplicate key!!\n");
  return -1;
 }

 diff = left_h-right_h;
 if(diff>1 || diff<-1)
 {
		printf("\n\t Tree is Un-Balanced at node data %d ", root->info);
        if(rotation_type == 1)
			printf("\n\t need to do LL rotation\n");
        if(rotation_type == 2)
			printf("\n\t need to do RL rotation\n");
        if(rotation_type == 3)
			printf("\n\t need to do LR rotation\n");
        if(rotation_type == 4)
			printf("\n\t need to do RR rotation\n");
        do_rotation(r,rotation_type);
		printf("\n\t rotation done successfully\n");
  root = *r;
 }
 return set_height(root);
}

void InOrder(node *root)
{
 node *temp = root;
 if(temp)
 {
  InOrder(temp->left);
  printf("%d ",temp->info);
  InOrder(temp->right);
 }
}

void PreOrder(node *root)
{
 node *temp = root;
 if(temp)
 {
  printf("%d ",temp->info);
  PreOrder(temp->left);
  PreOrder(temp->right);
 }
}

void PostOrder(node *root)
{
 node *temp = root;
 if(temp)
 {
  PostOrder(temp->left);
  PostOrder(temp->right);
  printf("%d ",temp->info);
 }
}
int menu()
{
	int ch;
	system("cls");
	printf("\n\n\t  MENU\n");
	printf("\t ===============\n");
	printf("\t 1. Insert	  \n");
	printf("\t 2. InOrder	  \n");
	printf("\t 3. PreOrder    \n");
	printf("\t 4. PostOrder   \n");
	printf("\t 5. Height of the tree \n");
	printf("\t 6. Exit \n");

	printf("\n\t Enter Ur choice:  ");
	scanf("%d",&ch);
	return ch;
}
void main()
{
 root r = NULL;
 int data,choice;

do
{
 choice=menu();

  switch(choice)
  {
   case 1:
	 printf("\n\t Enter the element:  ");
     scanf("%d",&data);
     insert(&r,data);
     break;
   case 2:
	 printf("\n\t Inorder is \n ");
	 InOrder(r);
     break;
   case 3:
	 printf("\n\t Preorder is \n ");
	 PreOrder(r);
     break;
   case 4:
	 printf("\n\t Postorder is \n ");
	 PostOrder(r);
     break;
   case 5:
	 printf("\n\t Height of the tree is %d\n",r->height);
     break;
   case 6: printf("\n\n\t Thank U visit again\n "); break;
   default:
		printf("\n\n\t Sorry Wrong Choice\n");
  }
  system("pause");
 }while(choice!=6);
}
