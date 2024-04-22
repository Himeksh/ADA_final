# 1-Kruskal's Algorithm Implementation

This C++ code implements Kruskal's algorithm to find the minimum spanning tree (MST) of a given weighted undirected graph.

## Description

The code performs the following tasks:

1. **Kruskal's Algorithm**: It implements the Kruskal's algorithm to find the minimum spanning tree of a graph.
2. **Heapify Function**: It defines a function to heapify an array of edges based on their weights.
3. **Disjoint Set**: It defines a disjoint set data structure with union-find operations to determine the connectivity of vertices.
4. **Input**: It prompts the user to enter the number of edges and the source, destination, and weight of each edge.
5. **Output**: It prints the edges chosen in the minimum spanning tree (MST).

## Time Complexity

- **Heapify Function**: O(log N)
- **Build Heap Function**: O(N)
- **Kruskal's Algorithm**: O(E log E) + O(E log V), where E is the number of edges and V is the number of vertices. The first part is for sorting the edges based on their weights, and the second part is for the union-find operations.

## Functions

### `void Heapify(Edge edge[], int i, int N)`

This function heapifies the array of edges `edge[]` starting from the index `i` up to `N`.

### `void build_heap(Edge edge[], int n)`

This function builds a max-heap of the edges array `edge[]` of size `n`.

### `void kruskal(Edge edge[], int n, int **t)`

This function applies Kruskal's algorithm to find the minimum spanning tree. It populates the 2D array `t` with the chosen edges.

## Instructions

1. Compile the code using a C++ compiler.
2. Run the executable.
3. Enter the number of edges and input the source, destination, and weight of each edge as prompted.
4. View the chosen edges in the minimum spanning tree (MST) printed by the program.

# 2-Prims Algorithm Implementation

This C++ code implements Prim's algorithm to find the minimum spanning tree (MST) of a given weighted undirected graph.

## Description

The code performs the following tasks:

1. **Graph Class**: It defines a templated graph class with methods to add edges, print the graph, and print the cost matrix.
2. **Adding Edges**: It prompts the user to input the number of nodes, number of edges, and the type of graph (directed or undirected), and then allows the user to input the edges and their weights.
3. **Prims Algorithm**: It implements Prim's algorithm to find the minimum spanning tree of the graph. It stores the edges of the MST in a 2D array `t`.

## Time Complexity

- **Prims Algorithm**: 
  - The time complexity of Prim's algorithm depends on the data structure used for the priority queue and the graph representation.
  - With an adjacency matrix and a simple linear search for the minimum edge, the time complexity is O(V^2), where V is the number of vertices.
  - With an adjacency list and a binary heap, the time complexity is O((V+E) log V), where V is the number of vertices and E is the number of edges.

## Functions

### `void adding_multiple_edges(graph<int> &g, int vertices, int edges, int direction)`

This function allows the user to add multiple edges to the graph by taking input for the vertices and weight of each edge.

### `void prims(graph<int> g, int n, int t[50][2])`

This function implements Prim's algorithm to find the minimum spanning tree of the graph. It stores the edges of the MST in a 2D array `t`.

## Instructions

1. Compile the code using a C++ compiler.
2. Run the executable.
3. Enter the number of nodes, number of edges, and the type of graph (directed or undirected).
4. Enter the vertices and weight of each edge as prompted.
5. View the edges chosen in the minimum spanning tree (MST) printed by the program.

# 3-Single-Source Shortest Path Algorithm Implementation

This C++ code implements the Single-Source Shortest Path (SSSP) algorithm using Dijkstra's algorithm for a given weighted graph.

## Description

The code performs the following tasks:

1. **Graph Class**: It defines a templated graph class with methods to add edges, print the graph, and print the cost matrix.
2. **Adding Edges**: It prompts the user to input the number of nodes, number of edges, and the type of graph (directed or undirected), and then allows the user to input the edges and their weights.
3. **SSSP Algorithm**: It implements Dijkstra's algorithm to find the shortest path from a given source node to all other nodes in the graph. It prints the shortest path lengths from the source node to all other nodes.

## Time Complexity

- **SSSP Algorithm (Dijkstra's Algorithm)**: 
  - The time complexity of Dijkstra's algorithm depends on the data structure used for the priority queue and the graph representation.
  - With an adjacency matrix and a simple linear search for the minimum distance, the time complexity is O(V^2), where V is the number of vertices.
  - With an adjacency list and a binary heap, the time complexity is O((V+E) log V), where V is the number of vertices and E is the number of edges.

## Functions

### `void adding_multiple_edges(graph<int> &g, int vertices, int edges, int direction)`

This function allows the user to add multiple edges to the graph by taking input for the vertices and weight of each edge.

### `int near_vertex(int signal[], int dist[], graph<int> g, int n)`

This function finds the nearest vertex with the minimum distance from the source vertex among the vertices not yet included in the shortest path.

### `void update_distance(int signal[], int distance[], graph<int> g, int n, int u)`

This function updates the distance array with the minimum distance from the source vertex to each vertex in the graph.

### `void sssp(graph<int> g, int source, int n)`

This function implements Dijkstra's algorithm to find the shortest path from a given source node to all other nodes in the graph and prints the shortest path lengths.

## Instructions

1. Compile the code using a C++ compiler.
2. Run the executable.
3. Enter the number of nodes, number of edges, and the type of graph (directed or undirected).
4. Enter the vertices and weight of each edge as prompted.
5. The program will calculate and print the shortest path lengths from the source node to all other nodes in the graph.


