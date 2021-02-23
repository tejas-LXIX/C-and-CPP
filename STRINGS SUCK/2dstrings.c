/* Exchange names using 2-D array of characters */
void main( )
{
char names[ ][10] = {
"akshay",
"parag",
"raman",
"srinivas",
"gopal",
"rajesh"
} ;
int i ;
char t ;
printf ( "\nOriginal: %s %s", &names[2][0], &names[3][0] ) ;
for ( i = 0 ; i <= 9 ; i++ )
{
t = names[2][i] ;
names[2][i] = names[3][i] ; //here the strings have been actually interchanged one character at a time. requires 10 exchanges. slow
names[3][i] = t ;
}
printf ( "\nNew: %s %s", &names[2][0], &names[3][0] ) ;






char *names1[ ] = {  /* names1[] is an array of char pointers. It contains base addresses of respective names. That is, base address of “akshay” is
stored in names[0], base address of “parag” is stored in names[1] and so on.*/
//this is more memory efficient as the memory usedd by each string is according to how much it needs,not the memory of 10 bytes each as allocated above.
//but this is risky if you want to change the values of the name so best to not do this
"akshay",
"parag",
"raman",
"srinivas",
"gopal",
"rajesh"
} ;
char *temp ;
printf ( "\nOriginal: %s %s", names1[2], names1[3] ) ;
temp = names1[2] ;
names1[2] = names1[3] ; //only the pointers point to different strings(have been interchanged) of the 2d string array now. 
//the strings haven't been interchanged. requires only one exchange. therefore faster than the above method
names1[3] = temp ;
printf ( "\nNew: %s %s", names1[2], names1[3] ) ;

}

