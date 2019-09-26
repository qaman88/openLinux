#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void * thred_function(void *arg){
	int * incoming = (int* )arg;int i;
	for (i=0;i<5;i++)
	printf( "Running Thread of value: %i \n",*incoming);
	return incoming;
}

int main(void){
	pthread_t thread1,thread2,thread3,thread4,thread5,thread6,thread7,thread8,thread9,thread10;
	void * exit_status;
	int value=0;
	//create the thread, passing value for argument |  wait for thread to terminate
	pthread_create(&(thread1),NULL,thred_function,&value);value++;
	pthread_create(&(thread2),NULL,thred_function,&value);value++;	
	pthread_create(&(thread3),NULL,thred_function,&value);value++;
	pthread_create(&(thread4),NULL,thred_function,&value);value++;
	pthread_create(&(thread5),NULL,thred_function,&value);value++;	
	pthread_create(&(thread6),NULL,thred_function,&value);value++;
	pthread_create(&(thread7),NULL,thred_function,&value);value++;
	pthread_create(&(thread8),NULL,thred_function,&value);value++;
	pthread_create(&(thread9),NULL,thred_function,&value);value++;
	pthread_create(&(thread10),NULL,thred_function,&value);value++;
	pthread_join(thread1,&exit_status);
	pthread_join(thread2,&exit_status);
	pthread_join(thread3,&exit_status);
	pthread_join(thread4,&exit_status);
	pthread_join(thread5,&exit_status);	
	pthread_join(thread6,&exit_status);
	pthread_join(thread7,&exit_status);
	pthread_join(thread8,&exit_status);	
	pthread_join(thread9,&exit_status);
	pthread_join(thread10,&exit_status);
	return 0;
}
