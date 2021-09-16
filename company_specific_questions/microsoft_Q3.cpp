#include<bits/stdc++.h>
using namespace std;

bool isObstruction(vector<string> &B,int i,int j)
{
    char val=B[i][j];
    if(val=='X' || val=='<' || val=='>' || val=='v' || val=='^')
        return true;
    return false;
}

pair<int,int> markWatched(vector<string> &B,vector<vector<bool>> &grid)
{
    pair<int,int> Assassin_pos;
    for(int i=0;i<B.size();i++)
    {
        for(int j=0;j<B[0].size();j++)
        {
            if(B[i][j]=='.')
                continue;
            else if(B[i][j]=='X')
                grid[i][j]=false;
            else if(B[i][j]=='^')
            {
                grid[i][j]=false;
                int k=i-1;
                while(k>=0)
                {
                    if(isObstruction(B,k,j))
                        break;
                    grid[k][j]=false;
                    k--;
                }
            }
            else if(B[i][j]=='v')
            {
                grid[i][j]=false;
                int k=i+1;
                while(k<B.size())
                {
                    if(isObstruction(B,k,j))
                        break;
                    grid[k][j]=false;
                    k++;
                }
            }
            else if(B[i][j]=='<')
            {
                grid[i][j]=false;
                int k=j-1;
                while(k>=0)
                {
                    if(isObstruction(B,i,k))
                        break;
                    grid[i][k]=false;
                    k--;
                }
            }
            else if(B[i][j]=='>')
            {
                grid[i][j]=false;
                int k=j+1;
                while(k<B[0].size())
                {
                    if(isObstruction(B,i,k))
                        break;
                    grid[i][k]=false;
                    k++;
                }
            }
            else
            {
                Assassin_pos.first=i;
                Assassin_pos.second=j;
            }
        }
    }
    for(int i=0;i<B.size();i++)
    {
        for(int j=0;j<B[0].size();j++)
        {
            cout<<grid[i][j];
        }
        cout<<endl;
    }
    return Assassin_pos;
}

bool solRecur(vector<vector<bool>> &grid,int i,int j)
{
    int n=grid.size(),m=grid[0].size();
    if(i==n || i<0)
        return false;
    if(j==m || j<0)
        return false;
    if(grid[i][j]==false)
        return false;
    if(i==n-1 && j==m-1)
        return true;
    else
    {
        grid[i][j]=false;
        return solRecur(grid,i+1,j) || solRecur(grid,i-1,j) || solRecur(grid,i,j+1) || solRecur(grid,i,j-1);
    }

}

bool solution(vector<string> &B)
{
    vector<vector<bool>> grid(B.size(),vector<bool>(B[0].size(),true));   //false represents that cell cannot be moved into. true represents that cell can be moved into safely.
    pair<int,int> Assassin_pos=markWatched(B,grid);     //marks all the positions in grid as safe(true) or unsafe(false) and returns the position of the Assassin
    return solRecur(grid,Assassin_pos.first,Assassin_pos.second);
}

int main()
{
    vector<string> B;
    for(int i=0;i<3;i++)    //this is only one testcase,i have forgotten the others.
    {
        string str;
        cin>>str;
        B.push_back(str);
    }
    if(solution(B))
        cout<<"Possible";
    else
        cout<<"Impossible";
    /*test input
    X.....>
    ..v..X.
    .>..X..
    A......



    ...Xv
    AX..^
    .XX..
    */
}