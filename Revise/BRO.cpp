#include<iostream>
using namespace std;
class Sally
{
    private:
        int x;
    public:
        Sally(int x)
        {
            this->x=x;
        }
        int returnVal()
        {
            return this->x;
        }
};
int main()
{
    Sally Tejas(71);
    cout<<Tejas.returnVal();
}