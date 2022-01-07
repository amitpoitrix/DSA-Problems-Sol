#include<iostream>
#include<vector>
// Striver Graph Series : Bellman Ford Algorithm
// 1. like Dijkstra Algorithm its also used to find Shortest Path in Weigted Undirected Graph from src to all vertices & 
// it also work on -ve weight
// 2. Bellman Ford Algorithm works in Directed Weighted(+ve/-ve) Graph & if it has to work on Undirected Weighted Graph than it has to 
// converted into Directed Graph using Bidirectional edges(->/<-) & it won't work on -ve cycle in both Directd & Undirected graph
// 3. It helps to detect -ve cycle in a graph
// In BFAlgo we have to relax the node (n-1) times & after this the dist[] will contain minmum distance from src if we do 1 more relaxation
// after (n-1) & value in dist[] further reduces than that graph contain -ve cycle

#define INF 1e9

struct Node{
    int u;
    int v;
    int wt;

    Node(int first, int second, int weight){
        u = first;
        v = second;
        wt = weight;
    }
};

void bellmanFordAlgo(int V, std::vector<Node> &edges){
    // Initializing dist[] with infinite except src node
    std::vector<int> dist(V, INF);
    int src = 0;
    dist[src] = 0;

    // Relaxing the Nodes (v-1) times
    for (int i = 1; i <= V-1; i++){
        for (auto x : edges){
            if(dist[x.u] + x.wt < dist[x.v]){
                dist[x.v] = dist[x.u] + x.wt;
            }
        }
    }

    // Relaxing 1 more time in order to detect -ve cycle
    int flag = 0;
    for (auto x : edges){
        if(dist[x.u] + x.wt < dist[x.v]){
            std::cout << "Negative Cycle Detected";
            flag = 1;
            break;
        }
    }
    
    if(!flag){
        std::cout << "Distance from src are : \n";
        for (int i = 0; i < V; i++){
            std::cout << dist[i] << " ";
        }
    }
}

int main(){
    int V, E;
    std::cin >> V >> E;
    std::vector<Node> edges;
    for (int i = 0; i < E; i++){
        int u, v, wt;
        std::cin >> u >> v >> wt;
        edges.push_back(Node(u, v, wt));
    }
    
    bellmanFordAlgo(V, edges);

    return 0;
}