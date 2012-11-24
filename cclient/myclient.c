/*
 * myclient.c
 *
 *  Created on: Nov 23, 2012
 *      Author: Zahir
 */
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
int main(int argc,char *args[])
{
	char  host_name[1024] ="172.18.4.200";
	struct hostent * server_host_name;
	server_host_name = gethostbyname(host_name);
	int socket_descriptor;



	int port = 8000;
	struct sockaddr_in pin;

	char buf[1024]="hell";
	int rval =1;

	char sendbuff[1024];
/*
	if(argc!=2)
	{
		printf("the number is error\n");
		return 1;
	}
	else
	{
		printf("%s\n",args[1]);
	}
	*/

	pin.sin_family = AF_INET;
	pin.sin_addr.s_addr = inet_addr("127.0.0.1");
	pin.sin_port = htons(port);
	bzero(&(pin.sin_zero), 8);

	socket_descriptor = socket(AF_INET, SOCK_STREAM, 0);
	if(connect(socket_descriptor, (void *)&pin, sizeof(pin))==-1)
	{
		perror("connect");
		exit(1);
	}
//	if (send(socket_descriptor,args[1],strlen(args[1]),0)<0)
	if (send(socket_descriptor,buf,strlen(buf),0)<0)
	{
		perror("send");
		exit(2);
	}

	while(rval){

		printf ("Enter msg: ");
		scanf ("%s", sendbuff);
		fflush(stdin);

		recv(socket_descriptor,buf,1024,0);
		send(socket_descriptor,sendbuff,strlen(sendbuff),0);

		printf("server says: %s",buf);

		printf ("want to send more?? if not press 0: ");
				scanf ("%d",&rval);
				fflush(stdin);

	}

	close(socket_descriptor);
	return 0;
}

