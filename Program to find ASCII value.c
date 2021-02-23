main()
{
    char a;
    printf("Please enter a single character: ");
    scanf("%c",&a);
    printf("ASCII value of %c=%d ",a,a);/*%c gives character value of a, whereas %d gives integer(ASCII) value of a.*/





    int m=3;
    int b=5;
    printf("\n%d",b/m);      /* therefore, its clear that the value is truncated, not rounded off.*/
    }
