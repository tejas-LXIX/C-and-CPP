#include<iostream>
#include<vector>
using namespace std;
//the only way to understand this algorithm is to do a dry run of it with a simple 3 node graph. You will understand how it works.

class Graph
{
    int V;
    vector<int> *adj;
    bool isCyclicUtil(int v,bool visited[],bool recstack[])
    {
        if(visited[v]==false)
        {   //mark the current node as visited and part of the recursion stack.
            visited[v]=true;
            recstack[v]=true;       //we need this stack to know if a particular node has been visited or not,and if it has not been popped out yet. This is there to check if our path is going back to a node which is one of its parent nodes in this traversal,meaning that its going back to where it started from in a cycle.
            vector<int>::iterator itr;
            for(itr=adj[v].begin();itr!=adj[v].end();itr++)
            {
                if(!visited[*itr] && isCyclicUtil(*itr,visited,recstack))   //if the adjacent vertex of v has not been visited yet OR the recursive call isCyclicUtil returns false.
                    return true;
                else if(recstack[*itr]) //if the node adjacent to node v, is a part of the recursion stack,meaning that it is a part of our path and we have basically reached back to it. This implies that a cycle exists.
                    return true;
            }
            recstack[v]=false;
            return false;
        }
    }
    public:
    Graph(int V)
    {
        this->V=V;
        adj=new vector<int>[V];
    }
    void addEdge(int v,int w)
    {
        adj[v].push_back(w);
        adj[w].push_back(v);    //IF YOU REMOVE THIS LINE,YOU MAKE THE GRAPH A DIRECTED GRAPH. Doing so will return "Graph doesnt contain cycle for the code in int main()". If you kepe it,then cycle exists.
    }
    bool isCyclic()     // Mark all the vertices as not visited and not part of recursion stack
    {
        bool* visited=new bool[V];
        bool *recstack=new bool[V];
        for(int i=0;i<V;i++)
        {
            visited[i]=false;
            recstack[i]=false;
        }
        for(int i=0;i<V;i++)     //Call the recursive helper function to detect cycle in different DFS trees
        {
            if(isCyclicUtil(i,visited,recstack))
                return true;
        }
        return false;
    }

};

int main()
{
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(0,3);
    if(g.isCyclic()) 
        cout << "Graph contains cycle"; 
    else
        cout << "Graph doesn't contain cycle";
}

/*Graph g(3);     //dry run the algo yourself with this graph. you will understand how the algo works.
    g.addEdge(0,1);
    g.addEdge(1,2);
    if(g.isCyclic()) 
        cout << "Graph contains cycle"; 
    else
        cout << "Graph doesn't contain cycle"; */