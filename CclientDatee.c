#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<time.h>
#include<string.h>
#include<arpa/inet.h>
#include<stdlib.h>
#define CLI_PORT 7777
#define BUFF_SIZE 30

int main(int argc, char**argv)
{
	int clisoc, re;
	char recbuff[BUFF_SIZE];
	struct sockaddr_in cliaddr;
	bzero(&cliaddr, sizeof(cliaddr));
	cliaddr.sin_family=AF_INET;
	cliaddr.sin_port=htons(7777);
	cliaddr.sin_addr.s_addr=inet_addr(argv[1]);

	if((clisoc=socket(AF_INET, SOCK_STREAM, 0))<0)
	{
		perror("Socket Error");
		exit(0);
	}

	if((connect(clisoc,(struct sockaddr*)&cliaddr,sizeof(cliaddr)))<0)
	{
		perror("Connect Error");
		exit(0);
	}

	if((re=(read(clisoc, recbuff, sizeof(recbuff),0)))<0)
	{
		printf("Read Error");
		exit(0);
	}
	printf("The Current Date and Time: %\n", recbuff);
	close(clisoc);
	return 0;
}
