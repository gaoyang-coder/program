#include<stdio.h>
int a;
static int b=10;
int main(int argc,char*argv[],char*envp[]){
char*p=(char*)malloc(sizeof(char));
printf("a=%d,p=0x%x\n",a,p);
getchar();
getchar();
return 0;
}
