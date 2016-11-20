#include <stdio.h>
#include <unistd.h>

int main() {
	int status,fd[2],x,y;
	status = pipe(fd);
	if ( status == -1 ) {
		printf("Pipe creation failed\n");
		return 0;
	} else
		printf("Pipe creation success\n");

	//An integer is pushed to pipe (fd[1]) with parent process
	//Then it is pulled from pipe (fd[0]) with child process
	pid_t process = fork();
	if ( process==0 ) { //Child
		read(fd[0],&y,sizeof(y));
		printf("y = %d\n",y);
		close(fd[0]);
	} else if ( process>0 ) { //Parent
		x = 3;
		write(fd[1],&x,sizeof(x));
		close(fd[1]);
	} else {
		printf("Forking failed\n");
	}
	return 0;
}
