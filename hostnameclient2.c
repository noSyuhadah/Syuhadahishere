#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <errno.h>

int hostname_to_ip(char*, char*);
int main (int argc, char *argv[])
{
	{
	int sock;
	struct sockaddr_in server;
	char message[1000], server_reply[2000];

	sock=socket(AF_INET, SOCK_STREAM, 0);
	if(sock==-1)
	{
		printf("Could not created socket\n");
	}
	puts("Socket created");

	server.sin_addr.s_addr=inet_addr("192.168.136.135");
	server.sin_family=AF_INET;
	server.sin_port=htons(36796);
	
	if(connect(sock, (struct sockaddr*) &server, sizeof(server))<0)
	{
		perror("Connect failed. error");
		return 1;
	}
	puts("Connected\n");

	printf("Enter message :");
	scanf("%s", message);
	}
	char *hostname=argv[1];
	char ip[100];

	hostname_ip(hostname, ip);
	printf("%s resolved to %s", hostname, ip);
	
	int hostname_to_ip(char *hostname, char* ip)
	{
		sockfd;
		struct addrinfo hints, *servinfo, *p;
		struct sockaddr_in *h;
		int rv;
	
		memset(&hints, 0, sizeof hints);
		hints.ai_family= AF_UNSPEC;
		hints.ai_socktype=SOCK_STREAM;

	}
	return 0;
}
