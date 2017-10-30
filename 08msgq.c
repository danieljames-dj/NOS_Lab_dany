#include <stdio.h>
#include <sys/msg.h>
#include <unistd.h>

struct msgbuff {
	long mtype;
	char mbuff[20];
};

int main() {
	struct msgbuff msg;
	int msgID;
	msgID = msgget(1234,IPC_CREAT|0666);
	msg.mtype = 200;
	fgets(msg.mbuff,sizeof(msg),stdin);
	msgsnd(msgID,&msg,sizeof(msg.mbuff),0);
	return 0;
}
