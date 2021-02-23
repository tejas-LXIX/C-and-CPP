#include<stdio.h>

struct address
{
    long phone;
    char city[20];
    int pin;
};
struct emp
{
    char name[15];
    struct address a; // a of type struct address is an element of the struct emp. this is called nesting of strucutres
};

void display(struct emp);
void display1(char *,long);

int main()
{
    struct emp e1={"Tejas",9765398107,"Hyderabad",5008};
    printf("%s %ld %s %d",e1.name,e1.a.phone,e1.a.city,e1.a.pin);
    display(e1); // a structure variable can be passed all at once to a function
    display1(e1.name,e1.a.phone);
}

void display(struct emp e)
{
    printf("\n%s %ld %s %d\n",e.name,e.a.phone,e.a.city,e.a.pin);
}

void display1(char *g,long p)
{
    for(int i=0;i<15;i++)
    {
        printf("%c",*g);
        g++;
    }
    printf(" %ld",p);
}