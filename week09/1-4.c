#include"my.h"
static void callback1(){

	peintf("-------callback1-------\n");
}
static void callback2(){

	peintf("-------callback2-------\n");
}
static void_attribute_((construtor))before_main()
{
 	printf("-------constructor------\n");
}
static void_attribute_((destrutor))after_main()
{
 	printf("-------dessstructor------\n");
}
int main()
{
	atexit(callback1);
	atexit(callback2);
	FILE*fp;
	char buf[]={"test data from full buffer!"};
	if((fp=fopen("test.dat","w+))==NULL)
	{
		perror("failed to fopen!\n");
		return -1;
	}	
	if(fputs(buf,fp)==EOF)
	{
		perror("failed too fputs!\n");
		return -1;
	}
	print("printf:data from line buffer");
	exit(0);
	//_exit(0);
	//return 0;
}














