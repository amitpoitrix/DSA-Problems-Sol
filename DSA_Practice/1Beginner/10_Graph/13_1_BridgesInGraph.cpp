#include<iostream>
#include<vector>
// Striver Graph Series : Bridges in Graph/ Cut Edge
// Leetcode Ques: https://leetcode.com/problems/critical-connections-in-a-network/

// Bridges are those edges in graph whose removal lead to increase in no. of components of a graph
// Vridge is also called as cut-edge
// Here, we'll make use of DFS

// Here we'll make use of two array:
// 1. time of insertion array - time[]: Store time of insertion of each node found during DFS of that node
// 2. lowest time of insertion array - low[]: store lowest time of insertion of current node and it is being updated from
// adjacent node whose dfs is already completed or from node which is already being visited.

// In order to check whether two nodes (after there dfs call is over) forms a bridge or not we've formulae:
// if(low[adjacentNodes] > time[currentNode]) than its a bridge btw them

// Algo:
// 1. First we'll make dfs of all its node and once its completed we'll backtrack & update the lowest time of current node 
// from its adjacent node whose dfs is already completed and than we'll apply the formulae to check whether there is bridge
// if(low[adjacentNode] > time[currentNode]) if true than there is bridge else no bridge
// 2. During dfs of all its adjacent node if we found a node(adjacent) which is already being visited than there can't be 
// any bridge just update the low[currentNode] with time[adjacentNode]

// TC - O(V + E) as we are simply using DFS
// SC - O(V) overall

void dfs(int node, int parent, std::vector<int> &visited, std::vector<int> &inTime, std::vector<int> &low, int &timer, std::vector<int> adj[]){
    // Marking the current node as visited
    visited[node] = 1;  
    // every time a node is visited in dfs we'll increase timer and store time for its insertion time & lowest time value
    inTime[node] = low[node] = ++timer;
    
    // Now checking all its adjacent nodes
    for (auto x : adj[node]){
        //If adjacent node is a parent node than do nothing as we don't go backward so just continue
        if(x == parent)
            continue;

        if(!visited[x]){
            // If adjacent nodes of current node is not visited we'll call dfs for this adjacent node
            dfs(x, node, visited, inTime, low, timer, adj);
            // After dfs() we'll backtrack & make low[current node] as low as possible by compairing it with adjacent node low
            low[node] = std::min(low[node], low[x]);
            // Now we'll check whether there is bridge or not
            if(low[x] > inTime[node]){
                std::cout << "Bridge : " << node << " - " << x << "\n";
            }
        }
        else{
            // If adjacent node is already visited than updating low of current with time of insertion of already visited
            // adjacent node
            low[node] = std::min(low[node], inTime[x]);
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
    
    // We'll take 3 arrays as inTime[], low[], visited[]
    std::vector<int> inTime(V, -1);
    std::vector<int> low(V, -1);
    std::vector<int> visited(V, 0);

    int timer = 0;

    for (int i = 0; i < V; i++){
        if(!visited[i]){
            dfs(i, -1, visited, inTime, low, timer, adj);
        }
    }
    
    return 0;
}