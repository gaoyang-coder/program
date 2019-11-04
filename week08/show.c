#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
pid_t result;
result=fork();
int newret;
if(result==-1)
{
	perror("創建進程失敗");
	exit;
}
else if(result==0)
	{
		printf("返回值是:%d,說明這是子進程!\n此進程的進程號(pid)是:%d\n此進程的父進程號(ppid)是:%d\n",result,getpid(),getppid());
newret=system("ls -l");
}
else
{
	sleep(10);
printf("返回值是:%d,說明這是父進程!\n此進程的進程號是(pid)是:%d\n此進程的父進程號(ppid)是:%d\n",result,getpid(),getppid());
newret=system("ping www.lupaworld.com");
}
}
