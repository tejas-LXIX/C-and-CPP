#include <bits/stdc++.h>

using namespace std;

/* Complete the encryption function below.  Test case 6 might fail because of Time limit exceeded. Submit karna wapas,succeed hojaayega.
roqfqeylxuyxjfyqterizzkhgvngapvudnztsxeprfp       INPUT
rlyzatp oxqkps quthvx fyegue qxrvdp ejinnr yfzgzf       OUTPUT*/
string encryption(string s) 
{
    int l=s.length(),min=INT_MAX;
    /*int rows=0,columns=0;
    if((floor(sqrt(l))*ceil(sqrt(l)))>=l && (floor(sqrt(l))*ceil(sqrt(l)))<min)
    {
        rows=floor(sqrt(l));
        columns=ceil(sqrt(l));
        min=rows*columns;
    }               this is what i had written to choose rows and columns. yeah ik testing with all possible values nahi kara meine.*/
    int rows = round(sqrt(l));
    int columns;
    if (rows >= sqrt(l)) columns = rows; else columns = rows + 1;       //ye samajh nahi aaya kaise choose kara hai.
    
    char arr[rows][columns];
    int itr=0;
    for(int i=0;i<rows,itr<l;i++)
    {
        for(int j=0;j<columns,itr<l;j++)
        {
            arr[i][j]=s[itr];
            itr++;
        }
    }
    string result,word;
    for(int j=0;j<columns;j++)
    {
        stringstream ss;
        for(int i=0;i<rows;i++)
        {
            if(arr[i][j]<'a' || arr[i][j]>'z')      //because test case "feedthedog" mein and in others too, one or two values of the array arr were remaining empty because the string is small. toh uske wajeh se ek extra space aa rha tha output mein humesha because that element in the array didnt have any value. isliye this is a condition to check for the empty value. agar woh garbage value koi character nahi hai,toh stringstream ss mein add hi nahi hoga.
                continue;
            ss<<arr[i][j];
        }
        ss>>word;
        result+=word;
        result+=" ";
    }
    return result;
}

int main()
{
    string s;
    getline(cin, s);
    string result = encryption(s);
    cout << result << "\n";
    return 0;
}
