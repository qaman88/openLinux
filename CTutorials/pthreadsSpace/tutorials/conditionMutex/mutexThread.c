/*Condition, Shared Data and Mutex  */

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
pthread_cond_t is_zero;
pthread_mutex_t mutex;
int sharedData =1000;

void *thread_function(void * arg){
	// Activity Defination
	while(sharedData>0){
		pthread_mutex_lock(&mutex);
		// do some work
		if(sharedData>0)--sharedData;
		printf("Running... %i shared data %i \n",*(int*)arg,sharedData);
		pthread_mutex_unlock(&mutex);	
	}
	
	printf("Done! Thread %i \n",*(int*)arg)	;
		
	//Signal Condition
	pthread_cond_signal(&is_zero);
	return NULL;
}

int main(void){
	pthread_t thread1,thread2;
	void * exitValue;
	int i=1,j=2;
	
	// Set condition and mutex
	pthread_cond_init(&is_zero,NULL);
	pthread_mutex_init(&mutex,NULL);
	
	// Create Thread
	pthread_create(&thread1,NULL,thread_function,&i);
	pthread_create(&thread2,NULL,thread_function,&j);
	
	// Wait unti shared data is zero
	while(sharedData>0){
		pthread_cond_wait(&is_zero,&mutex);
	}
	pthread_mutex_unlock(&mutex);
	
	// Wait until thread finish
	pthread_join(thread1,&exitValue);
	pthread_join(thread2,&exitValue);
	
	// Destroy condition and Mutex
	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&is_zero);
	
	printf("Program complited, bye!\n");
	
	return 0;
}
