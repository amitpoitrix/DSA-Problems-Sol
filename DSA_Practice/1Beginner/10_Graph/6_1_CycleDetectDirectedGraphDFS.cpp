#include<iostream>
#include<vector>
// Striver Graph Series : Detecting cycle in Directed Graph using DFS
// Algo:
// 1. If in recursion stack, a node comes two times then cycle is there.
// 2. So we can maintain two arrays, visited[] & dfsVisited[] call array.
// 3. If you go to a node then mark it in both arrays but when you go back from that node than unmark it from dfsVisited[] only.
// 4. If you go to a node where dfsVisited[] is already marked than cycle is there.

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
        
        // Backtracking : Un-marking dfsVisited[] 
        dfsVis[node] = 0;
        return false;
    }

public:
    bool isCyclic(int V, std::vector<int> adj[]) {
        // std::vector<int> vis(V, 0);
        // std::vector<int> dfsVis(V, 0);

        // Using normal array becoz vector<int> vis(V,0) initial value 0 initialization is costly(TLE)
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