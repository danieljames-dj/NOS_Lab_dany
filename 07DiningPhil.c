#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>

pthread_t phil[20];
sem_t chop[20];
int n;

void *eat(void *arg) {
	int i=arg;
	printf("Philosopher %d thinking\n",i);
	sem_wait(&chop[i]);
	sem_wait(&chop[(i+1)%n]);
	printf("Philosopher %d eating\n",i);
	sleep(10);
	printf("Philosopher %d finished eating\n",i);
	sem_post(&chop[i]);
	sem_post(&chop[(i+1)%n]);
}

int main() {
	int i;
	long j;
	printf("Enter no of philosophers : ");
	scanf("%d",&n);
	for ( i=0 ; i<n ; i++ ) {
		sem_init(&chop[i],0,1);
	}
	for ( i=0 ; i<n ; i++ ) {
		j = i;
		if (pthread_create(&phil[i],NULL,eat,(void*)j)) {
			printf("Error thread creation\n");
			return 0;
		}
	}
	for ( i=0 ; i<n ; i++ ) {
		if (pthread_join(&phil[i]),NULL ) {
			printf("Error thread join\n");
			return 0;
		}
	}
	return 0;
}
