#include<stdio.h>
//structures represent entities that are a collection of dissimilar data types. structures are derived data types(derived from the user)
struct book //structure type declaration does not tell the compiler to reserve any memory. memory is reserved only when variables are created that 
//are of the type struct book
{
    char name[10]; //elements of the structure
    float price;
    int pages;
};

int main()
{
    struct book b1,b2,b3={"C",175.69,300}; //declaration of variable of type struct book. makes space available to hold all the elements in the structure
    //in this case 9 (1 for char,4 for int and 4 for float) bytes each are allocated for the variables b1,b2,b3    
//all the elements of each variable are stored in contiguous memory locations. but the variables aren't necessarily stored in contiguous memory locations.
    //b2.name="Tejas"  is wrong. gives error. this is because ARRAYS ARE NOT ASSIGNABLE. CANT CHANGE VALUES OF AN ARRAY USING =. YOU HAVE TO USE FUNCTIONS
    //TO CHANGE THE ELEMENTS ONE BY ONE.
    
    printf("%s %f %d",b3.name,b3.price,b3.pages); //to access the individual elements of the variable b3 of type   "struct book"
    printf("enter the details of first book ");
    scanf("%s %f %d",&b1.name,&b1.price,&b1.pages);
    printf("%s %0.2f %d ",b1.name,b1.price,b1.pages); 

    struct book d[2]; //ARRAY OF STRUCTURES. all elements of the array are stored in contiguous memory locations like a normal array.
    for(int i=0;i<2;i++)
    {
        scanf("%s %f %d",&d[i].name,&d[i].price,&d[i].pages);
    }
    for(int i=0;i<2;i++)
    {
        printf("%s %0.2f %d",d[i].name,d[i].price,d[i].pages);
    }
    b1.price=b3.price; //copying one by one
    strcpy(b1.name,b3.name);  //b1.name=b3.name is not possible. error dega
    b2=b1; //copying everything all at once
}