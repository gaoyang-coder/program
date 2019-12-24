#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<errno.h>
#include<sys/types.h>

int port=8888;

int main()
{
	int sockfd;
	int len;
	int z;
	char buf[256];
	struct sockaddr_in adr_inet;
	struct sockaddr_in adr_clnt;
	printf("等待客户端....\n");
	/* 建立IP地址 */
	adr_inet.sin_family=AF_INET;
	adr_inet.sin_port=htons(port);
	adr_inet.sin_addr.s_addr =htonl(INADDR_ANY);
	bzero(&(adr_inet.sin_zero),8);
	len=sizeof(adr_clnt);
	/* 建立socket */
	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd==-1)
	{
		perror("socket 出错");
		exit(1);
	}
	/* 绑定socket */
	z=bind(sockfd,(struct sockaddr *)&adr_inet,sizeof(adr_inet));
	if(z==-1)
	{
		perror("bind 出错");
		exit(1);
	}
	while(1)
	{
	/* 接受传来的信息 */
		z=recvfrom(sockfd,buf,sizeof(buf),0,(struct sockaddr *)&adr_clnt,&len);
		if(z<0)
		{
			perror("recvfrom 出错");
			exit(1);
		}
		buf[z]=0;
		printf("接收:%s",buf);
	/* 收到stop字符串，终止连接*/
		if(strncmp(buf,"stop",4)==0)
		{
			printf("结束....\n");
			break;
		}
	}
	close(sockfd);
	exit(0);
}
