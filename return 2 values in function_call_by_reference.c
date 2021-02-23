#include<stdio.h>
main()
{
    int r;
    float perimeter,area;
    scanf("%d",&r);
    dimension(r,&perimeter,&area);/*since we have to pass the address of the variables so that they can be manipulated from inside the dimension function.*/
    printf("perimeter= %0.2f and area= %0.2f",perimeter,area);
}
dimension(int x,float *y,float *z) /* *y because y has to be a pointer variable because it points to the address of perimeter */
/* float *y means y points to a floating variable i.e it contains the address of a floating variable. */
{
    *y=2*3.14*x;
    *z=3.14*x*x;
}
