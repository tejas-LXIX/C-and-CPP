#include<stdio.h>
main()
{
    int num[]={1,3,5,7,8,4};
    int i;
    int *ptr=num;
    for(i=0;i<6;i++)
    {
        printf("%d\n",*(num+i)); //num[i] gets converted to *(num+i) where num holds the base address of the array num.
        printf("%d\n",ptr[i]); //ptr[i] gets converted to *(ptr+i) where ptr holds the base address of num i.e &num[0]
        printf("%d\n",*(ptr+i));
        printf("\n");
    }
}
