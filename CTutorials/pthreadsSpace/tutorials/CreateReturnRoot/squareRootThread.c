#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void * thred_function(void *arg){
	int * indexes =(int*)arg;
	int start=indexes[0],end =indexes[1];
	printf( "Computing squareroot... %i \n",end-start+1);
	float * outputBuf = (float* )malloc(end-start+1);
	int j;	
	for (j=start;j<=end;j++){
		outputBuf[j]=sqrt(j);
		printf(" %f |",outputBuf[j]);
	}
	return outputBuf;//
}

int main(void){
	pthread_t thread1,thread2,thread3,thread4;
	void * exit_status;
	float * buffer;int j;
	int values[2]= {1,10};
	/*for (j=0;j<99;j++){
		values[j]= j;
		printf( "%i|",values[j]);
	}
	//create the thread, passing value for argument |  wait for thread to terminate
	pthread_create(&(thread1),NULL,thred_function,values);
	/*pthread_create(&(thread2),NULL,thred_function,values);	
	pthread_create(&(thread3),NULL,thred_function,values);*/
	pthread_create(&(thread4),NULL,thred_function,values);
	
	/*pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	pthread_join(thread3,NULL);*/
	pthread_join(thread4,&exit_status);
	
//	buffer = (float *) exit_status;
	printf( " \n\nResults \n\n");
	/*int i;	
	for (i=0;i<99;i++)	{
		printf("|\t%f",buffer[i]);
	}*/
	
}
