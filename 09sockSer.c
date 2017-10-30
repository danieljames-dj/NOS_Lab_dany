#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>

int main() {
	int sockfd,newSock;
	struct sockaddr_in seAd,clAd;
	char s[100];
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if (sockfd<0) {
		printf("Error opening socket\n");
	}
	memset(&seAd,0,sizeof(seAd));
	seAd.sin_family = AF_INET;
	seAd.sin_addr.s_addr = INADDR_ANY;
	seAd.sin_port = htons(2020);
	if ( bind(sockfd,(struct sockaddr*)&seAd,sizeof(seAd)) < 0 ) {
		printf("Error on binding\n");
		return 0;
	}
	listen(sockfd,5);
	socklen_t clLn = sizeof(clAd);
	newSock = accept(sockfd,(struct sockaddr*)&clAd,&clLn);
	read(newSock,s,100);
	printf("%s\n",s);
	write(newSock,"Hello",100);
	close(sockfd);
	return 0;
}
