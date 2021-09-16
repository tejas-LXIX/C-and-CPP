#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool isSafe(int i,int j,vector<vector<bool>> &visited)
{
    if(i<0 || i==visited.size() || j<0 || j==visited[0].size() || visited[i][j])
        return false;
    return true;
}

void BFS(vector<vector<int>> &grid,vector<vector<bool>> &visited,int i,int j)
{
    queue<pair<int,int>> q;
    q.push({i,j});
    visited[i][j]=true;
    int row_itr[4]={-1,0,1,0};
    int col_itr[4]={0,1,0,-1};
    while(!q.empty())
    {
        pair<int,int> cell=q.front();
        int x=cell.first,y=cell.second;
        cout<<grid[x][y]<<" ";
        q.pop();
        for(int i=0;i<4;i++)
        {
            if(isSafe(x+row_itr[i],y+col_itr[i],visited))
            {
                q.push({x+row_itr[i],y+col_itr[i]});
                visited[x+row_itr[i]][y+col_itr[j]]=true;
            }
        }
    }
}

int main()
{
    // Given input matrix
    vector<vector<int>> grid= { { 1, 2, 3, 4 },
                           { 5, 6, 7, 8 },
                           { 9, 10, 11, 12 },
                           { 13, 14, 15, 16 } };
 
    // Declare the visited array
    vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
 
    BFS(grid, visited, 0, 0);
 
    return 0;
}