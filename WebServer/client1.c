#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pthread.h>
#include <sys/wait.h>

#define BUF_SIZE 512

int main()
{
	int current_sfd;
	int port = 7020;
	struct sockaddr_in address;
	char buf[BUF_SIZE];
	memset(buf, 0, BUF_SIZE);


	current_sfd = socket(AF_INET, SOCK_STREAM, 0);
	printf("Initilize socket: %d \n", current_sfd);

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = 0;//(in_addr_t)htonl(127*224+1);//INADDR_LOOPBACK;
	address.sin_port = htons(port);
	int beSuc = connect(current_sfd, (struct sockaddr *)&address, sizeof(address));

	printf("return of connect() is : %d\n", beSuc);

	buf[0]='a';
	buf[1]='m';
	buf[2]='b';
	buf[3]='e';
	buf[4]='r';
	buf[5]='\0';
	write(current_sfd, buf, 6);

}
