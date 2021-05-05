#include<iostream>  //SEE CODE IN C FOR AN EXAMPLE (passing 2d array to a function using pointers)
#include<vector>
using namespace std;
//C++ passes arrays to functions by reference—the called functions can modify the element values in the callers' original arrays.

/*WAYS OF PASSING 1-D ARRAY TO A FUNCTION.
Way-1
Formal parameters as a pointer as follows −

void myFunction(int *param) {
   .
   .
   .
}
Way-2
Formal parameters as a sized array as follows −

void myFunction(int param[10]) {
   .
   .
   .
}
Way-3
Formal parameters as an unsized array as follows −

void myFunction(int param[]) {
   .
   .
   .
}
Now, consider the following function, which will take an array as an argument along with another argument and based on the passed arguments, it will return average of the numbers passed through the array as follows −

double getAverage(int arr[], int size) {
  int i, sum = 0;       
  double avg;          

   for (i = 0; i < size; ++i) {
      sum += arr[i];
   }
   avg = double(sum) / size;

   return avg;
}
Now, let us call the above function as follows −

#include <iostream>
using namespace std;
 
// function declaration:
double getAverage(int arr[], int size);

int main () {
   // an int array with 5 elements.
   int balance[5] = {1000, 2, 3, 17, 50};
   double avg;

   // pass pointer to the array as an argument.
   avg = getAverage( balance, 5 ) ;
 
   // output the returned value 
   cout << "Average value is: " << avg << endl; 
    
   return 0;
}
*/
//FUCK THIS. JUST USE VECTORS. FUCK C++ FUCK EVERYONE.
//ARRAYS ARE NEVER PASSED BY VALUE,ALWAYS BY POINTER OR REFERENCE
void print_array(int [][5],int);
void print_mij(int *,int,int);
// void printSimpleWay(int memo[][],int dim1,int dim2); does not work.

//USE VECTORS. BEST
int print(vector<vector<int>> &arr)
{
    cout<<arr[53][61]<<endl;
    return 0;
}
int main()
{
    int m=71,n=65;
    vector<vector<int>> arr(m,vector<int>(n,17));   //initialising a 2d vector.
    //passing this vector to a function.
    cout<<print(arr);


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
    // 1-D ARRAY HAI TOH PASS NAME ONLY. 2-D ARRAY TOH NAME KE SAATH 1 DIMENSION(row dimension) BHI PASS KARNA HOGA.
    int memo[5][6]={0};
    //printSimpleWay(memo,5,6);
    //best hai,just declare the array as a global variable,then you wouldnt have to pass it around.
    //OR
    /*int **memo=new int*[6];   //memo is a pointer to an array of 6 integer pointers
    for(int i=0;i<6;i++)
    {
        int *ptr=new int[4];
        for(int j=0;j<4;j++)
            ptr[j]=0;
        memo[i]=ptr;
    }*/
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