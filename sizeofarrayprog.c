#include <stdio.h>
/*
Add `int max_of_four(int a, int b, int c, int d)` here.
*/
int max_of_four(int,int,int,int);
int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);

    return 0;
}
int max_of_four(int a,int b,int c,int d)
{
    int array[4]={a,b,c,d};
    int length= sizeof array/sizeof(array[0]); /*has to be divided by size of any element of array. this is because sizeof returns size in bytes. therefore
    sizeofarray actually gives 16(4ints*4(size of int in bytes)). therefore to get 4, we divide by sizeof array[0]*/
    printf("%d\n",length);
    int max=array[0];
    for(int i=0;i<length;i++)
    {
        if(array[i]>max)
        {
            max=array[i];
        }
    }
    return max;
}