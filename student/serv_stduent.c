#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include"student.h"
int main()
{
  int socfd,b,l,a;
  struct sockaddr_in server,client;
  struct student *s;
  socklen_t len;
  len=sizeof(client);
  socfd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
  if(socfd==-1)
  {
    printf("fail to create socket\n");
    exit(1);
  }
  memset(&server,0,sizeof(server));
  memset(&client,0,sizeof(client));
  server.sin_family=AF_INET;
  server.sin_port=5555;
  server.sin_addr.s_addr=inet_addr("127.0.0.1");
  b=bind(socfd,(struct scokaddr*)(&server),sizeof(server));
  if(b==-1)
  {
    printf("fail to bind\n");
    exit(2);
  }
  l=listen(socfd,1);
  if(l==-1)
  {
      printf("fail to listen\n");
      exit(3);
  }
  a=accept(socfd,(struct sockaddr *)&client,&len);
  if(a==-1)
  {
      printf("fail to accept\n");
      exit(4);
  }
  while(1)
  {
     int opt,idno,r,ret,ret1;
     socklen_t len;
     len=sizeof(client);
     printf("enter the option\n");
     scanf("%d",&opt);
     switch(opt)
     {
        case 1:r=recv(a,s,sizeof(struct student),0);
               if(r==-1)
               {
                 printf("fail to receive\n");
                 exit(5);
               }
               /*ret=register_student(s);
               ret1=send(a,&ret,sizeof(int),0);
               if(ret1==-1)
               {
                 printf("failed to send response\n");
                 exit(6);
               }*/
               printf("student idno-->%d\n",s->idno);
               printf("student name-->%s\n",s->name);
               printf("student marks-->%f\n",s->marks);
               printf("student gender-->%c\n",s->gender);
               break;
       /* case 2:display_all();
               break;
        case 3:display_particular(idno);
               break;*/
        default:printf("invalid input\n");
     }
   }
 }
               
               
     
