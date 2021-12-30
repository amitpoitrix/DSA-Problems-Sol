#include<iostream>
#include<vector>
// Striver Graph Series : Bipartite Graph(Graph Coloring) Using DFS

class Solution{
private:
    bool checkBipartite(int node, int color[], std::vector<int> adj[]){
        if(color[node] == -1)
            color[node] = 1;    // Assigning initial color as 1
        
        for (auto x : adj[node]){
            if(color[x] == -1){
                color[x] = 1 - color[node];
                if(!checkBipartite(x, color, adj))
                    return false;
            }

            else if(color[x] == color[node])
                return false;
        }
        
        return true;
    }

public:
    bool isBipartite(int V, std::vector<int> adj[]){
        int color[V];
        for (int i = 0; i < V; i++){
            color[i] = -1;
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