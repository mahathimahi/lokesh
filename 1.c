main()
{
int arr[4]={10,20,30,40};
int x=100,*ptr=arr;
printf("%u %d %d\n",ptr,*ptr,x);
x=*ptr++;
printf("%u %d %d\n",ptr,*ptr,x);
x=*++ptr;
printf ("%u %d %d\n", ptr, *ptr, x) ;
x=++*ptr;
printf ("%u %d %d\n" ,ptr, *ptr,x);
x=(*ptr)++;
printf("%u %d %d\n",ptr,*ptr,x);
}
