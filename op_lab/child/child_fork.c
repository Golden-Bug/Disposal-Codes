// C++ program to demonstrate creating processes using fork() 
#include <unistd.h> 
#include <stdio.h> 

int main() 
{ 
	// Creating first child 
	pid_t n1,n2;
	n1 = fork(); 
	if(n1==0)
	{
		printf("parent:");
		printf(" %d ",getppid());
		printf("child 1: %d \n", getpid());
	}

	else if(n1>0){
		n2=fork();
		if(n2==0){
			printf("parent:");
			printf(" %d ",getppid());
			printf("child 1: %d \n", getpid());
			}
		
			
	    }
	return 0;
}
