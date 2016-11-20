#include <stdio.h>
//#include <sys/types.h>
#include <unistd.h>

int main() {
	int status,fd[2];
	status = pipe(fd);
	if ( status == -1 ) {
		printf("Pipe creation failed\n");
		return 0;
	} else
		printf("Pipe creation success\n");
	return 0;
}
