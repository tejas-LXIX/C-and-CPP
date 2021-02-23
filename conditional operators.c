#include<stdio.h>
int main()
{
char a;
printf("please enter a single character: ");
scanf("%c",&a);
printf("%c",(a>='b'?'T':'FreeE')); /*only the last character "E" is printed because char*/
int i=4;
if(i==5);
{
    printf("\nyou entered 5");       /*even though the if statement if false, the printf is executed because the 'if' statement has a null statement*/
                                     /*inside it. therefore if condition is true,the null statement gets executed following which prinft is executed.*/
/*if the condition is false, the printf statement is executed directly. therefore the if condition fails because of syntax error of putting a semicolon*/
}
}
