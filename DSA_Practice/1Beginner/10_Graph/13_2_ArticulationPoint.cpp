#include<iostream>
#include<vector>
// Striver Graph Series : Articulation Point or Cut Vertex 
// Articulation point in a graph is the Node/Vertex removal of which leads to increase in the no. of components of graph
// Here we'll use DFS same as in Bridge in Graph
// A Node/Vertex in graph is Articulation Point/Cut Vertex if any of the condition is true :
// 1. A node is a root node(i.e., parent[node] == -1) & it has atleast 2 children(i.e, individual child that require individual DFS call)
// 2. u is not root of DFS tree and it has a child v such that no vertex in subtree rooted with v has a back edge to one of the ancestors 
// (in DFS tree) of u.
// 3. A leaf node cannot be an Articulation Point

void dfs(int node, int parent, std::vector<int> &isArticulation, std::vector<int> &visited, std::vector<int> &descTime, std::vector<int> &lowTime, int &timer, std::vector<int> adj[]){
    // 2nd condition of Articulation Point
    visited[node] = 1;
    descTime[node] = lowTime[node] = ++timer;
    int child = 0;

    for (auto x : adj[node]){
        if(x == parent)
            continue;

        if(!visited[x]){
            dfs(x, node, isArticulation, visited, descTime, lowTime, timer, adj);
            lowTime[node] = std::min(lowTime[node], lowTime[x]);
            // As each dfs() call represent individual child
            child++;
            // Condition for checking Articulation point as well as its parent should not be a root node(i.e., Starting node can't be a AP)
            if(lowTime[x] >= descTime[node] && parent != -1){
                // As we can get same Articulation Point(AP) multiple times so storing it as Hash instead of printing
                isArticulation[node] = 1;
            }
        }
        else{
            lowTime[node] = std::min(lowTime[node], descTime[x]);
        }
    }

    // 1st condition of Articulation Point i.e, if current node is a root node & has atleast 2 child
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
    
    std::vector<int> descTime(V, -1);
    std::vector<int> lowTime(V, -1);
    std::vector<int> visited(V, 0);
    std::vector<int> isArticulation(V, -1);
    int timer = 0;

    for (int i = 0; i < V; i++){
        if(!visited[i]){
            dfs(i, -1, isArticulation, visited, descTime, lowTime, timer, adj);
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