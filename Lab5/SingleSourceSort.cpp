#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std ;
template <typename T>


class graph {
    public:
    unordered_map<T,vector<pair<T,int>>> adj;
    vector<vector<int>> cost;

   graph(int n){
        cost.resize(n, vector<int>(n, INT16_MAX));
        cout << "done1" << endl;
    }
    
    void addEdge(T u, T v ,int w, int dir){
        adj[u].push_back(make_pair(v,w));
        cost[u][v]=w;
        if(dir == 0){
        adj[v].push_back(make_pair(u,w));
        cost[v][u]=w;
        }
    }

    void printGraph(){
        for(auto i : adj){
            cout<<i.first<<" -> ";
            for(auto j:i.second){
                cout<<"["<<j.first<<","<<j.second<<"]"<<", ";
            }
            cout<<endl;
        }
    }

    void printCost(){
        for(int i=0;i<cost.size();i++){
            for(int j=0;j<cost[i].size();j++){
                cout<<cost[i][j]<<"\t";
            }
            cout<<endl;
        }
    }
};

void adding_multiple_edges(graph<int> &g,int vertices, int edges, int direction){
    int i=0;
    while(i<edges){
        cout<<"enter vertices in which edge is present and weight of edge : "<<endl;
        int p,q,w;
        cin>>p>>q>>w;
        if(p>=vertices || q>=vertices){
            cout<<"entered vertices are not present"<<endl;
        }
        else{
            g.addEdge(p,q,w,direction);
            i++;
        }
    }
}

int near_vertex(int signal[],int dist[],graph<int> g,int n){
    int min = -1;
    int mincost = INT16_MAX;
    for(int i=0;i<n;i++){
        if(signal[i]==0 && dist[i]<mincost){
        min = i;
        mincost = dist[i];
        }

    }
    return min;
}

void update_distance(int signal[],int distance[],graph <int> g,int n, int u){
    for(int i=0;i<n;i++){
        if(signal[i]==0 && distance[i]>=(distance[u]+g.cost[u][i]))
        distance[i]=distance[u]+g.cost[u][i];
    }
}

void sssp(graph<int> g ,int source,int n){
    int dist[n];
    int signal[n];
    for(int i=0;i<n;i++){
        dist[i]=g.cost[source][i];
        signal[i]=0;
    }
    signal[source]=1;
    dist[source]=0;
    for(int j=1;j<n;j++){
        int p = near_vertex(signal,dist,g,n);
        if(p>=0){
        signal[p]=1;
        update_distance(signal,dist,g,n,p);
        }
    }
    cout<<"shortest path length between : "<<endl;
    for(int i=0;i<n;i++){
        cout<<source<<" and "<<i<<" : "<<dist[i]<<endl;
    }

}


int main(){
    int n;
    int m;
    int dir;
    cout<<"enter number of nodes : ";
    cin>>n;
    cout<<"enter number of edges : ";
    cin>>m;
    cout<<"enter 1 for directed and 0 for undirected graph : ";
    cin>>dir;
    graph<int> g(n);
    adding_multiple_edges(g,n,m,dir);
    sssp(g,0,n);
    return 0;
}