#include "ch07.h"
static void sig_usr(int); 
int main(void)
{
   if(signal(SIGUSR1, sig_usr) == SIG_ERR) /* 建立信号SIGUSR1的句柄 */
      err_exit ("can't catch SIGUSR1\n");
   for(; ;)
      pause();
}
static void sig_usr(int signo)       /* 信号SIGUSR1的句柄 */
{
   printf("received SIGUSR1\n");
   return;
}
