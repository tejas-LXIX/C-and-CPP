#include<iostream>
#include<vector>
#include<stack>
using namespace std;
//in-degree of a vertex is the number of input edges of a vertex. out-degree of a vertex is the number of output edges of a vertex.
//Topological sort is basically,we print that vertex first which has the in-degree=0. We then delete this vertex(not actual deletion),basically we detach the vertex and all its output edges from the graph(IN OUR BRAIN ONLY).
//We then call the function again and repeat the same,always choosing the vertex with in-degree=0 and printing it.
//TOPOLOGICAL SORT ONLY WORKS FOR DIRECTED ACYCLIC GRAPHS.
//A directed acyclic graph is a directed graph that has no cycles.
//iss algo ka dry run karo to understand. Dry run waala graph is in the DSA folder.
class Graph
{
    int V;
    vector<int> *adj;
    void topologicalSortUtil(int v,bool visited[],stack<int> &Stack)
    {
        visited[v]=true;
        vector<int>::iterator itr;
        for(itr=adj[v].begin();itr!=adj[v].end();itr++)
        {
            if(!visited[*itr])
            {
                topologicalSortUtil(*itr,visited,Stack);    //call this recursive function for each unvisited vertex.
            }
        }
        Stack.push(v);  //A vertex is pushed to stack only when all of its adjacent vertices (and their adjacent vertices and so on) are already in the stack. 
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
    }
    void topologicalSort()
    {
        bool *visited=new bool[V];
        stack<int> Stack;
        for(int i=0;i<V;i++)
            visited[i]=false;
        for(int i=0;i<V;i++)    //starts from vertex 0.
        {
            if(visited[i]==false)
            {
                topologicalSortUtil(i,visited,Stack);   //calls the util function for each node.
            }
        }
        while(!Stack.empty())
        {
            cout<<Stack.top()<<" ";
            Stack.pop();
        }
    }

};

int main()
{
    Graph g(6); 
    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1); 
  
    cout << "Following is a Topological Sort of the given "
            "graph \n"; 
    
    // Function Call 
    g.topologicalSort(); 
  
    return 0; 
}