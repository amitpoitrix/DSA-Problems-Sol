#include<iostream>
#include<vector>
// Striver Graph Series : Detect cycle in Directed Graph using DFS

class Soltuion{
private:
    bool detectCycle(int node, std::vector<int> adj[], int vis[], int dfsVis[]){
        vis[node] = 1;
        dfsVis[node] = 1;

        for (auto x : adj[node]){
            if(!vis[x]){
                if(detectCycle(x, adj, vis, dfsVis))
                    return true;
            }

            else if(dfsVis[x])
                return true;
        }
        
        // Backtracking
        dfsVis[node] = 0;
        return false;
    }

public:
    bool isCyclic(int V, std::vector<int> adj[]) {
        // std::vector<int> vis(V, 0);
        // std::vector<int> dfsVis(V, 0);

        int vis[V];
        int dfsVis[V];
        for (int i = 0; i < V; i++){
            vis[i] = 0;
            dfsVis[i] = 0;
        }
        
        for (int i = 0; i < V; i++){
            if(!vis[i]){
                if(detectCycle(i, adj, vis, dfsVis)){
                    return true;
                }
            }
        }
        
        return false;
    }
};

int main(){

    return 0;
}