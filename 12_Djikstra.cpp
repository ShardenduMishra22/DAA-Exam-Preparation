#include <bits/stdc++.h>
using namespace std;

vector<int> Dijkstra(vector<vector<int>>& vec, int vrt, int edgs, int src) {
    unordered_map<int, list<pair<int, int>>> adj;

    for (int i = 0; i < edgs; i++) {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> dist(vrt, INT_MAX);
    dist[src] = 0;

    set<pair<int, int>> s;
    s.insert({0, src});

    while (!s.empty()) {
        auto p = *(s.begin());
        int nodeDist = p.first; // Current shortest distance to the node
        int node = p.second;    // Current node

        s.erase(s.begin());

        for (auto neighbour : adj[node]) {
            int nextNode = neighbour.first; // Adjacent node
            int weight = neighbour.second; // Weight of the edge to the adjacent node

            // If a shorter path to the adjacent node is found
            if (nodeDist + weight < dist[nextNode]) {
                auto it = s.find({dist[nextNode], nextNode});
                if (it != s.end()) {
                    s.erase(it); // Remove the outdated distance
                }

                dist[nextNode] = nodeDist + weight;
                s.insert({dist[nextNode], nextNode});
            }
        }
    }

    return dist;
}

int main() {
    vector<vector<int>> vec = {
        {0, 1, 7}, {0, 2, 1}, {1, 3, 5},
        {1, 4, 1}, {1, 2, 3}, {4, 3, 7},
        {3, 0, 2}
    };

    int vrt = 5; // Number of vertices
    int edgs = vec.size(); // Total number of edges
    int src = 0; // Source vertex

    vector<int> result = Dijkstra(vec, vrt, edgs, src);
    for (int i = 0; i < result.size(); i++) {
        if (result[i] == INT_MAX)
            cout << "Vertex " << i << ": INF\n";
        else
            cout << "Vertex " << i << ": " << result[i] << "\n";
    }

    return 0;
}
