#include<iostream>  //SEE CODE IN C FOR AN EXAMPLE (passing 2d array to a function using pointers)
using namespace std;

void print_array(int [][5],int);
void print_mij(int *,int,int);

int main()
{
    int m[][5]={{1,2,3,4,5},{6,7,8,9,10}};
    print_array(m,2); //not passed by value, passed as a pointer to the first element. therefore changes are made in the array directly.
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<5;j++)
        {
            cout<<m[i][j]<<"\t";
        }
    }
    cout<<"\n";
    print_mij(m[0],2,5); //just writing m causes a type error. this is a funda with 2-d arrays where passing just the name is not enough. you have
    //to pass it as m[0] only. clear explanation nahi diya hai.
    // 1-D ARRAY HAI TOH PASS NAME ONLY. 2-D ARRAY TOH NAME KE SAATH 1 DIMENSION(row dimemnsion) BHI PASS KARNA HOGA.
}

void print_array(int x[][5],int dim1)  //best to use pointers rather than x[][5] and other bullshit.
{
    for(int i=0;i<dim1;i++)
    {
        for(int j=0;j<5;j++)
        {
            x[i][j]+=2;
        }
    }
}
void print_mij(int *m, int dim1, int dim2) //correct solution if you want to pass both dimensions together. using print_array with x[][] is illegal.
{ //error dikhayega. so best to use pointers for multidimensional arrays.
for (int i = 0; i!=dim1; i++) {
for (int j = 0; j!=dim2; j++)
cout << m[i*dim2+j] << '\t'; // obscure. REMEMBER THIS EXPRESSION. This works because it is also converted to *(m+i*dim2 +j) just like the array m is
//converted from m[i][j] to *(*(m+i)+j) 
//i*dim2 is done so as to move from one row to the other.
//eg: dim1=2,dim2=5 in the above array. therefore to access the elements of second row(i=1),we get 1*5+j which gives m[5+j] which starts giving elements
//of the second row completely skipping the first row because of 5
}
}