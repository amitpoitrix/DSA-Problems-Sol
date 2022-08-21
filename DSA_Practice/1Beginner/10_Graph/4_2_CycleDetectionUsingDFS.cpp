#include<iostream>
#include<vector>
using namespace std;
// Striver Graph Series : Cycle Detection in Undirected Graph using DFS
// If adjacent node(next node) is already visited & its not a parent node than there is a cycle

class Solution{
private:
    bool detectCycle(int node, int parent, vector<int> &vis, vector<int> adj[]){
        vis[node] = 1;

        for (auto adjacentNode : adj[node]){
            if(!vis[adjacentNode]){
                if(detectCycle(adjacentNode, node, vis, adj))
                    return true;
            }

            else if(adjacentNode != parent)
                return true;
        }
        
        return false;
    }

public:
    bool isCycle(int V, vector<int> adj[]){
        vector<int> vis(V, 0);

        for (int i = 0; i < V; i++){
            if(!vis[i]){
                if(detectCycle(i, -1, vis, adj))
                    return true;
            }
        }
        
        return false;
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
    if(obj.isCycle(V, adj))
        cout << "Graph has Cycle";
    else
        cout << "Graph doesn't have cycle";

    return 0;
}