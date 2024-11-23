#include<bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int>> solve(vector<vector<int>>& vec, int vrt, int edgs) {
    unordered_map<int, list<pair<int, int>>> adj;
    
    // Build the adjacency list
    for(int i = 0; i < edgs; i++) {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> parent(vrt, -1);
    vector<int> key(vrt, INT_MAX);
    vector<bool> mst(vrt, false);

    key[0] = 0;  // Starting from vertex 0
    parent[0] = -1;

    // Priority queue to select the minimum key vertex (u, key[u])
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});  // Push the starting vertex with its key value

    while(!pq.empty()) {
        int node = pq.top().second; // get node with min key 
        pq.pop();

        mst[node] = true;

        // Explore all adjacent vertices of the current node
        for(auto i : adj[node]) {
            int nextNode = i.first;
            int nextDist = i.second;

            // If nextNode is not in MST and the edge weight is smaller than the current key[nextNode]
            if(!mst[nextNode] && nextDist < key[nextNode]) {
                key[nextNode] = nextDist;
                parent[nextNode] = node;
                pq.push({key[nextNode], nextNode});  // Push the updated key and vertex to the priority queue
            }
        }
    }

    // Prepare the result with edges (u, v) and their weights
    vector<pair<pair<int, int>, int>> result;
    for(int i = 1; i < vrt; i++) {
        result.push_back({{parent[i], i}, key[i]});
    }

    return result;
}

int main() {
    // Example graph
    vector<vector<int>> vec = {
        {0, 1, 2}, {0, 3, 6}, {1, 3, 8}, {1, 2, 3}, 
        {1, 4, 5}, {2, 4, 7}, {3, 4, 9}
    };

    int vrt = 5;  // Number of vertices
    int edgs = vec.size();  // Number of edges

    vector<pair<pair<int, int>, int>> mst = solve(vec, vrt, edgs);

    // Print the MST edges and their weights
    for(auto edge : mst) {
        cout << "Edge: (" << edge.first.first << ", " << edge.first.second << "), Weight: " << edge.second << "\n";
    }

    return 0;
}
