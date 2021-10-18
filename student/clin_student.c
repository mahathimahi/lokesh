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
  int socfd,c;
  struct sockaddr_in server,clinet;
  struct student *s;
  socfd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
  if(socfd==-1)
  {
    printf("fail to create socket\n");
    exit(1);
  }
  //memset(&server,0,sizeof(server));
  //memset(&client,0,sizeof(client));
  server.sin_family=AF_INET;
  server.sin_port=5555;
  server.sin_addr.s_addr=inet_addr("127.0.0.1");
  c=connect(socfd,(struct sockaddr*)&server,sizeof(server));
  if(c==-1)
  {
    printf("fail to connect\n");
    exit(2);
  }
  while(1)
  {
     //memset(s,0,sizeof(struct student));
     int opt,idno,sen,ret;
     char name[20],gender;
     float marks;
     printf("enter the option\n 1.register_student\n 2.display_studentinfo\n 3.display_particularinfo\n");
     scanf("%d",&opt);
     switch(opt)
     {
        case 1:printf("enter student idno-->");
               scanf("%d",&s->idno);
               printf("enter student name-->");
               scanf("%s",s->name);
               __fpurge(stdin);
               printf("enter student marks-->");
               scanf("%f",&s->marks);
               __fpurge(stdin);
               printf("enter student gender-->");
               scanf("%c",&s->gender);
               //register_student(s);
               sen=send(socfd,s,sizeof(struct student),0);
               if(sen==-1)
               {
                 printf("fail to read\n");
                 exit(3);
               }
               /*ret=recv(socfd,&ret,sizeof(int),0);
               if(ret==-1)
               {
                  printf("fail to receive\n");
                  exit(4);
               }*/
               break;
        /*case 2:display_all();
               sen=send(socfd,&s,sizeof(struct student),0);
               if(sen==-1)
               {
                 printf("fail to display\n");
                 exit(4);
               }
               break;
        case 3:display_particular(idno);
               break;*/
        default:printf("invalid input\n");
      }
    }
 }
