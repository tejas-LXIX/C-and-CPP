#include<iostream>
using namespace std;
int main() {
   int num1, num2, carry;
   cout << "Enter first number:"<<endl;
   cin >> num1;
   cout << "Enter second number:"<<endl;
   cin >> num2;

   while (num2 != 0) {
      carry = num1 & num2;
      num1 = num1 ^ num2;
      num2 = carry << 1;   //to add negative numbers too, write (unsigned int)carry<<1;      IDK HOW BUT THIS WORKS!
   }
   cout << "The Sum is: " << num1;
   return 0;
}