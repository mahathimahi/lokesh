#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
main(int argc,char *argv[])
{
  int fd,ret;
  char buf[10];
  if(argc!=2)
  {
    printf("invalid input\n");
    exit(0);
  }
  fd=open(argv[1],O_RDONLY);
  if(fd<0)
  {
    printf("fail to open file\n");
    exit(1);
  }
  while(ret=read(fd,buf,9)<0)
  {
    if(ret<0)
    {
       printf("fail to read file\n");
       exit(2);
    }
    buf[ret]='\0';
  }
  printf("%s\n",buf);
}
  
