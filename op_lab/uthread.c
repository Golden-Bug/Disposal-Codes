#include <stdio.h>
#include <pthread.h>
  
/* user defined thread function definition*/
void* threadFunction(void* args)
{
   int n = 10;
    while(n>0)
    {
        printf("function 1 of  %d.\n",n);
        n = n -1;
    }
}


void* threadFunction1(void* args)
{
   int n = 10;
    while(n>0)
    {
        printf(" function 2 - %d.\n",n);
        n = n -1;
    }
}

void* threadFunction2(void* args)
{
   int n = 10;
    while(n>0)
    {
        printf("function 3 of  %d.\n",n);
        n = n -1;
    }
}


int main()
{
    /*creating thread id*/
    pthread_t id;
    int ret,set,get;
    int n = 20;
  
    /*creating thread*/
    ret=pthread_create(&id,NULL,&threadFunction,NULL);
    
    if(ret==0){
    
        printf("\n Function1 created.\n");
         threadFunction(n);
    }
    else{
        printf("Thread of 1 not created.\n");
        return 0; /*return from main*/
    }
    
    set=pthread_create(&id,NULL,&threadFunction1,NULL);
   
    if(set==0){
        printf(" Function2 created .\n");
         threadFunction1(n);
    }
    else{
        printf("Thread 2 not created.\n");
        return 0; 
    }
  
 
  get=pthread_create(&id,NULL,&threadFunction2,NULL);
  
    if(get==0){
        printf(" Function3 created .\n");
         threadFunction2(n);
    }
    else{
        printf("Thread 3 not created.\n");
        return 0; /*return from main*/
    }

  
    return 0;
}
