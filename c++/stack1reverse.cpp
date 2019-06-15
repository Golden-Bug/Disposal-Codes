#include<stdio.h>
#include<math.h>
#define MAX 100
 
 struct stack
 {
 	int element[MAX];
 	int top;
 };
 struct stack st;
  
   void push(int x)
   {
   	if(st.top==MAX-1)
   
   {
	   	printf("full");
	   }
	    else 
	    {
	    	st.top++;
	    	x=st.element[st.top];
		}
}   
  
    int pop()
    {
    	if(st.top==-1)
      {	printf("stack is empty");}
      else
      {
      	int x=st.element[st.top];
      	st.top--;
      	
	  }
	}
	
	
	int main()
	{ 
	   st.top=-1;
	   int n;
	   int c;
	   int sum=0;
	   scanf("%d",&n);
	   while (n>0)
	   {
	   	 push(n%10);
	   	 n=n/10;
	   } 
	   while(st.top>=0)
	   {
	   	sum=sum+st.element[st.top]*pow(10,c);
	    st.top--;
	   }
	    printf("%d",sum);
	    return 0;
	}
