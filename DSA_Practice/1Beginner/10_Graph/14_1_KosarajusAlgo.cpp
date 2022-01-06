#include<iostream>
#include<vector>
#include<stack>
// Striver Graph Series : Kosaraju's Algorithm to detect Strongly Connected Components(SCC) in directed graph
// TC - O(V + E)
// SC - O(V + E)
// Algo : step 1: We'll do the topological sort in order to get finishing order time
// Step 2 : Than we'll transpose the Graph
// Step 3 : Then we'll apply DFS on transpose graph

class Solution{
private:
    void topoSortDFS(int node, std::stack<int> &st, std::vector<int> &visited, std::vector<int> adj[]){
        visited[node] = 1;

        for (auto x : adj[node]){
            if(!visited[x]){
                topoSortDFS(x, st, visited, adj);
            }
        }
        
        // After DFS we'll push  current node to stack in order to get Topo Sort
        st.push(node);
    }

    void revDFS(int node, std::vector<int> &visited, std::vector<int> transpose[]){
        // Printing the node element first than follows DFS traversal
        std::cout << node << " ";
        visited[node] = 1;
        for (auto x : transpose[node]){
            if(!visited[x]){
                revDFS(x, visited, transpose);
            }
        }
    }

public:
    void kosarajuAlgo(int V, std::vector<int> adj[]){
        std::vector<int> visited(V, 0);

        // Step 1 : Make a topological sort of given graph
        std::stack<int> st;
        for (int i = 0; i < V; i++){
            if(!visited[i]){
                topoSortDFS(i, st, visited, adj);
            }
        }
        
        // Step 2 : We'll transpose the graph
        std::vector<int> transpose[V];  // created transpose adjacency list
        for (int i = 0; i < V; i++){
            visited[i] = 0; // Making visited as not visisted
            for (auto x : adj[i]){
                transpose[x].push_back(i);
            }
        }
        
        // Step 3 : Now smartly Calling DFS on transpose graph
        while (!st.empty()){
            int node = st.top();
            st.pop();

            if(!visited[node]){
                std::cout << "SSC : ";
                revDFS(node, visited, transpose);
                std::cout << "\n";
            }
        }
    }
};

int main(){
    int V, E;
    std::cin >> V >> E;
    // Creating Adjacency List for Graph
    std::vector<int> adj[V];
    for (int i = 0; i < E; i++){
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);    // As we are creating Directed Graph
    }
    
    Solution obj;
    obj.kosarajuAlgo(V, adj);

    return 0;
}