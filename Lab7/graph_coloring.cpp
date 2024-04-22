 #include <iostream>
#include <vector>
using namespace std;
//color =current coloring of vertices
//v=current vertex
// Function to check if it's safe to assign the color 'c' to vertex 'v'
bool isSafe(int v, vector<vector<int>>& graph, vector<int>& color, int c) {
    for (int i = 0; i < graph.size(); ++i) {
        if (graph[v][i] && c == color[i])
            return false;
    }
    return true;
}

// Recursive function to solve m-coloring problem using backtracking
bool mColoringUtil(vector<vector<int>>& graph, int m, vector<int>& color, int v) {
    // Base case: if all vertices are assigned a color
    if (v == graph.size())
        return true;

    // Try assigning different colors to the vertex 'v'
    for (int c = 1; c <= m; ++c) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;
            // Recursive call for the next vertex
            if (mColoringUtil(graph, m, color, v + 1))
                return true;
            // Backtrack: remove color assignment if it doesn't lead to a solution
            color[v] = 0;
        }
    }
    return false;
}

// Function to solve m-coloring problem
bool mColoring(vector<vector<int>>& graph, int m) {
    int V = graph.size();
    vector<int> color(V, 0); // Initialize all colors as 0

    // Call the recursive function with the first vertex
    if (!mColoringUtil(graph, m, color, 0)) {
        cout << "Solution does not exist." << endl;
        return false;
    }

    // Print the solution
    cout << "Solution exists. The coloring of vertices is:" << endl;
    for (int i = 0; i < V; ++i)
        cout << "Vertex " << i << ": Color " << color[i] << endl;
    return true;
}

int main() {
    vector<vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };
    int m = 3; // Number of colors
    mColoring(graph, m);
     return 0;
}
