#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>

int main() {
	int sockfd;
	char buff[100];
	struct sockaddr_in seAd,clAd;
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if (sockfd<0) {
		printf("Error opening socket\n");
	}
	memset(&seAd,0,sizeof(seAd));
	seAd.sin_family = AF_INET;
	seAd.sin_addr.s_addr = INADDR_ANY;
	seAd.sin_port = htons(2020);
	if ( connect(sockfd,(struct sockaddr*)&seAd,sizeof(seAd)) < 0 ) {
		printf("Error on connecting\n");
		return 0;
	}
	write(sockfd,"Hi",100);
	read(sockfd,buff,100);
	printf("%s\n",buff);
	close(sockfd);
	return 0;
}
