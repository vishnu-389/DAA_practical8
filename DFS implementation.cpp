#include <iostream>
#include <vector>
using namespace std;

void DFS(int node, vector<vector<int>>& graph, vector<bool>& visited)
{
    // Mark current node as visited
    visited[node] = true;

    // Print current node
    cout << node << " ";

    // Visit all connected nodes
    for (int next : graph[node])
    {
        if (!visited[next])
        {
            DFS(next, graph, visited);
        }
    }
}

int main()
{
    int n, e;

    // Number of vertices
    cout << "Enter number of vertices: ";
    cin >> n;

    // Create graph
    vector<vector<int>> graph(n);

    // Number of edges
    cout << "Enter number of edges: ";
    cin >> e;

    // Enter edges
    cout << "Enter edges:\n";

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;

        // Undirected graph
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // Starting vertex
    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    // Visited array
    vector<bool> visited(n, false);

    // DFS traversal
    cout << "\nDFS Traversal: ";

    DFS(start, graph, visited);

    cout << endl;

    return 0;
}
