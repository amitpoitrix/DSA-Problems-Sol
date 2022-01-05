#include<iostream>
#include<vector>
// Striver Graph Series : Bridges in Graph/ Cut Edge
// Bridges are those edges in graph whose removal lead to increase in no. of components of a graph
// Here, we'll make use of DFS
// TC - O(V + E) as we are simply using DFS
// SC - O(V) overall

void dfs(int node, int parent, std::vector<int> &visited, std::vector<int> &discTime, std::vector<int> &lowTime, int &timer, std::vector<int> adj[]){
    visited[node] = 1;  // Marking the current node as visited
    discTime[node] = lowTime[node] = ++timer;

    for (auto x : adj[node]){
        //If adjacent node is a parent node
        if(x == parent)
            continue;

        if(!visited[x]){
            // If adjacent nodes of current node is not visited we'll call dfs for this adjacent node
            dfs(x, node, visited, discTime, lowTime, timer, adj);
            // After dfs() we'll backtrack & make lowTime[current node] as low as possible by compairing it with adjacent node lowTime
            lowTime[node] = std::min(lowTime[node], lowTime[x]);
            // Now we'll check if adjacent node has another route(back edge) to current node or ancestors of current node
            if(lowTime[x] > discTime[node]){
                std::cout << "Bridge : " << node << " - " << x << "\n";
            }
        }
        else{
            // If adjacent node is already visited than its discTime should be lower
            lowTime[node] = std::min(lowTime[node], discTime[x]);
        }
    }
}

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
    
    // We'll take 3 arrays as discTime[], lowTime[], visited[]
    std::vector<int> discTime(V, -1);
    std::vector<int> lowTime(V, -1);
    std::vector<int> visited(V, 0);
    int timer = 0;

    for (int i = 0; i < V; i++){
        if(!visited[i]){
            dfs(i, -1, visited, discTime, lowTime, timer, adj);
        }
    }
    
    return 0;
}