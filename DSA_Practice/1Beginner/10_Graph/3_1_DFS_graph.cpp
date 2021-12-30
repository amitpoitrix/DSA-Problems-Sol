#include<iostream>
#include<vector>
// Striver Graph Series : Depth First Search Traversal on Graph
// Here we use recursion to implement DFS & in this it calls for Adjacent Node followed by there adjacent Node that means
// It goes into the depth of the Nodes first 

// TC - O(V + E)
// SC - O(V + E) + O(V) + O(V)  ; O(V+E) -> For using Adjacency List, O(V) -> Visited Array, O(V) -> Auxillary Space

class Solution{
private:
    void dfs(int node, std::vector<int> &visited, std::vector<int> adj[], std::vector<int> &storeDfs){
        storeDfs.push_back(node);
        visited[node] = 1;
        for (auto x : adj[node]){
            if(!visited[x]){
                dfs(x, visited, adj, storeDfs);
            }
        }
    }

public:
    std::vector<int> dfsOnGraph(int V, std::vector<int> adj[]){
        std::vector<int> storeDfs;
        std::vector<int> visited(V, 0); // 0 based indexing for graph

        for (int i = 0; i < V; i++){
            if(!visited[i]){
                dfs(i, visited, adj, storeDfs);
            }
        }
        
        return storeDfs;
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
    std::vector<int> res = obj.dfsOnGraph(V, adj);

    for (auto x : res){
        std::cout << x << " ";
    }
    
    return 0;
}