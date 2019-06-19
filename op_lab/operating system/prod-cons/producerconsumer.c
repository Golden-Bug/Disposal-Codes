#include<stdio.h>
#include<stdlib.h>
int mutex=1,full=0,empty=3,x=0;
int main()
{
	int n;
	void producer();
	void consumer();
	
	int wait(int);
	int signal(int);
	printf("\n1.producer\n2.consumer\n3.exit\n");
	while(1)
	{
		printf("Enter the option no:");
		scanf("%d",&n);
		switch(n)
		{
			case 1: if((mutex==1)&&(empty!=0))
						producer();
					else
						printf("Producer is full!");
					break;
			case 2: if((mutex==1)&&(full!=0))
						consumer();
					else
						printf("Consumer is empty!");
					break;
			case 3:
					exit(0);
					break;
		}
	}
	return 0;
}

int wait(int s)
{
	return(--s);
}
int signal(int s)
{
	return(s++);
}
void producer()
{
	mutex=wait(mutex);
	full=signal(full);
	empty=wait(empty);
	x++;
	printf("\n producer produced items %d\n",x);
	mutex=signal(mutex);
		
		
}
void consumer()
{
	mutex=wait(mutex);
	full=wait(full);
	empty=signal(empty);
	x--;
	printf("\nconsumer consumed items %d",x);
	mutex=signal(mutex);
}



			
						
	
