#include<stdio.h>
main()
{
    char name[]={'H','A','E','S','L','E','R','\0'}; /* \0 is very important. It signifies the ending of the string and is the only way that functions that
    work with strings can know where the string ends. A string not terminated by \0 is just a simple array of characters.*/
    char name1[]="HAESLER12boing"; /*easier way of initialising string. \0 not required here. C inserts it automatically at the end.*/
    //you have to initialise strings where they were formed(except in structures where they can be given a value once in main and dont have to be initialised
    //in the strucutre definition). therefore, char name1[10];
    //                                         name1="tejas"    is not possible. it gives an error. (should be modifiable l value)
    // ARRAY IS NOT ASSIGNABLE. SO EK BAAR INITIALISE KARNE KE BAAD YOU CANT CHANGE BY USING = SIGN. YOU HAVE TO CHANGE INDIVIDUAL ELEMENTS ONE BY ONE
    int i=0;
    while(name[i]!='\0')
    {
        printf("%c",name[i]); /*general way of printing out a string. Doesnt require the length of the string.*/
        i++;
    }
    printf("\n");
    char *ptr;
    ptr=name1; /*base address of name1 is passed to ptr.*/
    ptr="movie 2 shjit"; /*ptr now stores base address of this new array.*/
    while(*ptr!='\0')
    {
        printf("%c",*ptr); /*referring to char elements of an array is same as referring to int elements of an array*/
        ptr++;
    }
    printf("\n%s",name); /*format specification to print out a string*/
    char name2[25]; /*the length of the string should not exceed the dimension of the character array.*/
    strcpy(name2,name);
    printf("enter a string: ");
    scanf("%s",name2); //scanf ke baad \n not required in printf because scanf automatically introduces a \n(newline) in the buffer.
    printf("%s",name2);
    printf("%c",name2[24]); /*if the string is less than 24 chars long,then this prints out garbage values*/
    int cha='9';
    printf(" %c\n",cha); /*prints 9*/ /*%d wouldve printed 57(ascii of 9)*/
    char ham[20]="Hey ";
    char ham1[20]="shithead";
    strcat(ham,ham1);
    printf("%s",ham);
}