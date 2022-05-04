#include<iostream>
#include<vector>
#include<stack>
// Striver Graph Series : Kosaraju's Algorithm to detect Strongly Connected Components(SCC) in Directed Graph
// SCC are components in which you start from any one node you can able to reach every other node in Directed Graph

// Algo:
// 1. Sort all the nodes in order of finishing times(i.e., Topological Sort)
// 2. Than we'll transpose the Graph so that we won't end up going to the other part(other SSC)
// Transpose of graph will just reverse the direction of directed graph
// 3. Perform DFS according to finishing time(i.e., topological sort) on transpose graph

// TC - O(V + E) + O(V + E) + O(V + E) ~ O(V+E); 1st for Topo Sort, 2nd for Transpose & 3rd for DFS again on Transpose graph 
// SC - O(V + E) + O(V) + O(V) ~ O(V + E)
// O(V+E) for tranpose graph, O(V) for visited[], O(V) for stack 

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
            // Making visited as not visisted
            visited[i] = 0; 
            // Earlier there was edge from i -> x
            for (auto x : adj[i]){
                // Now making edge from x -> i
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
                std::cout << "\n";  // New line to print each SCC components on next line
            }
        }
    }
};

int main(){
    int V, E;
    std::cin >> V >> E;

    std::vector<int> adj[V];

    for (int i = 0; i < E; i++){
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);    // As we are creating Directed Graph u -> v
    }
    
    Solution obj;
    obj.kosarajuAlgo(V, adj);

    return 0;
}