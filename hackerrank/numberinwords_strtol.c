#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h> /*takes a number as input and writes it in lowercase*/
#include <stdlib.h>
#include <string.h>

char* readline();
int main()
{
    char* n_endptr;
    char* n_str = readline(); /*the pointer n_str becomes equal to the pointer char pointer data*/
    int n = strtol(n_str, &n_endptr, 10);/*strtol converts a string to a long integer. n_str is the pointer to the string. therefore,the base address 
    of the string has been passed. &n_endptr is to tell the function where to stop the conversion. 10 is the the base of the number to be converted*/
    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }/*test case to see if the user has input nothing or has input a string without
    following the correct way of putting \0 at the end.*/
    else
    {
        if(n==1)
        {
            printf("one");
        }
        else if(n==2)
        {
            printf("two");
        }
        else if(n==3)
        {
            printf("three");
        }
        else if(n==4)
        {
            printf("four");
        }
        else if(n==5)
        {
            printf("five");
        }
        else if(n==6)
        {
            printf("six");
        }
        else if(n==7)
        {
            printf("seven");
        }
        else if(n==8)
        {
            printf("eight");
        }
        else if(n==9)
        {
            printf("nine");
        }
        else {
        printf("Greater than 9");
        }
    }

    // Write Your Code Here

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}
