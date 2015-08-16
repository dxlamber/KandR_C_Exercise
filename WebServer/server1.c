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
#define MAX_CONNECTIONS 3

void customProcess(int sfd)
{
	int numRead = 0;
	char buf[BUF_SIZE];
	//1. read stream;
	while((numRead = read(sfd, buf, BUF_SIZE)) > 0)
	{
		//2. write to stand out stream
		//we can replace here with more complex function in a later.
		//such as write back to client,  ananlysis request type, implement http protocal.
		write(1, buf, numRead);
	}

}

int main()
{
	int current_sfd;
	int connected_sfd;
	int port = 7020;
	socklen_t cltAddr_size;
	struct sockaddr_in address;
	struct sockaddr_storage connectedClientAddr;


	current_sfd = socket(AF_INET, SOCK_STREAM, 0);
	printf("After socket(), socked file descriptor is: %d  \n", current_sfd);

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(port);
	int bindResult = bind(current_sfd, (struct sockaddr *)&address, sizeof(address));
	printf("After bind(), return value is: %d \n", bindResult);

	int listenResult = listen(current_sfd, MAX_CONNECTIONS);
	printf("After listen(),  return value is : %d\n", listenResult);

	while(1)
	{
		connected_sfd = accept(current_sfd, (struct sockaddr *)&connectedClientAddr, &cltAddr_size);
		printf("get a connection of:  %d\n" , connected_sfd);
		customProcess(connected_sfd);
		close(connected_sfd);
	}

}
