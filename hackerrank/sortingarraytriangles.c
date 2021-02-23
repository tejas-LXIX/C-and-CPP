#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
void sort_by_area(triangle *tr,int n)
{
    float p;
    int area[n];
    int a,b,c;
    for(int i=0;i<n;i++)
    {
        a=tr[i].a; // *(tr[i].a) is not used. this is because internally, the C compiler
        //treats tr[i] as *(tr+i) where tr is the pointer that contains the address
        //the array that has been created in main()
        b=tr[i].b;
        c=tr[i].c;
        p=(a+b+c)/2.0;
        area[i]=p*(p-a)*(p-b)*(p-c);
    }
    triangle temp;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(area[i]>area[j])
            {
                temp=tr[i];
                tr[i]=tr[j];
                tr[j]=temp;
            }
        }
    }
	/**
	* Sort an array a of the length n
	*/
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}