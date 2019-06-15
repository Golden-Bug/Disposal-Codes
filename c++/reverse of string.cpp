//reverse of linked list nptel //

 #include<stdio.h>
#include<stdlib.h>
 
/* Link list node */
struct Node
{
    int data;
    struct Node* next;
};
void printList(struct Node* head);
 void push(struct Node** head_ref,int new_data)
 {
 	struct Node* newnode;
 	newnode=(struct Node*)malloc(sizeof(struct Node));
 	newnode->data=new_data;
 	newnode->next=(*head_ref);
 	(*head_ref)=newnode;
 }
 

  static void reverse(struct Node** head_ref)
{
    struct Node* prev   = NULL;
    struct Node* current = *head_ref;
    struct Node* next = NULL;
    while (current != NULL)
    {
        next  = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
  
  void printList(struct Node *head)
{
    struct Node *temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);    
        temp = temp->next;  
    }
}    

  
 int main()
{
   
    struct Node* head = NULL;
   	 int a,x,i;
   	 scanf("%d",&a);
   	 for(i=0; i<a; i++){
   	 	scanf("%d",&x);
   	 	push(&head, x);
   	 }	
   
     
    
	 reverse(&head);   
	                  
     printList(head);    
     getchar();
}
