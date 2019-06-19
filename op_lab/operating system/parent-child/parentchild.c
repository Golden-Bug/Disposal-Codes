#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	int pid,pid1,pid2,pid3;
	pid=fork();
	if(fork()==0)
	{
		sleep(3);
		printf("child[1]->pid=%d & ppid=%d\n",getpid(),getppid());
	}
	else
	{
		pid1=fork();
		{
			if(fork()==0)
			{
				sleep(2);
				printf("child[2]->pid=%d & ppid=%d\n",getpid(),getppid());
			}
			else
			{
				pid2=fork();
				{
					if(fork()==0)
					{
						
						printf("child[3]->pid=%d & ppid=%d\n",getpid(),getppid());
					}			
					else
						pid3=fork();
						{
							if(fork()==0)
							{
								printf("child[4]->pid=%d & ppid=%d\n",getpid(),getppid());
							}
							else

							{
					
								sleep(3);
								printf("parent->pid=%d\n",getpid());
							}
						}
					
				}
			}
	
		}
	}
}

