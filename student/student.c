#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"student.h"
int register_student(struct student *ptr)
{
  struct student *temp;
  struct student *ptr1=(struct student *)malloc(1*sizeof(struct student));
    if(ptr1==NULL)
    {
        printf("insufficient memory");
        exit(1);
    }
    strcpy(ptr1->name,ptr->name);
    ptr1->idno=ptr->idno;
    ptr1->marks=ptr->marks;
    ptr1->gender=ptr->gender;
    ptr1->link=NULL;
    if(head==NULL)
    {
       head=ptr1;
       return;
    }
    temp=head;
    while(temp->link!=NULL)
    {
       temp=temp->link;
    }
    temp->link=ptr1;
    return 0;
}

void display_all()
{
  struct student *temp;
 
  if(head==NULL)
  {
    printf("list is empty\n");
    return;
  }
  temp=head;

  while(temp!=NULL)
  {
    temp=temp->link;
  }
}
void display_particular(int idno)
{
   struct student *temp;
   if(head==NULL)
   {
      printf("list is empty\n");
      return;
   }
   temp=head;
   while(temp!=NULL)
   {
     if(temp->data==idno)
        printf("%d\n",temp->idno);
     temp=temp->link;
   }
}
