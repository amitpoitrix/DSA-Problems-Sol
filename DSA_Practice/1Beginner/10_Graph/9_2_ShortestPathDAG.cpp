#include<iostream>
#include<vector>
#include<stack>
// Striver Graph Series : Shortest Path in Directed Acyclic Graph(DAG)
// Here we'll make use of Topological Sort using DFS
// 1e9 = 1 * 10 to the 9th power i.e., 1 billion (1,000,000,000)

class Solution{
private:
    void findTopoSort(int node, int vis[], std::stack<int> &st, std::vector<std::pair<int, int>> adj[]){
        vis[node] = 1;

        for (auto x : adj[node]){
            if(!vis[x.first]){
                findTopoSort(x.first, vis, st, adj);
            }
        }
        
        st.push(node);
    }

public:
    void shortestPathDAG(int V, std::vector<std::pair<int, int>> adj[], int src){
        int vis[V] = {0};
        std::stack<int> st;
        for (int i = 0; i < V; i++){
            if(!vis[i]){
                findTopoSort(i, vis, st, adj);
            }
        }

        int path[V];
        for (int i = 0; i < V; i++){
            path[i] = 1e9;
        }
        path[src] = 0;

        while (!st.empty()){
            int vertex = st.top();
            st.pop();

            // If path has been visited before
            if(path[vertex] != 1e9){
                for (auto x : adj[vertex]){
                    if(path[vertex] + x.second < path[x.first])
                        path[x.first] = x.second + path[vertex];
                }
            }
        }
        
        for (int i = 0; i < V; i++){
            (path[i] == 1e9) ? std::cout << "INF " : std::cout << path[i] << " ";
        }
        
    }
};

int main(){
    int V, E;
    std::cin >> V >> E;

    std::vector<std::pair<int, int>> adj[V];

    for (int i = 0; i < E; i++){
        int u, v, wt;
        std::cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }
    
    Solution obj;
    obj.shortestPathDAG(V, adj, 1);

    return 0;
}

// 6 9
// 0 1 5
// 0 2 3
// 1 3 6
// 1 2 2
// 2 4 4
// 2 5 2
// 2 3 7
// 3 4 -1
// 4 5 -2