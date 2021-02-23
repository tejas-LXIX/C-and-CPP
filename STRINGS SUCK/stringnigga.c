#include<stdio.h>

int main()
{
    char str[10]="Hello";
    char *p;
    p=str; //holds the base address of the string str
    p="Bye"; //try avoiding this as far as possible. only use it if you know you wont have to change the contents of the string later.
    while(*p!='\0')
    {
        printf("%c",*p);
        p++;
    }
    printf("\n");//this does not change the string str. it only points to a new string "Bye". same goes for all other array types too.
    //the above change if made for int arrays also doesn't change the array the pointer initially pointed to. it only points to a new int array now.
    for(int i=0;i<5;i++)
    {
        printf("%c",str[i]); //output is still hello only.
        str[i]='s'; //this is how you change the original string by changing the individual characters
        printf(" %c ",str[i]);
    }
    printf("\n");
    p=str; //you can access anything with pointers
    p="Bye"; //but never make a pointer point to a string by writing p="Bye". this is because even though you can access the string elements using the pointer
    //but when you try to change the elements of the string using pointers,it has undefined behaviour and therefore during runtime,the program will die with a
    //segmentation fault. therefore, when you know you have to change the elements of a string but also want to use a pointer,then first create a string
    //variable (eg: str[10]) that holds the string literal and then assign a pointer to that string variable.

//actual reason
    /*An aside: C's rules for string literals are different from C++'s rules. In C, a string literal is an array of char, not an array of const char -- but
    attempting to modify it has undefined behavior. This means that in C you can legally write char *s = "hello"; s[0] = 'H';, and the compiler won't
    necessarily complain -- but the program is likely to die with a segmentation fault when you run it. This was done to maintain backward compatibility
    with C code written before the const keyword was introduced. C++ had const from the very beginning, so this particular compromise wasn't necessary.*/

// a literal is a specific value, a variable is a variable lo. eg: here "Bye" is a string literal, whereas str[10] is a string variable

    while(*p!='\0')
    {
        printf("%c",*p); //output is Bye
        printf("%c ",*p);
        // if you write *p='s'; here, you will get a segmentation fault
        p++;
    }

    char str1[10]="shithead";
    strcpy(str,str1);
    printf("%s",str);
}