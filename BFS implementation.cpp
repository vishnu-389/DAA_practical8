#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BFS Function
void BFS(int start, vector<vector<int>>& graph)
{
    int n = graph.size();

    // Visited array
    vector<bool> visited(n, false);

    // Queue for BFS
    queue<int> q;

    // Mark starting node as visited
    visited[start] = true;

    // Insert starting node into queue
    q.push(start);

    // Continue until queue becomes empty
    while (!q.empty())
    {
        // Get front node
        int node = q.front();
        q.pop();

        // Print current node
        cout << node << " ";

        // Visit all connected nodes
        for (int next : graph[node])
        {
            if (!visited[next])
            {
                visited[next] = true;
                q.push(next);
            }
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

    // BFS traversal
    cout << "\nBFS Traversal: ";

    BFS(start, graph);

    cout << endl;

    return 0;
}
