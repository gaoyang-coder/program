#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
printf("call:pid=%d,ppid=%d",getpid(),getppid());
system("/home/rlk/linux/week08/test.c");
printf("After calling");
}
