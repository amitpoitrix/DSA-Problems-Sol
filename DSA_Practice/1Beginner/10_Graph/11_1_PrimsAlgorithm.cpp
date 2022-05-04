#include<iostream>
#include<vector>
#include<queue>

#define MAX 1e9

// Striver Graph series : Prim's Algorithm - to get the MST(Minimum Spanning Tree) from given graph
// Spanning Tree - A subgraph formed from graph(V,E) having V nodes & V-1 edges & each node is reachable from every other node
// MST - A spanning tree having minimum cost of edge weights
// Prim's Algo almost similar to Dijstra's Algorithm

// Algo:
// 1. Take any node(or src node) for Tree.
// 2. Now check the adjacent edges of all the nodes taken till now in the tree & take the edge with min weight 
// 3. Repeat step 2 n-1 times.
// As we want want min weight(or edge) each time, so we can use min_heap instead of key(or dist[]) array.

// TC - O(ElogV)

void primsAlgorithm(int src, int V, std::vector<std::pair<int, int>> adj[]){
    // Here we take 3 arrays
    int dist[V];  // This array will store weight/distance/cost(key-value) of all vertices as low as possible
    bool MST[V];    // This will make sure that algo won't consider duplicate vertices & kind of visited[]
    int parentNode[V];  // This will actually contain the MST

    for (int i = 0; i < V; i++){
        dist[i] = MAX;
        MST[i] = false;
    }
    dist[src] = 0;
    parentNode[src] = -1;

    // Declaring PriorityQueue as min_heap {distance, node}
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> min_heap;
    min_heap.push({dist[src], src});

    while (!min_heap.empty()){
        int u = min_heap.top().second;
        min_heap.pop();

        MST[u] = true;  // Node u is taken into MST

        // Here in Prim's Algo we're checking all the adjacent nodes having min edge weights
        for (auto it : adj[u]){
            int v = it.first;
            int nextDist = it.second;

            // Here we're not computing/checking dist. from src to dest node but from current node to adjacent nodes
            if(MST[v] == false && nextDist < dist[v]){
                dist[v] = nextDist;
                min_heap.push({dist[v], v});
                // After computing its min edge weight now we're storing its parent
                parentNode[v] = u;
            }
        }
    }
    
    // Display parent[] after Prim's Algorithm & starting from node 1 as node 0 won't be having any parent node
    for (int i = 1; i < V; i++){
        std::cout << parentNode[i] << " - " << i << "\n";
    }
}

int main(){
    int V, E;
    std::cin >> V >> E;
    // Adjacency list {u, v, wt}
    std::vector<std::pair<int, int>> adj[V];

    for (int i = 0; i < E; i++){
        int u, v, wt;
        std::cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    int src = 0;
    
    primsAlgorithm(src, V, adj);

    return 0;
}