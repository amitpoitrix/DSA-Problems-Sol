#include<iostream>
#include<vector>
#include<queue>
// Striver Graph Series : Cycle detection in Undirected Graph using BFS 
// Using BFS, if from a node 'u' (currentNode) we visit a node 'v'(nextNode) & if 'v' is already visited & also 'v' is not
// a parent of 'u' (i.e., we can't go to 'u' from 'v') than there is a cycle

class Solution{
private:
    bool detectCycle(int node, std::vector<int> &visited, std::vector<int> adj[]){
        // queue<{currentNode, parentNode}>
        std::queue<std::pair<int, int>> q;
        q.push({node, -1});     // Starting vertex parent is NULL so we'll put it as -1
        visited[node] = true;

        while (!q.empty()){
            int current = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto x : adj[current]){
                // If not yet visited
                if(!visited[x]){
                    visited[x] = true;
                    q.push({x, current});
                }
                // else if visited than it must be its parent node if not than there is cycle
                else if(x != parent)
                    return true;
            }
        }
        
        return false;
    } 

public:
    bool isCycle(int V, std::vector<int> adj[]){
        std::vector<int> visited(V, 0);
        for (int i = 0; i < V; i++){
            if(!visited[i]){
                // If any component have cycle than return true
                if(detectCycle(i, visited, adj))
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