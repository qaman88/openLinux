#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void * thred_function(void *arg){
	int * buffer = (int* )malloc(64);
	int i,j;	
	for (j=0;j<64;j++)
		buffer[j]=j;
	for (i=0;i<*(int*)arg;i++)	
		printf( "Running... %i |  \n",i);
	return buffer;
}

int main(void){
	pthread_t thread1,thread2,thread3,thread4;
	void * exit_status;
	int * buffer;
	int value[4]={2,3,4,5};
	//create the thread, passing value for argument |  wait for thread to terminate
	pthread_create(&(thread1),NULL,thred_function,&value);value[1];
	pthread_create(&(thread2),NULL,thred_function,&value);value[2];	
	pthread_create(&(thread3),NULL,thred_function,&value);value[3];
	pthread_create(&(thread4),NULL,thred_function,&value);value[0];
	
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	pthread_join(thread3,NULL);
	pthread_join(thread4,&exit_status);
	
	buffer = (int *) exit_status;
	printf( " \n\nResults \n\n");
	int i;	
	for (i=0;i<64;i++)	
		printf("|\t%i",buffer[i]);
	
}
