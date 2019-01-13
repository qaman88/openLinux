/*Condition, Shared Data and Mutex  */

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <semaphore.h>
int sharedData=1000;
sem_t semaphore;

void *thread_function(void * arg){
	// Activity Defination
	sem_wait(&semaphore);
	while(sharedData>0){
		if(sharedData>0)--sharedData;
		printf("Running... %i shared data %i \n",*(int*)arg,sharedData);
	}
	//sem_signal(&semaphore); //error
	
	printf("Done! Thread %i \n",*(int*)arg)	;
	return NULL;
}

int main(void){
	pthread_t thread1,thread2;
	void * exitValue;
	int i=1,j=2;
	sem_init(&semaphore,1,1);
	
	// Create Thread
	pthread_create(&thread1,NULL,thread_function,&i);
	pthread_create(&thread2,NULL,thread_function,&j);
	
	// Wait unti shared data is zero
	while(sharedData>0){
		sem_wait(&semaphore);
	}
	//sem_signal(&semaphore); //error
	
	// Wait until thread finish
	pthread_join(thread1,&exitValue);
	pthread_join(thread2,&exitValue);
	
	// Destroy Semaphore
	sem_destroy(&semaphore);
	printf("Program complited, bye!\n");
	
	return 0;
}
