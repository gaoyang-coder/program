#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>
#include<pthread.h>

#define PORT 9990
#define SIZE 1024

int Creat_socket()
{
	int listen_socket=socket(AF_INET,SOCK_STREAM,0);
	if(listen_socket==-1)
	{
		perror("socket");
		return -1;
	}
	struct sockaddr_in addr;
	memset(&addr,0,sizeof(addr));
	
	addr.sin_family=AF_INET;
	addr.sin_port=htons(PORT);
	addr.sin_addr.s_addr=htonl(INADDR_ANY);
	
	int ret=bind(listen_socket,(struct sockaddr*)&addr,sizeof(addr));
	if(ret==-1)
	{
		perror("bind");
		return -1;
	}
	return listen_socket;
}

int wait_client(int listen_socket)
{
	struct sockaddr_in cliaddr;
	int addrlen=sizeof(cliaddr);
	printf("等待客户端连接。。。\n");
	int client_socket=accept(listen_socket,(struct sockaddr*)&cliaddr,&addrlen);
	if(client_socket==-1)
	{
		perror("accept");
		return -1;
	}
	
	printf("成功接收到一个客户端：%s\n",inet_ntoa(cliaddr.sin_addr));
	
	return client_socket;
}

void hanld_client(int listen_socket,int client_socket)
{
	char buf[SIZE];
	while(1)
	{
		int ret=read(client_socket,buf,SIZE-1);
		if(ret==-1)
		{
			perror("read");
			break;
		}
		if(ret==0)
		{
			break;
		}
		buf[ret]='\0';
		int i;
		for(i=0;i<ret;i++)
		{
			buf[i]=buf[i]+'A'-'a';
		}
	
		printf("%s\n",buf);
		write(client_socket,buf,ret);

		if(strncmp(buf,"end",3)==0)
		{
			break;
		}
	}
	close(client_socket);
}

int main()
{
	int listen_socket=Creat_socket();

	while(1);
	{
		int client_socket=wait_client(listen_socket);

		pthread_t id;
		pthread_create(&id,NULL,hanld_client,(void*)client_socket);

		pthread_detach(id);
	}
	close(listen_socket);

	return 0;
}
		