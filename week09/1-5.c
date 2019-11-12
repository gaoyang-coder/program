#include"my.h"
int g=10;
int main()
{
	int s=20;
	static int k=30;
	pid_t pid;
	pid=fork();
	if(pid<0)
	{
		perror("fork failed!\n");
		return -1;
	}
	else if(pid==0)
	{
		printf("child:%g=%16p\n&k=%16p&s=%16p\n",getpid(),&g,&k);
		g=100;
		s=200;
		k=300;
		printf("child after g=%d,s=%d,k=%d\n",g,s,k);
		_exit(0);
	}
	else
{
		printf("parent:%g=%16p\n&k=%16p&s=%16p\n",getpid(),&g,&k);
		printf("parent after g=%d,s=%d,k=%d\n",g,s,k);
		return 0:
}

     }
