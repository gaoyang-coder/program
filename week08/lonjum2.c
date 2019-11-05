#include"my.h"
#include<setjmp.h>
static jmp_buf g_stack_env;

static void fun1(void);
static void fun2(void);

int main(void)
{
	if(00==setjmp(g_stack_env)){
		printf("Normal folw\n");
		printf("1:a=%d,b=%d,c=%d\n",a,b,c);
		func1(&a,&b,&c);
		}
		else{
			printf("long jump flow");
			printf("2:a=%d,b=%d,c=%d\n",a,b,c);
			}
		return 0;

}
static void fun1(int *a,int *b,int *c)
{
	printf("Enter func1\n");
	++(*a);
	++(*b);
	++(*c);
	printf("fun1:a=%d,b=%d,c=%d\n",*a,*b,*c);
	longjmp(g_stack_env,1);
	printf("Leave func1\n");
}











