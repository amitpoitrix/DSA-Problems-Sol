#include<iostream>
#include<vector>
using namespace std;
// Striver Graph Series : Depth First Search (DFS) Traversal On Graph
// Here we use recursion to implement DFS & in this it calls for Adjacent Node followed by there adjacent Node that means
// It goes into the depth of the Nodes first 

// TC - O(V + E)
// SC - O(V + E) + O(V) + O(V)  ; O(V+E) -> For using Adjacency List, O(V) -> Visited Array, O(V) -> Auxillary Space

// Application of DFS :
// 1. Cycle Detection
// 2. Topological Sorting
// 3. Strongly Connected Components
// 4. Path Finding
// 5. Solving Maze and Similar Puzzles

class Solution{
private:
    void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &storeDfs){
        vis[node] = 1;  // First mark the node as visited
        storeDfs.push_back(node);   // than push it into storeDfs[]

        // Traversing in depth through its neighbour nodes
        for (auto x : adj[node]){
            if(!vis[x]){    // if neighbour is not visited than doing recursive call to go in depth
                dfs(x, vis, adj, storeDfs);
            }
        }
    }

public:
    vector<int> dfsOnGraph(int V, vector<int> adj[]){
        vector<int> storeDfs;
        vector<int> vis(V, 0); // 0 based indexing for graph

        // Traversing first till Vth node becoz of any non connected components of graph
        for (int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i, vis, adj, storeDfs);
            }
        }
        
        return storeDfs;
    }
};

int main(){
    int V, E;
    cin >> V >> E;

    vector<int> adj[V];

    for (int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    Solution obj;
    vector<int> res = obj.dfsOnGraph(V, adj);

    for (auto x : res){
        cout << x << " ";
    }
    
    return 0;
}