#include<iostream>
#include<vector>
#include<queue>

#define MAX 1e9

// Striver Graph Series : Dijstra's Algorithm - Used to find Shortest Path in Weigted Undirected Graph from src to all vertices
// but it doesn't work on -ve edges
// TC - O((V + E)logV)
// SC - O(V + E) + O(V) + O(V)

void djikstra(int src, int V, std::vector<std::pair<int, int>> adj[]){
    // Initializing each element of distTo[] as MAX 
    int distTo[V];
    for (int i = 0; i < V; i++){
        distTo[i] = MAX;
    }  
    distTo[src] = 0;

    // Declaring Priority Queue as min_heap {distance, node}
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> min_heap;
    min_heap.push({distTo[src], src});

    while (!min_heap.empty()){
        int u = min_heap.top().second;
        min_heap.pop();

        // Now checking the adjacent nodes of u
        std::vector<std::pair<int, int>>::iterator it;

        for (it = adj[u].begin(); it != adj[u].end(); it++){
            int v = it->first;
            int nextDist = it->second;
            // distTo[u] = prevDist(i.e., min_heap.top().first) both are same
            if(distTo[u] + nextDist < distTo[v]){
                distTo[v] = distTo[u] + nextDist;
                min_heap.push({distTo[v], v});
            }
        }

        // for (auto it : adj[u]){
        //     int nextDist = it.second;
        //     int v = it.first;

        //     if(distTo[u] + nextDist < distTo[v]){
        //         distTo[v] = distTo[u] + nextDist;
        //         min_heap.push({distTo[v], v});
        //     }
        // }
        
    }
    
    std::cout << "Distance from Source " << src << ":\n";
    for (int i = 0; i < V; i++){
        std::cout << distTo[i] << " ";
    }
}

int main(){
    int V, E;
    std::cin >> V >> E;
    // Adjacency List - {node, weights}
    std::vector<std::pair<int, int>> adj[V];

    for (int i = 0; i < E; i++){
        int u, v, wt;
        std::cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    
    int src = 0;

    djikstra(src, V, adj);
    
    return 0;
}