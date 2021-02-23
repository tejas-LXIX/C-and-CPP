#include<iostream>
using namespace std;

int main()
{
    int day,year,month,feb;
    cin>>day;
    cin>>year;
    if(year<1918)  //russian calendar changed in 1918
        feb=(year%4==0)?29:28;
    else if(year==1918)
        feb=16; //29-13
    else
    {
        if((year%4==0 && year%100!=0) || year%400==0)
            feb=29;
        else
            feb=28;
    }
    int days_in_month[]={31,feb,31,30,31,30,31,31,30,31,30,31};
    for(int i=0;i<12;i++)
    {
        if(day<days_in_month[i])
        {
            month=i+1;
            break;
        }
        else
            day=day-days_in_month[i];
    }
    cout<<day<<'/'<<month<<'/'<<year;
}