// A simple representation of graph using STL. A graph is always represented using an adjacency list usually,or sometimes an adjacency matrix.
//An acyclic graph is one which does not contain a cycle.
#include<bits/stdc++.h> 
using namespace std; 

// A utility function to add an edge in an 
// undirected graph. 
void addEdge(vector<int> adj[], int u, int v) 
{ 
	adj[u].push_back(v);    //push the node v into the u'th vector in adj.
	adj[v].push_back(u); 	//push the node u into the v'th vector in adj.
	//we do this because this is an undirected graph. So,an edge from u to v is also an edge from v to u.
} 

// A utility function to print the adjacency list 
// representation of graph 
void printGraph(vector<int> adj[], int V) 
{ 
	for (int v = 0; v < V; ++v) 
	{ 
		cout<<"\n Adjacency list of vertex "<<v<<"\n head "; 
		for (auto x : adj[v]) 
			cout << "-> " << x; 
		printf("\n"); 
	} 
} 

// Driver code 
int main() 
{ 
	int V = 5; 
	vector<int> adj[V];     //an array of integer vectors. Adjacency List to represent a graph.
	addEdge(adj, 0, 1); 
	addEdge(adj, 0, 4); 
	addEdge(adj, 1, 2); 
	addEdge(adj, 1, 3); 
	addEdge(adj, 1, 4); 
	addEdge(adj, 2, 3); 
	addEdge(adj, 3, 4); 
	printGraph(adj, V); 
	return 0; 
} 
