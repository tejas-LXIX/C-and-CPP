//BFS on an undirected graph.
//Time Complexity: O(V+E) where V is number of vertices in the graph and E is number of edges in the graph.
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Graph{
    int V;      //Number of vertices.
    vector<int> *adj;   //pointer to the adjacency list.
    public:
        Graph(int V)
        {
            this->V=V;
            adj=new vector<int>[V]; //dynamic allocation,since we dont know the number of vertices at compile time.
        }
        void addEdge(int u,int v)
        {
            adj[u].push_back(v);
        }
        void BFS(int s)     //prints BFS traversal from a given source s
        {
            bool *visited=new bool[V];      //To avoid processing a node more than once, we use a boolean visited array. For simplicity, it is assumed that all vertices are reachable from the starting vertex. 
            for(int i=0;i<V;i++)
                visited[i]=false;   //mark all vertices initially as not visited.
            queue<int> q;
            visited[s]=true;        //to mark the source node as visited,and then push it onto the queue.
            q.push(s);
            vector<int>::iterator itr;      //to get all the adjacent vertices of a vertex.
            while(!q.empty())   //the BFS algo stops when the queue is emptied fully.   //This is responsible for O(v). We visit all the vertices.
            {
                s=q.front();    //dequeue a vertex from the queue and print it.
                cout<<s<<" ";
                q.pop();
                // Get all adjacent vertices of the dequeued
                // vertex s. If a adjacent vertex has not been visited, 
                // then mark it visited and enqueue it.
                for(itr=adj[s].begin();itr!=adj[s].end();itr++)     //this is responsible for O(e). We visit all the edges of a given vertex.
                {
                    if(!visited[*itr])
                    {
                        visited[*itr]=true;
                        q.push(*itr);
                    }
                }
            }
        }
};

int main()
{
    Graph g(5);
    g.addEdge(0,4);
    g.addEdge(0,1);    
    g.addEdge(1,0);
    g.addEdge(1,2);
    g.addEdge(1,4);
    g.addEdge(2,3);
    g.addEdge(2,1);
    g.addEdge(3,2);
    g.addEdge(3,4);
    g.addEdge(4,3);
    g.addEdge(4,1);
    g.addEdge(4,2);
    g.BFS(3);
}