/*  Prim's algorithm runs faster in dense graphs. Kruskal's algorithm runs faster in sparse graphs.
How does Prim’s Algorithm Work? The idea behind Prim’s algorithm is simple, a spanning tree means all vertices must be connected. So the two disjoint subsets (discussed above) of vertices must be connected to make a Spanning Tree. And they must be connected with the minimum weight edge to make it a Minimum Spanning Tree.
Algorithm 
1) Create a set mstSet that keeps track of vertices already included in MST. 
2) Assign a key value to all vertices in the input graph. Initialize all key values as INFINITE. Assign key value as 0 for the first vertex so that it is picked first. 
3) While mstSet doesn’t include all vertices 
….a) Pick a vertex u which is not there in mstSet and has minimum key value. 
….b) Include u to mstSet. 
….c) Update key value of all adjacent vertices of u. To update the key values, iterate through all adjacent vertices. For every adjacent vertex v, if weight of edge u-v is less than the previous key value of v, update the key value as weight of u-v. i.e keyvalue=weight of u-v
The idea of using key values is to pick the minimum weight edge from cut. The key values are used only for vertices which are not yet included in MST, the key value for these vertices
indicate the minimum weight edges connecting them to the set of vertices included in MST.
O(V^2) time complexity.
*/
#include<iostream>
#define V 5     //a graph of 5 vertices.
using namespace std;

int minKey(int key[],bool mstSet[])
{
    int min=INT_MAX;    //initialise the value of min and min_index.
    int min_index;
    for(int i=0;i<V;i++)    //iterates over all the vertices.
    {
        if(!mstSet[i] && key[i]<min)    //returns the vertex with minimum key value,from the given set of vertices not yet included in the MST.
            min=key[i],min_index=i;
    }
    return min_index;
}

void printMST(int parent[],int graph[V][V])
{
    cout<<"Edge \tWeight\n";
    for (int i = 1; i < V; i++)     //i=1 because parent[0]=-1 i.e parent of the root node does not exist.  
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";  //this basically tells you the parent of a particular node,as well as the weight of the edge connecting the node to its parent. Therefore,you get the required MST.
}

void primMST(int graph[V][V])
{
    int parent[V];      //to store the parent node of the edge that has been included in the MST. This is used to print the final MST.
    int key[V];     //to store the edge weights for each vertex. Is useful for picking the minimum weight edge from the remaining edges.
    bool mstSet[V]; //to represent the set of vertices already included in the MST(already visited).
    for(int i=0;i<V;i++)
    {
        key[i]=INT_MAX;     //initialise the key values with infinite
        mstSet[i]=false;    //initially,no nodes have been visited and the MST is empty.
    }
    key[0]=0;   //so that vertex 0 is picked first.
    parent[0]=-1;   //since root node has no parent.
    for(int i=0;i<V-1;i++)      //V-1 because MST always has only V-1 edges. This loop is to construct the MST,including one edge in the MST in each iteration.
    {
        int u=minKey(key,mstSet);   // Pick the minimum key vertex from the set of vertices not yet included in MST.
        mstSet[u]=true;     //since this vertex has now been included in the MST.
        // Update key value and parent index of the adjacent vertices of the picked vertex.Consider only those vertices which are not yet included in MST.
        for(int v=0;v<V;v++)
        {   //we are updating the key values for all the vertices that are connected to the vertex u.
            if(graph[u][v] && mstSet[v]==false && graph[u][v]<key[v])    // graph[u][v] isn't zero when an edge from u to v exists. mstSet[v] is false for vertices not yet included in MST.Update the key only if graph[u][v] is smaller than key[v].
            {
                parent[v]=u;
                key[v]=graph[u][v];
            }
        }  
    }
    printMST(parent,graph);
}
int main()
{
    /* Let us create the following graph  
        2 3  
    (0)--(1)--(2)   the brackets represent the vertex. and the numbers above the edges represent the edge weights.
    | / \ |  
    6| 8/ \5 |7  
    | / \ |  
    (3)-------(4)  
            9     */
    int graph[V][V]={ { 0, 2, 0, 6, 0 },  //a graph of 5 vertices. graph[i][j] represents the weight of the edge from ith vertex to jth vertex. 0 means no edge exists.
                    { 2, 0, 3, 8, 5 },  
                    { 0, 3, 0, 0, 7 },  
                    { 6, 8, 0, 0, 9 },      //this graph here is an undirected graph,because this matrix is equal to its transpose.
                    { 0, 5, 7, 9, 0 } }; 
    primMST(graph);
}