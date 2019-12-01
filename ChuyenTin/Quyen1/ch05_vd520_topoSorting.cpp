#include <iostream> 
#include <limits.h> 
#include <list> 
#include <stack> 
#define NINF INT_MIN 
using namespace std; 
class AdjListNode {  
    int v;  
    int weight;      
  public:  
    AdjListNode(int _v, int _w)  
    {  
        v = _v;  
        weight = _w;  
    }  
    int getV() { return v; }  
    int getWeight() { return weight; }  
};  
class Graph {  
    int V;
    list<AdjListNode>* adj;
    void topologicalSortUtil(int v, bool visited[],  
                             stack<int>& Stack);  
    
  public:  
    Graph(int V); // Constructor  
    ~Graph(); // Destructor 
    void addEdge(int u, int v, int weight); 
    void longestPath(int, int);  
};  
    
Graph::Graph(int V) // Constructor  
{  
    this->V = V;  
    adj = new list<AdjListNode>[V];  
}  
  
Graph::~Graph() // Destructor  
{  
    delete [] adj;  
}  
  
  
void Graph::addEdge(int u, int v, int weight)  
{  
    AdjListNode node(v, weight);  
    adj[u].push_back(node); // Add v to u's list  
}
void Graph::topologicalSortUtil(int v, bool visited[],  
                                stack<int>& Stack)  
{
    visited[v] = true;
    list<AdjListNode>::iterator i;  
    for (i = adj[v].begin(); i != adj[v].end(); ++i) {  
        AdjListNode node = *i;  
        if (!visited[node.getV()])  
            topologicalSortUtil(node.getV(), visited, Stack);  
    }
    Stack.push(v);  
}
void Graph::longestPath(int s, int t)  
{  
    stack<int> Stack; 
    int dist[V];
    bool* visited = new bool[V];  
    for (int i = 0; i < V; i++)  
        visited[i] = false;
        
    for (int i = 1; i < V; i++)  
        if (visited[i] == false)  
            topologicalSortUtil(i, visited, Stack);  
    
    for (int i = 0; i < V; i++)  
        dist[i] = NINF;  
    dist[s] = 0;  
     
    while (Stack.empty() == false) {    
        int u = Stack.top();  
        Stack.pop();  
    
        list<AdjListNode>::iterator i;  
        if (dist[u] != NINF) {  
            for (i = adj[u].begin(); i != adj[u].end(); ++i)  
                if (dist[i->getV()] < dist[u] + i->getWeight())  
                    dist[i->getV()] = dist[u] + i->getWeight();  
        }  
    }  
    for(int t = 1; t < V; t++)
    	cout << dist[t] << endl;
      
    delete [] visited; 
}  
    
int main()  
{  
	int n, m, A, B;
	cin >> n >> m >> A >> B;
    Graph g(n + 1);
	int u, v;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		g.addEdge(u, v, 1);
		g.addEdge(v, u, 1);
	}   
    g.longestPath(A, B);  
    return 0;  
} 
/*
10 12 2 5
1 10
10 9
9 8
8 7
7 6
6 5
5 4
4 6
6 10
10 3
3 2
2 1
*/
