#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void * thread_run(void *arg)
{
	while(1)
	{
		printf("new thread.....\n");
		sleep(1);
	}
	return (void*)1;
}
int main()
{
	pthread_t id;
	pthread_create(&id,NULL,thread_run,(void*)123);
	int count = 0;
	while(1)
	{
		printf("main thread...\n");
		sleep(1);
		if(count++ > 5)
		{
		//	pthread_exit((void*)2);
			pthread_cancel(pthread_self());
		}
	}
	return 0;
}
