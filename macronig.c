#include<stdio.h> /*macros help if a value of a constant needs to be changed everywher in the program. */
#define PI 3.1415 /*Macros. PI is macro template. 3.1415 is the macro expansion. The preprocessor searches the program for all macro templates,and wherever it 
finds one, it replaces it with the macro expansion. Only after this, the program is handed over to the compiler.*/
#define AND &&
#define ARRANGE (a>2 AND a<50) /*ARRANGE is the macro template.(a>2 AND a<50) is the expansion.Keep expressions(mathematical) in parentheses always*/
#define AREA(x) (PI*x*x) /*Macros with arguments. there should be no space between AREA and (x), otherwise even (x) will be treated as an expansion.*/

void main()
{
    float a=PI;
    if(ARRANGE)
    {
        printf("yay success");
    }
    else
    {
        printf("lel");
    }
    float b=AREA(3);
    printf("\n%0.2f",b);
    float c =AREA(7);
    printf("\n%0.2f\n",c);
}/* define when used to define macros for constants,greatly increases the compactness and speed of the code,when compared to using a variable to define a 
constant value. Also makes the code more readable.*/ 