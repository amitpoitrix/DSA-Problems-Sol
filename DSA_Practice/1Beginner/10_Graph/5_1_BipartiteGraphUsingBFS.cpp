#include<iostream>
#include<vector>
#include<queue>
// Striver Graph Series : Bipartite Graph(Graph Coloring) Using BFS
// Bipartite Graph: A graph that can be colored using 2 colors(i.e, 0 & 1) such that no two adjacent nodes have same color.
// A graph containing odd length cycle cannot be a Bipartite graph

// Algo:
// 1. Push root(starting node) in queue & mark its color as 0.
// 2. Then keep visiting adjacent nodes & mark them colored with opposite color of their parent.
// 3. At any point if you visit a node which is already colored & the color is same as color of source node than return false.

// TC - O(V + E)
// SC - O(V) ~ Due to queue
class Solution{
private:
    // Using BFS - Iterative Approach
    bool checkBipartite(int node, int color[], std::vector<int> adj[]){
        std::queue<int> q;
        q.push(node);
        color[node] = 1;    // Let there are two colors as 0 & 1

        while (!q.empty()){
            int vertex = q.front();
            q.pop();

            for (auto x : adj[vertex]){
                if(color[x] == -1){
                    color[x] = 1 - color[vertex];     // This will make sure to add opposite color to its adjacent vertex
                    q.push(x);
                }
                // If adjacent vertex have same color than return false
                else if(color[x] == color[vertex])
                    return false;
            }
        }
        
        return true;
    }

public:
    bool isBipartite(int V, std::vector<int>adj[]){
        // We can't use std::vector<int> color(V, -1) as this will cause TLE
	    int color[V];
        for (int i = 0; i < V; i++){
            color[V] = -1;
        }
        
        for (int i = 0; i < V; i++){
            if(color[i] == -1){
                if(!checkBipartite(i, color, adj))
                    return false;
            }
        }
        
        return true;
	}
};

int main(){
    int V, E;
    std::cin >> V >> E;

    std::vector<int> adj[V];

    for (int i = 0; i < E; i++){
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    Solution obj;
    if(obj.isBipartite(V, adj))
        std::cout << "Its a Bipartite Graph";
    else
        std::cout << "Its not a Bipartite Graph";

    return 0;
}