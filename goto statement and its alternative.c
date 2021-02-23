#include<stdio.h>
#include<conio.h>
main()
{
 int i, j, k ;
 for ( i = 1 ; i <= 3 ; i++ )
 {
 for ( j = 1 ; j <= 3 ; j++ )
 {
 for ( k = 1 ; k <= 3 ; k++ )
 {
 if ( i == 3 && j == 3 && k == 3 )
 goto out ;
 else
 printf ( "%d %d %d\n", i, j, k ) ;
 }
 }
 }
 out :
 printf ( "Out of the loop at last!" ) ;
/*now doing the same without goto(using logical if-else statements). IT IS ALWAYS BETTER TO NOT USE GOTO. */
printf("\n\n now the same thing without using goto\n");
for ( i = 1 ; i <= 3 ; i++ )
 {
    for ( j = 1 ; j <= 3 ; j++ )
    {
        for ( k = 1 ; k <= 3 ; k++ )
        {
            if (k == 3 )
                {
                    break;
                }
            else
            printf ( "%d %d %d\n", i, j, k ) ;
        }
    if(j==3)
        {
            break;
        }
    }
 if(i==3)
    {
        break;
    }
 }

 printf ( "Out of the loop at last!" ) ;
}
