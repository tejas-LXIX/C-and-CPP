#include<iostream>

int main()
{
    int j=6;
    for(int i=0;i<j;i++) //for j=6, pairs are i,j={{0,6},{1,5},{2,4}}. {3,3} pe i<j condition becomes false,so the loop exits
    {
        std::cout<<i;
        j--;
    }
}