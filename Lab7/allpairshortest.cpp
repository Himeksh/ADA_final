#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define INF INT_MAX

// Function to find the shortest paths between every pair of vertices using Floyd-Warshall algorithm
void floydWarshall(const vector<vector<int>>& graph) {
    int V = graph.size();
    vector<vector<int>> dist(V, vector<int>(V, 0));

    // Initialize distances based on the graph
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            dist[i][j] = graph[i][j];
        }
    }

    // Iterate through all vertices as intermediate vertices
    for (int k = 0; k < V; ++k) {
        // Pick all vertices as source one by one
        for (int i = 0; i < V; ++i) {
            // Pick all vertices as destination for the above picked source
            for (int j = 0; j < V; ++j) {
                // If vertex k is on the shortest path from i to j, then update the value of dist[i][j]
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distances
    cout << "Shortest distances between every pair of vertices:" << endl;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (dist[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    // Example graph represented as an adjacency matrix
    vector<vector<int>> graph = {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}
    };

    floydWarshall(graph);

   return 0;
}
