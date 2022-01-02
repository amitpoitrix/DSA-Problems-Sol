#include<iostream>
#include<vector>
#include<queue>

#define MAX 1e9

// Striver Graph Series : Dijstra's Algorithm - Used to find Shortest Path in Weigted Undirected Graph
// TC - O((V + E)logV)
// SC - O(V + E) + O(V) + O(V)

void djikstra(int src, int V, std::vector<std::pair<int, int>> adj[]){
    // Initializing each element of distTo[] as INT_MAX 
    int distTo[V];
    for (int i = 0; i < V; i++){
        distTo[i] = MAX;
    }  
    distTo[src] = 0;

    // Declaring Priority Queue as min_heap {distance, node}
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> min_heap;
    min_heap.push({distTo[src], src});

    while (!min_heap.empty()){
        int prevDist = min_heap.top().first;
        int prevNode = min_heap.top().second;
        min_heap.pop();

        // Now checking the adjacent nodes
        std::vector<std::pair<int, int>>::iterator it;

        for (it = adj[prevNode].begin(); it != adj[prevNode].end(); it++){
            int nextDist = it->second;
            int nextNode = it->first;
            // distTo[prevNode] = prevDist both are same
            if(distTo[prevNode] + nextDist < distTo[nextNode]){
                distTo[nextNode] = distTo[prevNode] + nextDist;
                min_heap.push({distTo[nextNode], nextNode});
            }
        }

        // for (auto it : adj[prevNode]){
        //     int nextDist = it.second;
        //     int nextNode = it.first;

        //     if(distTo[prevNode] + nextDist < distTo[nextNode]){
        //         distTo[nextNode] = distTo[prevNode] + nextDist;
        //         min_heap.push({distTo[nextNode], nextNode});
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