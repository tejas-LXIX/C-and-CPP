#include<stdio.h>
void shithead();
int * fun(); /*static variables are initialised and allocated memory during compilation. auto variables are initialised and allocated memory during runtime.*/
int lg=3;
int ng=7; /*declaration of a global variable*/
int main()     /*static variables persist. they dont die even after the function that called them is no longer active.
               A STATIC VARIABLE REMAINS IN MEMORY THE WHOLE TIME THE PROGRAM IS RUNNING*/
{              /*Static variables have a property of preserving their value even after they are out of their scope!
Hence, static variables preserve their previous value in their previous scope and are not initialized again in the new scope.
But their scope is local to the block in which it is defined.*/
/*EXTERNAL variables ka SCOPE is GLOBAL.*/
    shithead();
    shithead();
    int *j;
    j=fun();
    printf("%d\n",*j);
    int lg=4;
    printf("%d\n",lg); /*local variables have precedence over external variables. therefore 4 is printed.*/
    printf("%d\n",ng); 
}
void shithead()
{
    static int count; /*Static variables are always initialised to 0.
    To count the no. of times a function has been run,auto vars cant be used. this is because auto variables will get initialised everytime
    the function is called. but static variables are only initialised ONCE. after that their value persists between different function calls.
    therefore they can be used to count the no. of times a program has been run.*/
    count++;
    printf("the function has run %d times\n",count);
}
int * fun()
{
    static int k=35; /*agar yahan pe static nahi hota,then k would've died the moment the control returned from fun*/
    return &k;
}