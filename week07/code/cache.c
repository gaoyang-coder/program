#include<stdio.h>
#include<stdlib.h>
#define SIZE 512
int main(int arge,char *argv[])
{
	char buf[SIZE];
	if(seetvbuf(stdin,buf,_IONBF,SIZE)!=0)
{
	perror("将标准输入stdin的输入设置为无缓冲失败！\n");
	return 0;
}
	printf("将标准输入stdin 的输入设置为无缓冲成功！\n");
	printf("stdin类型为");
if(stdin->_flags&_IO_LINE_BUF)
{
	printf("行缓冲\n");
}
else
{
	printf("全缓冲");
}
printf("缓冲区大小为%ld\n",stdin->_IO_buf_end-stdin->_IO_buf_base);
//打印缓冲区的大小
printf("文件描述为 %d\n",fileno(stdin));
if(setvbuf(stdin,buf,_IOFBF,SIZE)!=0)
{
	//将标准输入的缓冲类型设为全缓冲，缓存大小为512
	printf("将标准输入stdin设置为全缓冲失败!\n");
	return 2;
}
printf("修改标准输入stdin的类型成功!");
printf("stdin类型为");
if(stdin->_flags&_IO_UNBUFFERED)
{
		printf("无缓冲\n");
}
else if(stdin->_flags&_IO_LINE_BUF)
{
printf("行缓冲\n");
}
else
{
printf("全缓冲\n");
}
printf("缓冲区大小为%ld\n",stdin->_IO_buf_end-stdin->_io_buf_base);




























