#include<iostream>
#include<vector>
#include<queue>

#define MAX 1e9

// Striver Graph Series : Shortest Path in Undirected Graph with Unit Weights
// Here we'll return a vector having shortest distance of all vertex from source(src)
// We'll use modified version of BFS

class Solution{
public:
    void shortestPath(int V, std::vector<int> adj[], int src){
        int distTo[V];
        for (int i = 0; i < V; i++){
            distTo[i] = MAX;
        }
        distTo[src] = 0;  // Making the distance of src from src as 0

        std::queue<int> q;
        q.push(src);

        while (!q.empty()){
            int prevNode = q.front();
            q.pop();

            for (auto nextNode : adj[prevNode]){
                if(distTo[prevNode] + 1 < distTo[nextNode]){
                    distTo[nextNode] = distTo[prevNode] + 1;
                    q.push(nextNode);
                }
            }
        }
        
        // Display Shortest Path
        for (int i = 0; i < V; i++){
            std::cout << distTo[i] << " ";
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