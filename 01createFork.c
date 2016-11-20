#include <stdio.h>
//#include <sys/types.h>
#include <unistd.h>

int main() {
	pid_t process = fork();
	if ( process==0 ) {
		printf("Child Process\n");
	} else if ( process>0 ) {
		printf("Parent Process\n");
	} else {
		printf("Process creation failed\n");
	}
}
