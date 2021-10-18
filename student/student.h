struct student{
int idno;
char name[20];
float marks;
char gender;
struct student *data;
struct student *link;
};
struct student *head;
int register_student(struct student *);
//void display_all();
//void display_particular(int );
