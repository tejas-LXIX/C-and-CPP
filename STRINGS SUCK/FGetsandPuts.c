#include<stdio.h>

int main()
{
    char name[20]="hello bitch";
    printf("%s\n",name);
    printf("enter a string ");
    scanf("%[^\n]",name); // name passes the base address of the string name to the scanf function
    printf("%s\n",name);
    printf("enter a string ");
    char x;
    x=scanf("%d",&x); /*reads the extra newline. this has to be done because every scanf() leaves a newline character in buffer that is read by next scanf.*/
    /*toh if you dont use this,then fgets() actually reads the newline and the actual input string is ignored by it.*/
    fgets(name,20,stdin); // stdin stands for standard input
    puts(name);
    char name1[15]; //you cannot write name here because you cannot define name again
    scanf("%[a-zA-Z]",name);// Taking a name as an input. reads only alphabets from the input string and stops at the first instance it encounters a number.
    printf("%s",name);
    return 0;
}
