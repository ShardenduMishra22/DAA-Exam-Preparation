#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int solve(vector<vector<int>>& graph, int source, int destination) {
    int n = graph.size();
    vector<int> dp(n, INT_MAX);
    dp[destination] = 0; 

    for (int i = destination - 1; i >= source; i--) {
        for (int j = i + 1; j < n; j++) {
            if (graph[i][j] != INT_MAX && dp[j] != INT_MAX) {
                dp[i] = min(dp[i], graph[i][j] + dp[j]);
            }
        }
    }
    return dp[source]; 
}

int main() {
    int vertices, edges, stages, source, destination;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edges;
    cout << "Enter the number of stages: ";
    cin >> stages;

    // Initialize graph with INT_MAX indicating no direct path
    vector<vector<int>> graph(vertices, vector<int>(vertices, INT_MAX));

    cout << "Enter each edge (source, destination, weight):\n";
    for (int i = 0; i < edges; i++) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        graph[src][dest] = weight;
    }

    cout << "Enter the source node: ";
    cin >> source;
    cout << "Enter the destination node: ";
    cin >> destination;

    int shortestPath = solve(graph, source, destination);
    cout << "\nShortest path from node " << source << " to node " << destination << " = " << shortestPath << endl;

    return 0;
}