
#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include<arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>

int hostname_to_ip(char*, char*);

int main(int argc, char *argv[])
{
	

	int socket_desc, client_sock, c, read_size;
	struct sockaddr_in server, client;
	char client_message[2000];

	socket_desc = socket(AF_INET, SOCK_STREAM, 0);
	if(socket_desc==-1)
	{
		printf("Could not create");
	}
	puts("Socket created\n");

	server.sin_family=AF_INET;
	server.sin_addr.s_addr=INADDR_ANY;
	server.sin_port=htons(36796);

	if(bind(socket_desc, (struct sockaddr*) &server, 
sizeof(server))<0)
	{
		perror("bind failed. error");
	}
	puts("Bind done\n");	
	listen(socket_desc, 3);

	puts("Waiting for incoming connections..");
	c=sizeof(struct sockaddr_in);

	client_sock=accept(socket_desc,(struct sockaddr*) &client, 
(socklen_t*) &c);
	if(client_sock<0)
	{
		perror("accept failed");
	}
	puts("connection accepted");

	int hostname_to_ip(char * hostname, char* ip)
	{
		struct hostent  *he;
		struct in_addr **addr_list;
		int i;
		if((he=gethostbyname(hostname))==NULL)
		{
			
			return 1;
		}
		addr_list=(struct in_addr **) he->h_addr_list;

		for(i=0; addr_list[i] !=NULL; i++)
		{
			strcpy(ip, inet_ntoa(*addr_list[i]));
			return 0;
		}
		return 1;

}
