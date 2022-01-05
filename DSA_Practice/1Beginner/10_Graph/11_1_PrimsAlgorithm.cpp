#include<iostream>
#include<vector>
#include<queue>

#define MAX 1e9

// Striver Graph series : Prim's Algorithm - to get the MST(Minimum Spanning Tree) from given graph
// spanning Tree - A subgraph formed from graph(V,E) having V nodes & V-1 edges & each node is reachable from every other
// MST - A spanning tree having minimum cost of edge weights
// Prim's Algo almost similar to Dijstra's Algorithm
// TC - O(ElogV)

void primsAlgorithm(int src, int V, std::vector<std::pair<int, int>> adj[]){
    // Here we take 3 arrays
    int distTo[V];  // This array will store cost(key value) of all vertices as low as possible
    bool MST[V];    // This will make sure that algo won't consider duplicate vertices
    int parentNode[V];  // This will actually contain the MST

    for (int i = 0; i < V; i++){
        distTo[i] = MAX;
        MST[i] = false;
    }
    distTo[src] = 0;
    parentNode[src] = -1;

    // Declaring PriorityQueue as min_heap {distance, node}
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> min_heap;
    min_heap.push({distTo[src], src});

    while (!min_heap.empty()){
        int u = min_heap.top().second;
        min_heap.pop();

        MST[u] = true;

        for (auto it : adj[u]){
            int v = it.first;
            int nextDist = it.second;

            if(MST[v] == false && nextDist < distTo[v]){
                distTo[v] = nextDist;
                min_heap.push({distTo[v], v});
                parentNode[v] = u;
            }
        }
    }
    
    // Display after Prim's Algorithm
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