/* Sending and receiving values between functions */
#include<stdio.h>
#include<math.h>

main()
{
int a,b,c,sum;
printf ( "\nEnter any three numbers " ) ;
scanf ( "%d %d %d",&a,&b,&c) ;
sum = calsum (a,b,c) ;
printf ( "\nSum = %d",sum) ;
}
calsum (int x,int y,int z)             /* first, the value of z is taken as 'c'. then value of y is taken as 'b'. then finally value of x is taken as 'a'.*/
{
int d ;
d = x+y+z;
return (d) ;
}
