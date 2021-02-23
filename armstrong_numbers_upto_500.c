#include<stdio.h>
#include<math.h>

int main()
{
    int i;
    for(i=2;i<500;i++)
    {
        int number, sum = 0, rem = 0, cube = 0, temp;
        number=i;
        temp = number;
        while (number != 0)
        {
            rem = number % 10;
            cube = pow(rem, 3);
            sum = sum + cube;
            number = number / 10;
        }
        if (sum == temp)
            {
                printf ("%d\n",temp);
            }
    }
}
