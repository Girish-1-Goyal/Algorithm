#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int src, dest, weight;
};

void bellmanFord(int V, int E, int src, vector<Edge>& edges) {
    // Step 1: Initialize distances
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Step 2: Relax edges V-1 times
    for (int i = 0; i < V - 1; ++i) {
        for (const auto& edge : edges) {
            int u = edge.src, v = edge.dest, w = edge.weight;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Step 3: Check for negative weight cycles
    for (const auto& edge : edges) {
        int u = edge.src, v = edge.dest, w = edge.weight;
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            cout << "Graph contains a negative weight cycle!" << endl;
            return;
        }
    }

    // Step 4: Print the distances
    cout << "Vertex\tDistance from Source" << endl;
    for (int i = 0; i < V; ++i) {
        cout << i << "\t" << dist[i] << endl;
    }
}

int main() {
    int V = 5, E = 8; // Number of vertices and edges
    vector<Edge> edges = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2},
        {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}
    };

    int source = 0;
    bellmanFord(V, E, source, edges);

    return 0;
}