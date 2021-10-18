#include<stdio.h>
int main()
{
  int min,max,count=0,i;
  printf("enter min and max values\n");
  scanf("%d-%d",&min,&max);
  for(min=0;min<=max;min++)
  {
    count=0;
    for(i=1;i<=min;i++)
    {
      if(min%i==0)
      count++;
    }
   if(count==2)
     printf("%d-%d\n",min,count);
   }
}  
