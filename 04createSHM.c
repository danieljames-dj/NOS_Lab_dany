#include <stdio.h>
#include <sys/shm.h>

int main() {
	int shmID = shmget(IPC_PRIVATE,20*sizeof(int),0666);
	if ( shmID == -1 ) {
		printf("Shared memory creation failed\n");
		return 0;
	} else
		printf("Shared memory creation success\n");
	return 0;
}
