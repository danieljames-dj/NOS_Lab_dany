#include <stdio.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc,char* argv[]) {
	int shmID = shmget(IPC_PRIVATE,20*sizeof(int),0666);
	if ( shmID == -1 ) {
		printf("Shared memory creation failed\n");
		return 0;
	} else
		printf("Shared memory creation success\n");
	pid_t p = fork();
	if ( p==0 ) {
		wait(NULL);
		int *sh = shmat(shmID,NULL,0);
		printf("%d\n",*sh);
	} else if ( p>0 ) {
		int* sh = shmat(shmID,NULL,0);
		int x = atoi(argv[1]),y = atoi(argv[2]);
		*sh = x+y;
	} else {
		printf("Process creation failed\n");
		return 0;
	}
	return 0;
}
