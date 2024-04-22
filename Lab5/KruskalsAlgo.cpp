#include <iostream>
#include <chrono>
#include <algorithm>
#include <random>
using namespace std;
using namespace std::chrono;

const int MAX_VERTICES = 1000; 

struct Edge
{
    int source;
    int destination;
    int weight;
};

struct DisjointSet
{
    int parent[MAX_VERTICES];
    int rank[MAX_VERTICES];

    DisjointSet(int n)
    {
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int u)
    {
        if (parent[u] != u)
        {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void unionSets(int u, int v)
    {
        int rootU = find(u);
        int rootV = find(v);

        if (rank[rootU] < rank[rootV])
        {
            parent[rootU] = rootV;
        }
        else if (rank[rootU] > rank[rootV])
        {
            parent[rootV] = rootU;
        }
        else
        {
            parent[rootU] = rootV;
            rank[rootV]++;
        }
    }
};



void Heapify(Edge edge[], int i, int N)
{
    int large = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < N && edge[i].weight < edge[left].weight)
    {
        large = left;
    }
    if (right < N && edge[large].weight < edge[right].weight)
    {
        large = right;
    }
    if (large != i)
    {
        swap(edge[i], edge[large]);
        Heapify(edge, large, N);
    }
}

void build_heap(Edge edge[], int n)
{
    for (int i = n / 2 - 1; i >= 0; --i)
    {
        Heapify(edge, i, n);
    }
}

void kruskal(Edge edge[], int n, int **t)
{
    build_heap(edge, n);

    DisjointSet d(n);

    int edgeCount = 0;
    int i = 0;

    while (edgeCount < n - 1)
    {
        Edge E1 = edge[i];

        int Source = d.find(E1.source);
        int Dest = d.find(E1.destination);

        if (Source != Dest)
        {
            t[edgeCount][0] = E1.source;
            t[edgeCount][1] = E1.destination;
            edgeCount++;
            d.unionSets(Source, Dest);
        }

        i++;
    }
}

int main()
{
    int n;
    cout << "choose the number of edges";
    cin >> n;

    int **t = new int*[n - 1];
    for (int i = 0; i < n - 1; ++i) {
        t[i] = new int[2];
    }

    Edge edge[n];
    for (int i = 0; i < n; i++) {
        cout << "enter source then destination and then weight";
        cin >> edge[i].source >> edge[i].destination >> edge[i].weight;
    }

    kruskal(edge, n, t);

    cout << "Chosen Edges in the Minimum Spanning Tree (MST):" << endl;
    for (int i = 0; i < n - 1; ++i) {
        cout << "Edge: " << t[i][0] << " - " << t[i][1] << endl;
    }

    for (int i = 0; i < n - 1; ++i) {
        delete[] t[i];
    }
    delete[] t;

    return 0;
}