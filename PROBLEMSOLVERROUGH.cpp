#include <bits/stdc++.h>

using namespace std;

// Complete the substrCount function below.
long substrCount(int n, string s) {
    string str;
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            for(int k=i;k<=j;k++)
            {
                str+=s[k];
            }
            cout<<str<<endl;
            int l=str.length();
            
            if(l%2==0)
            {
                int p;
                for(p=1;p<l;p++)
                {
                    if(str[p]!=str[p-1])
                        break;
                }
                if(p==l)
                    count++;
            }
            else
            {
                int p;
                for(p=1;p<l;p++)
                {
                    if(p==l/2)
                    {
                        if(str[p+1]!=str[p-1])
                            break;
                    }
                    else if(p-1==l/2)
                    {}
                    else
                    {
                        if(str[p]!=str[p-1])
                            break;
                    }
                }
                if(p==l)
                    count++;
            }
            str="";
        }
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}