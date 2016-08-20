#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <pthread.h>

/*void *thread_run(void * arg)
{
	pthread_detach(pthread_self());
	printf("%s\n",(char*)arg);
	return NULL;
}
int main()
{
	pthread_t tid;
	if(pthread_create(&tid,NULL,thread_run,"thread_run....") != 0)
	{
		perror("pthread_run");
		return -1;
	}

	if(0 == pthread_join(tid,NULL))
	{
		printf("wait success\n");
		return 0;
	}
	else
	{
		printf("wait failed\n");
		return -2;
	}
	return 0;
}*/
int g_val = 0;
pthread_mutex_t  mutex_lock = PTHREAD_MUTEX_INITIALIZER;

void * thread_run(void *val)
{
	int i = 1;
	while(i++ <= 5000)
	{
		pthread_mutex_lock(&mutex_lock);
		int tmp = g_val;
		printf("g_val : %d\n",g_val);
		g_val = tmp +1;
		pthread_mutex_unlock(&mutex_lock);
	}
	return (void*)123;
}
int main()
{
	pthread_t id1;
	pthread_t id2;
	pthread_create(&id1,NULL,thread_run,NULL);
	pthread_create(&id2,NULL,thread_run,NULL);
	pthread_join(id1,NULL);
	pthread_join(id2,NULL);
	printf("count fina val is :%d\n",g_val);
	return 0;
}
