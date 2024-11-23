#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX

// Bellman-Ford Algorithm
bool solve(int n, vector<vector<int>>& edges, int src, vector<int>& dist) {
    dist[src] = 0;

    for(int i=1;i<n;i++){
        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if(dist[u] != INF && dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }

    for(auto& edge : edges){
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        if(dist[u] != INF && dist[u] + w < dist[v]){
            cout<<"-ve cycle detected"<<endl;
            return false;
        }
    }

    return true;
}

int main() {
    // Number of vertices and edges
    int n = 5, e = 8;
    
    // Edges represented as (u, v, weight)
    vector<vector<int>> edges = {
        {0, 1,-1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3,-3}
    };

    vector<int> dist(n, INF);

    int source = 0;

    if (solve(n, edges, source, dist)) {
        // Print shortest distances from the source
        cout << "Shortest distances from source vertex " << source << " are:" << endl;
        for (int i = 0; i < n; i++) {
            if (dist[i] == INF) {
                cout << "INF ";
            } else {
                cout << dist[i] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
