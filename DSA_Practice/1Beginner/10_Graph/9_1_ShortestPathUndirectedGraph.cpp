#include<iostream>
#include<vector>
#include<queue>

#define MAX 1e9

// Striver Graph Series : Shortest Path in Undirected Graph with Unit Weights
// Find shortest distance from given source node to every other node in the graph
// We'll use modified version of BFS

// Algo:
// 1. Perform BFS
// 2. Maintain a distance[] array initially filled with MAX(or 1e9) & here we don't require visited[]
// 3. Mark source's distance as 0.
// 4. If you visit neighbours of a node(whose distance is d) than check if(d+1 < dist(neighbor)) if yes than update the 
// neighbors distance and push it into the queue(this is the modified BFS)
// 5. That distance[] is our ans just print it or return it

class Solution{
public:
    void shortestPath(int V, std::vector<int> adj[], int src){
        int dist[V];
        for (int i = 0; i < V; i++){
            dist[i] = MAX;
        }
        dist[src] = 0;  // Making the distance of src from src as 0

        std::queue<int> q;
        q.push(src);

        while (!q.empty()){
            int currNode = q.front();
            q.pop();

            for (auto nextNode : adj[currNode]){
                if(dist[currNode] + 1 < dist[nextNode]){
                    dist[nextNode] = dist[currNode] + 1;
                    q.push(nextNode);
                }
            }
        }
        
        // Display Shortest Path
        for (int i = 0; i < V; i++){
            std::cout << dist[i] << " ";
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