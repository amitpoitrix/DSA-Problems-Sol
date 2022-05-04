#include<iostream>
#include<vector>
// Striver Graph Series : Articulation Point or Cut Vertex 
// Articulation point in a graph is the Node/Vertex removal of which leads to increase in the no. of components of graph
// Here we'll use DFS same as in Bridge in Graph

// Here also we'll maintain two array like bridge i.e., time[] & low[]
// A Node/Vertex in graph is Articulation Point/Cut Vertex if any of the condition is true :
// 1. if(low[adjacentNode] >= time[currentNode] && parent != -1) than currentNode is Articulation Point.
// If parent == -1 then that means there is no upper half, so even if you remove that node, no. of components are not going
// to increase
// 2. A node is a root node(i.e., parent[node] == -1) & it has atleast 2 children(individual child > 1 i.e, each individual 
// child that require individual DFS call)
// 3. u is not root of DFS tree and it has a child v such that no vertex in subtree rooted with v has a back edge to one 
// of the ancestors (in DFS tree) of u.
// 4. A leaf node cannot be an Articulation Point

// Note: While running algo, one node can come multiple times due to multiple childs, so its better to mark the node in 
// hash map

// TC - O(V+E)
// SC - O(V)
void dfs(int node, int parent, std::vector<int> &isArticulation, std::vector<int> &visited, std::vector<int> &inTime, std::vector<int> &low, int &timer, std::vector<int> adj[]){
    visited[node] = 1;
    inTime[node] = low[node] = ++timer;

    int child = 0;  // For computing the no. of individual children

    for (auto x : adj[node]){
        if(x == parent)
            continue;

        else if(!visited[x]){
            dfs(x, node, isArticulation, visited, inTime, low, timer, adj);
            low[node] = std::min(low[node], low[x]);
//Condition for checking Articulation point as well as its parent should not be a root node(i.e., Starting node can't be a AP)
            if(low[x] >= inTime[node] && parent != -1){
                // As we can get same Articulation Point(AP) multiple times so storing it as Hash instead of printing
                isArticulation[node] = 1;
            }

            // As each dfs() call represent individual child
            child++;
        }

        else{
            low[node] = std::min(low[node], inTime[x]);
        }
    }

    //If current node is a root node & has atleast 2 child
    if(parent == -1 && child > 1){
        isArticulation[node] = 1;
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
    
    std::vector<int> inTime(V, -1);
    std::vector<int> low(V, -1);
    std::vector<int> visited(V, 0);

    std::vector<int> isArticulation(V, -1); // Hash map in order to avoid duplicate elements

    int timer = 0;

    for (int i = 0; i < V; i++){
        if(!visited[i]){
            dfs(i, -1, isArticulation, visited, inTime, low, timer, adj);
        }
    }
    
    std::cout << "Articulation Points are : \n"; 
    for (int i = 0; i < V; i++){
        if(isArticulation[i] == 1){
            std::cout << i << " ";
        }
    }
    
    return 0;
}