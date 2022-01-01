#include<iostream>
#include<vector>
// Striver Graph Series : Cycle Detection in Undirected Graph using DFS

class Solution{
private:
    bool detectCycle(int node, int parent, std::vector<int> &visited, std::vector<int> adj[]){
        visited[node] = true;
        for (auto x : adj[node]){
            if(!visited[x]){
                if(detectCycle(x, node, visited, adj))
                    return true;
            }

            else if(x != parent)
                return true;
        }
        
        return false;
    }

public:
    bool isCycle(int V, std::vector<int> adj[]){
        std::vector<int> visited(V, 0);
        for (int i = 0; i < V; i++){
            if(!visited[i]){
                if(detectCycle(i, -1, visited, adj))
                    return true;
            }
        }
        
        return false;
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
    if(obj.isCycle(V, adj))
        std::cout << "Graph has Cycle";
    else
        std::cout << "Graph doesn't have cycle";

    return 0;
}