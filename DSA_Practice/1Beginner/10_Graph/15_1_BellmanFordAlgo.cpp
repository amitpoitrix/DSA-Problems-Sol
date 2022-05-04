#include<iostream>
#include<vector>
// Striver Graph Series : Bellman Ford Algorithm

// 1. like Dijkstra Algorithm it's also used to find Shortest Path in Weigted Undirected Graph from src to all vertices & 
// it also work on -ve weight
// 2. Bellman Ford Algorithm works in Directed Weighted(+ve/-ve) Graph & if it has to work on Undirected Weighted Graph than 
// it has to converted into Directed Graph using Bidirectional edges(->/<-) & it won't work on -ve weight cycle(i.e., a cycle
// with sum of edge weights being -ve) in both Directed & Undirected graph
// 3. Bellman Ford Algorithm helps to detect -ve weight cycle in a graph
// In BF Algo we have to relax all the edges (n-1)times 
// i.e., if(dist[u] + wt < dist[v]) then dist[v] = dist[u] + wt;
// if after relaxing (n-1)times, if you relax again & if distance reduces then it indicates that -ve edge weight cycle is there

// We are relaxing (n-1)times because in a graph of n nodes the largest path from src to any node will contain (n-1)edges atmost

// TC - O(E * (V - 1)); where V-1 is (N-1) no. of nodes - 1
// SC - O(V)

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

    // Relaxing all the edges (V -1) times starting from i=1
    for (int i = 1; i <= V-1; i++){
        // Relaxing each edges
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