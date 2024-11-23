#include <iostream>
#include <vector>
using namespace std;

void vertexCover(int V, int E, vector<pair<int, int>>& edges) {
    vector<bool> visited(V, false);  // To keep track of visited vertices
    vector<int> cover;               // To store the vertices in the vertex cover

    // Loop through each edge
    for (int i = 0; i < E; i++){

        int u = edges[i].first;
        int v = edges[i].second;

        if (!visited[u] && !visited[v]){
            visited[u] = true; cover.push_back(u);
            visited[v] = true; cover.push_back(v);
        }
    }

    // Output the result
    cout << "Vertex Cover: ";
    for (int v : cover) {
        cout << v << " ";
    }
    cout << endl;
}

int main() {
    int V = 5;
    int E = 6;
    vector<pair<int, int>> edges = {
        {0, 1}, {0, 2}, {1, 2}, {1, 3}, {2, 3}, {3, 4}
    };

    // Call the vertexCover function with hardcoded values
    vertexCover(V, E, edges);

    return 0;
}
