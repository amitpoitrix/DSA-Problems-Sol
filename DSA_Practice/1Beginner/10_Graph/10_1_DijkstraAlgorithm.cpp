#include<iostream>
#include<vector>
#include<queue>

#define MAX 1e9

// Striver Graph Series : Dijkstra's Algorithm 
// It is used to find Shortest Path in Weigted Undirected Graph from src to all vertices but it doesn't work on -ve edges

// Algo:
// 1. Perform BFS(using min_heap as we can't use queue becoz of different edge weights) & we don't require visited[] 
// 2. Maintain a min_heap of pair{distance, node} and do notice adjacency list for graph is in pair{node, distance}
// 3. Make a distance[] array, mark src as 0 & every other node as MAX
// 4. While min_heap is not empty
//      a) Take top pair of heap
//      b) Check for adjacents of top node
//      c) If you find better distance, update it in visited array & push into heap

// TC - O((V + E)logV)
// SC - O(V + E) + O(V) + O(V)

void djikstra(int src, int V, std::vector<std::pair<int, int>> adj[]){
    // Initializing each element of dist[] as MAX 
    int dist[V];
    for (int i = 0; i < V; i++){
        dist[i] = MAX;
    }  
    dist[src] = 0;

    // Declaring Priority Queue as min_heap {distance, node}
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> min_heap;
    min_heap.push({dist[src], src});

    while (!min_heap.empty()){
        int u = min_heap.top().second;
        min_heap.pop();

        // Now checking the adjacent nodes of u
        std::vector<std::pair<int, int>>::iterator it;

        for (it = adj[u].begin(); it != adj[u].end(); it++){
            int v = it->first;
            int nextDist = it->second;
            // dist[u] = prevDist(i.e., min_heap.top().first) both are same
            if(dist[u] + nextDist < dist[v]){
                dist[v] = dist[u] + nextDist;
                min_heap.push({dist[v], v});
            }
        }

        // Another way for checking adjacent node of u
        // for (auto it : adj[u]){
        //     int nextDist = it.second;
        //     int v = it.first;

        //     if(dist[u] + nextDist < dist[v]){
        //         dist[v] = dist[u] + nextDist;
        //         min_heap.push({dist[v], v});
        //     }
        // }
        
    }
    
    std::cout << "Distance from Source " << src << ":\n";
    for (int i = 0; i < V; i++){
        std::cout << dist[i] << " ";
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