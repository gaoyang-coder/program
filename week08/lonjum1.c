#include"my.h"
#include<setjmp.h>
static jmp_buf g_stack_env;

static void fun1(void);
static void fun2(void);

int main(void)
{
	if(00==setjmp(g_stack_env)){
		print("Normal folw\n");
		func1();
		}
		else{
			print("long jump flow");
			}
		return 0;

}
static void fun1(void)
{
	printf("Enter func1\n");
	func2();
}
static void fun2(void)
{
	printf("Enter func2\n");
	longjmp(g_stack_env);
	printf("Leave func2\n");
}












