//SEE https://www.tutorialspoint.com/connected-vs-disconnected-graphs#:~:text=c%20d-,Disconnected%20Graph,component%20of%20the%20graph%20G for diff b/w connected/disconnected graph.
/*A spanning tree is a subset of Graph G, which has all the vertices covered with minimum possible number of edges. Hence, a spanning tree does not have cycles and it cannot be disconnected.
A connected graph G can have more than one spanning tree.

All possible spanning trees of graph G, have the same number of edges and vertices.

The spanning tree does not have any cycle (loops).

Removing one edge from the spanning tree will make the graph disconnected, i.e. the spanning tree is minimally connected.

Adding one edge to the spanning tree will create a circuit or loop, i.e. the spanning tree is maximally acyclic.

Given a connected and undirected graph, a SPANNING TREE of that graph is a subgraph that is a tree and connects all the vertices together. A single graph can have many different spanning trees.
A minimum spanning tree (MST) or minimum weight spanning tree for a weighted, connected and undirected graph is a spanning tree with weight less than or equal to the weight of every other spanning tree. The weight of a spanning tree is the sum of weights given to each edge of the spanning tree.
How many edges does a minimum spanning tree have? A minimum spanning tree has (V – 1) edges where V is the number of vertices in the given graph.
Below are the steps for finding MST using Kruskal’s algorithm
1. Sort all the edges in non-decreasing order of their weight. 
2. Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far. If cycle is not formed, include this edge. Else, discard it. BECAUSE,MST CANNOT FORM A CYCLE.
3. Repeat step#2 until there are (V-1) edges in the spanning tree.

A complete undirected graph is one in which each vertex is connected to all the other vertices. It can have n^(n-2) number of undirected graphs.

Algorithm for Kruskal's MST.
1. Sort all the edges in non-decreasing order of their weight. 
2. Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far. If cycle is not formed, include this edge. Else, discard it. 
3. Repeat step#2 until there are (V-1) edges in the spanning tree.
The algorithm is a Greedy Algorithm. The Greedy Choice is to pick the smallest weight edge that does not cause a cycle in the MST constructed so far.

O(ElogE) TIME COMPLEXITY
Prim's algorithm runs faster in dense graphs. Kruskal's algorithm runs faster in sparse graphs. This is because we have less vertices in dense graphs and more edges, so O(V^2) beats O(ElogE).
But, in sparse graphs, we have a lot of vertices and lesser edges. So, O(ElogE) beats O(V^2).
*/

#include<iostream>
using namespace std;

class 
{
    public:

};

int main()
{

}
