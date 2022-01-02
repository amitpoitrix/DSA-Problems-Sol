#include<iostream>
#include<vector>
#include<queue>
// Striver Graph Series : Shortest Path in Undirected Graph with Unit Weights
// Here we'll return a vector having shortest distance of all vertex from source(src)
// We'll use modified version of BFS

class Solution{
public:
    void shortestPath(int V, std::vector<int> adj[], int src){
        int path[V];
        for (int i = 0; i < V; i++){
            path[i] = 10000000;
        }

        std::queue<int> q;
        path[src] = 0;  // Making the distance of src from src as 0
        q.push(src);

        while (!q.empty()){
            int vertex = q.front();
            q.pop();

            for (auto x : adj[vertex]){
                if(path[vertex] + 1 < path[x]){
                    path[x] = path[vertex] + 1;
                    q.push(x);
                }
            }
        }
        
        // Display Shortest Path
        for (int i = 0; i < V; i++){
            std::cout << path[i] << " ";
        }
    }
};

int main(){
    int V, E;
    std::cin >> V >> E;

    std::vector<int> adj[V];

    for (int i = 0; i < E; i++){
        int u, v;
        std::cin>> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Solution obj;
    obj.shortestPath(V, adj, 0);
    
    return 0;
}

// 8 10
// 0 1
// 0 3
// 1 2
// 3 4
// 3 7
// 4 5
// 4 6
// 4 7
// 5 6
// 6 7