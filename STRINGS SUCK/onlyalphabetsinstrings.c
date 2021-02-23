/* C program to remove all the characters 
* from the alphanumeric string
*/

#include <stdio.h>
#include <string.h>

// This function removes all the chars
// used in the string passed and will leave
// only the alphanumeric characters
int RemoveChars(char *string)
{
	int length=0,i=0,j=0,k=0;

	length = strlen(string);

	for(i=0;i<length;i++)
	{
		for(j=0;j<length;j++)
		{
			if((string[j]>='a' && string[j]<='z') || (string[j]>='A' && string[j]<='Z')) //just put a ! if you want only alphabets and no digits.
			{
				for(k=j;k<length;k++)
				{ //string[k] actually means *(string+k)
					string[k] = string[k+1]; //if you have an alphabet in between, then that alphabet is replaced by the character next to in the array
                //this goes on till the end of the array and at the end and the character is pushed off after the '\0' also. therefore when we print the
                //string,the printing stops at '\0' and therefore the alphabets are not printed. 
				}
				length--;//the length of the array is not reduced,this only reduces the test condition for the for loops.
			}
		}
	}
}

// main function 
int main()
{
	char string[50]={0};

	printf("\nEnter the string : ");
	gets(string);

	// pass the string to the function
	RemoveChars(string);
	printf("Final string is : %s",string);
	return 0;
}
