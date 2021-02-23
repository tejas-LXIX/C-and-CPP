/*Algorithm         Also see notes at the end.
1) Create a set sptSet (shortest path tree set) (which is almost like a visited[] set that we have used earlier) that keeps track of vertices included in shortest path tree, i.e., whose minimum distance from source is calculated and finalized. Initially, this set is empty.
2) Assign a distance value to all vertices in the input graph. Initialize all distance values as INFINITE. Assign distance value as 0 for the source vertex so that it is picked first.
3) While sptSet doesn’t include all vertices
….a) Pick a vertex u which is not there in sptSet and has minimum distance value. Basically,the vertex which hasnt been visited yet and is also the closest from the source out of the given unvisited vertices.
….b) Include u to sptSet.
….c) Update distance value of all adjacent vertices of u. To update the distance values, iterate through all adjacent vertices. For every adjacent vertex v, if sum of distance value of u (from source) and weight of edge u-v, is less than the distance value of v, then update the distance value of v.*/

#include<iostream>
#include<vector>
using namespace std;
#define V 9
// A utility function to find the vertex with minimum distance value, from the set of vertices not yet included in shortest path tree
int closestUnvisitedVertex(int dist[],bool sptSet[])
{
    int min_index,min_dist=INT_MAX; //initialising the min_dist with infinity.
    for(int i=0;i<V;i++)
    {
        if(!sptSet[i] && dist[i]<min_dist)  //this loop gives us the closest unvisited vertex to the source.
            min_dist=dist[i],min_index=i;
    }
    return min_index;
}

void printSolution(int dist[])  //to print the final dist array which contains the minimum distance of each node from the source.
{
    cout<<"Vertex \t\t Distance from Source\n";
    for(int i=0;i<V;i++)
        cout<<i<<"\t\t"<<dist[i]<<endl;
}

void dijkstra(int graph[V][V],int src)      //You can decide the source node.
{
    int dist[V]; // The output array.  dist[i] will hold the shortest distance from src to i.
  
    bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest path tree or shortest distance from src to i is finalized.
    for(int i=0;i<V;i++)    // Initialize all distances as INFINITE and stpSet[] as false .
    {
        dist[i]=INT_MAX;
        sptSet[i]=false;
    }
    dist[src]=0;  //distance of source node is 0.
    for(int i=0;i<V-1;i++)  //V-1 since last node will obviously have no more nodes left to process.
    {
        int u=closestUnvisitedVertex(dist,sptSet);  // Pick the minimum distance vertex from the set of vertices not yet processed. u is always equal to src in the first iteration.
        sptSet[u]=true;     //since we have now visited the vertex u.
        
        for(int v=0;v<V;v++)        //update dist values of the adjacent vertices of the chosen vertex.
        {
            if(!sptSet[v] && graph[u][v] && dist[u]+graph[u][v]<dist[v]) //1. if the vertex has not been visited yet. 2. If an edge exists from u to v. 3. If the distance of u plus the distance between u and v is less than the existing distance of v from source
            {   // Update dist[v] only if is not in sptSet, there is an edge from u to v, and total weight of path from src to  v through u is smaller than current value of dist[v].
                dist[v]=dist[u]+graph[u][v];
            }
        }
    }
    printSolution(dist);
}
int main() 
{ 
    /* Let us create the example graph discussed above. See the example graph on https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/ */
    int graph[9][9] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
    
    dijkstra(graph,0);
  
    return 0; 
} 

/*Notes:
1) The code calculates shortest distance, but doesn’t calculate the path information. We can create a parent array, update the parent array when distance is updated (like prim’s implementation) and use it show the shortest path from source to different vertices.

2) The code is for undirected graph, same dijkstra function can be used for directed graphs also.

3) The code finds shortest distances from source to all vertices. If we are interested only in shortest distance from the source to a single target, we can break the for the loop when the picked minimum distance vertex is equal to target (Step 3.a of the algorithm).

4) Time Complexity of the implementation is O(V^2). If the input graph is represented using adjacency list, it can be reduced to O(E log V) with the help of binary heap. Please see
Dijkstra’s Algorithm for Adjacency List Representation for more details.

5) Dijkstra’s algorithm doesn’t work for graphs with negative weight cycles, it may give correct results for a graph with negative edges. For graphs with negative weight edges and cycles, Bellman–Ford algorithm can be used/.
*/