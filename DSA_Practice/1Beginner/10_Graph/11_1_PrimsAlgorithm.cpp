#include<iostream>
#include<vector>
#include<queue>

#define MAX 1e9

// Striver Graph series : Prim's Algorithm - to get the MST(Minimum Spanning Tree) from given graph
// spanning Tree - A tree formed from graph(V,E) having V nodes & V-1 edges & each node is reachable to every other nodes
// MST - A spanning tree having minimum cost of edge weight

void primsAlgorithm(int src, int V, std::vector<std::pair<int, int>> adj[]){
    // Here we take 3 arrays
    int distTo[V];
    bool MST[V];
    int parentNode[V];

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
        int prevNode = min_heap.top().second;
        min_heap.pop();

        MST[prevNode] = true;

        for (auto it : adj[prevNode]){
            int nextNode = it.first;
            int nextDist = it.second;

            if(MST[nextNode] == false && nextDist < distTo[nextNode]){
                distTo[nextNode] = nextDist;
                min_heap.push({distTo[nextNode], nextNode});
                parentNode[nextNode] = prevNode;
            }
        }
    }
    
    // Display after Prim's Algorithm
    for (int i = 0; i < V; i++){
        std::cout << parentNode[i] << " - " << i << "\n";
    }
}

int main(){
    int V, E;
    std::cin >> V >> E;

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