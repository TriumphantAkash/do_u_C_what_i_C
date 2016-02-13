#include <stdio.h>
#include <pthread.h>

pthread_t tid[2];

void* sample_thread(void *arg)
{
	int i = 0;
	pthread_t tid_curr;
	tid_curr = pthread_self();

	if(tid_curr == tid[0]) {
		while(i < 10){
			printf("\nthis is first thread\n");
			sleep(1);
		}
	}else if(tid_curr == tid[1]) {
			while(i < 10){
				printf("\nthis is second thread\n");
				sleep(1);
			}
	}else {
		printf("\nI dunno.. where I am\n");
	}

//	for(i = 0; i < 0xFFFFFFFF; i++);
	return NULL;
}


int main()
{	
	int i = 0;
	printf("\nmain thread start\n");
	while(i < 2){
		pthread_create(&tid[i], NULL, &sample_thread, NULL);
		i++;
	}
//	sleep(5);
	printf("\nmain thread gonna end\n");
	return 0;	
}
