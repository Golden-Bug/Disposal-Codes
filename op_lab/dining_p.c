// To Compile :  gcc dining_p.c -pthread
// To run : ./a.out

#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
sem_t stick[5];
void* philosopher(void* j)
{
 int i =(int) j;		//indicating for hungry state
 printf("\nPhilosopher %d is Hungry\n",i);		
 sem_wait(&stick[(i+1)%5]);		//waiting for left stick
 sem_wait(&stick[(i+5)%5]);		//waiting for right stick
 printf("\nPhilosopher %d is eating\n",i);
 sleep(1);				//time for eating
 sem_post(&stick[(i+1)%5]);		//put down the left stick first
 sem_post(&stick[(i+5)%5]);		//put down the right stick 
 printf("\nPhilosopher %d is thinking\n",i);		//go back to thinking state
}
void main()
{
 int i;
 pthread_t pid[5];
 for(i=0;i<5;i++)		//status of the chop stick either 0 or 1 .0->block,1->unblock
 sem_init(&stick[i],0,1);
 for(i=0;i<5;i++)		//creating threads for different semaphores
  pthread_create(&pid[i],NULL,philosopher,(void*)i);
  for(i=0;i<5;i++)			//joining the threads
  pthread_join(pid[i],NULL);
}
