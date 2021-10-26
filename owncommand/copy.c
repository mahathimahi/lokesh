#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
main(int argc,char *argv[])
{
   int fd,ret,fd1,ret1;
   char buf[10];
   if(argc!=3)
   {
     printf("invalid input\n");
     exit(0);
   }
   fd=open(argv[1],O_RDONLY);
   if(fd<0)
   {
     printf("fail to read\n");
     exit(1);
   }
   while(ret=read(fd,buf,9)<0)
   {
     if(ret<0)
     {
       printf("fail to read\n");
       exit(2);
     }
     buf[ret]='\0';
   }
   fd1=open(argv[2],O_CREAT|O_TRUNC|O_WRONLY,0660);
   if(fd1<0)
   {
     printf("fail to open second file\n");
     exit(3);
   }
   ret1=write(fd1,buf,strlen(buf));
   if(ret1<0)
   {
     printf("fail to write in another file\n");
     exit(4);
   }
   close(fd);
   close(fd1);
}
     
