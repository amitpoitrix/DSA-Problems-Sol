#include<iostream>
#include<vector>
#include<queue>
using namespace std;
// Striver Graph Series : Cycle detection in Undirected Graph using BFS 
// Using BFS, if from a node 'u' (currentNode) we visit a node 'v'(nextNode) & if 'v' is already visited & also 'v' is not
// a parent of 'u' (i.e., we can't go to 'u' from 'v') than there is a cycle

class Solution{
private:
    bool detectCycle(int src, vector<int> &vis, vector<int> adj[]){
        vis[src] = 1;

        // {currentNode, parentNode}
        queue<pair<int, int>> q;
        q.push({src, -1});     // Starting vertex parent is NULL so we'll put it as -1

        while (!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto adjacentNode : adj[node]){
                // If not yet vis
                if(!vis[adjacentNode]){
                    vis[adjacentNode] = 1;
                    q.push({adjacentNode, node});
                }
                // else if adjacent Node is not the parent node than there is a cycle
                else if(adjacentNode != parent)
                    return true;
            }
        }
        
        return false;
    } 

public:
    bool isCycle(int V, vector<int> adj[]){
        vector<int> vis(V, 0);
        
        for (int i = 0; i < V; i++){
            if(!vis[i]){
                // If any component have cycle than return true
                if(detectCycle(i, vis, adj))
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