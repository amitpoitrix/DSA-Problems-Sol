#include<iostream>
#include<vector>
#include<queue>
// Striver Graph Series : Bipartite Graph Using BFS
// Bipartite Graph are the graphs having different colors of any two adjacent nodes

class Solution{
private:
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
                else if(color[x] == color[vertex])
                    return false;
            }
        }
        
        return true;
    }

public:
    bool isBipartite(int V, std::vector<int>adj[]){
        // We can't use std::vector<int> color{V, -1} as this will cause TLE
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