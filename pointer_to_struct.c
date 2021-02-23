#include<stdio.h>

struct student
{
    char name[15];
    int marks;
};

int main()
{
    struct student b={"Tejas",76};
    struct student *ptr; //since ptr points to a variable whose type is struct student
    ptr=&b;
    printf("%s %d",ptr->name,ptr->marks); //arrow operator. to be used with pointers to access the structure elements
    display(&b);
}
display(struct student *h)
{
    printf("%s %d",h->name,h->marks);
}