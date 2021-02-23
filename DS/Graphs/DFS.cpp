#include<iostream>  //To avoid processing a node more than once, we use a boolean visited array. For simplicity, it is assumed that all vertices are reachable from the starting vertex. 
#include<vector>
using namespace std;

//Time complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph.

class Graph{
    int V;
    vector<int>* adj;   //pointer to the adjaceny list.
    public:
        Graph(int V)
        {
            this->V=V;
            adj=new vector<int>[V];
        }
        void addEdge(int v,int w)   //directed graph
        {
            adj[v].push_back(w);
            adj[w].push_back(v);
        }
        void DFSUtil(int s,bool visited[])  //Recursive function call for DFS. Goes through each and every node and 
        {
            visited[s]=true;    //mark current node as visited and print it.
            cout<<s<<" ";
            vector<int>::iterator itr;
            for(itr=adj[s].begin();itr!=adj[s].end();itr++)   //Recur for all the vertices adjacent to this vertex.
            {
                if(!visited[*itr])  //if the node has not been visited,then call the DFSUtil function on it.
                    DFSUtil(*itr,visited);
            }
        }
        void DFS(int s) //DFS of the vertices reachable from the vertex v. v is basically the root node from where to conduct a DFS search. It's our choice.
        {
            bool* visited=new bool[V];
            for(int i=0;i<V;i++)
                visited[i]=false;
            DFSUtil(s,visited);
        }
};
int main()
{
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,3);
    g.addEdge(1,2);
    g.addEdge(1,6);
    g.addEdge(2,3);
    g.addEdge(2,4);
    g.addEdge(2,5);
    g.addEdge(3,4);
    g.addEdge(4,6);
    g.DFS(0);
}