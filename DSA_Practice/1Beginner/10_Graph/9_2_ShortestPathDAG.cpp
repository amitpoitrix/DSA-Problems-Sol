#include<iostream>
#include<vector>
#include<stack>
// Striver Graph Series : Shortest Path in Weighted Directed Acyclic Graph(DAG)
// Here we'll make use of Topological Sort using DFS (i.e., using stack where we push node into stack only when its dfs is done)
// 1e9 = 1 * 10 to the 9th power i.e., 1 billion (1,000,000,000)

// Algo:
// 1. Store Topological Sort in stack using DFS
// 2. Make a distance array, mark src as 0 & all other nodes as MAX
// 3. Now apply BFS on constructed stact as While stack is not empty
//      a) pop(let say node u is popped)
//      b) If current node dist is not MAX than only calculate its adjacent node distance
//      c) see the adjacent nodes of u, dist of adjacent node = min(dist[adjacent node], dist[u] + weight on edge of u & adj. node)

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
        int vis[V] = {0};   // Assigning all elements of array of size V as 0
        std::stack<int> st;
        for (int i = 0; i < V; i++){
            if(!vis[i]){
                // DFS
                findTopoSort(i, vis, st, adj);
            }
        }

        // Taking distance[] of size V & initialise each element with 1e9
        // BFS with constructed stack
        int dist[V];
        for (int i = 0; i < V; i++){
            dist[i] = 1e9;
        }
        dist[src] = 0;

        while (!st.empty()){
            int vertex = st.top();
            st.pop();

            // If dist has been visited before than don't compute its adjacent nodes as there might be case when there is 
            // component of graph
            if(dist[vertex] != 1e9){
                for (auto x : adj[vertex]){
                    if(dist[vertex] + x.second < dist[x.first])
                        dist[x.first] = x.second + dist[vertex];
                }
            }
        }
        
        for (int i = 0; i < V; i++){
            (dist[i] == 1e9) ? std::cout << "INF " : std::cout << dist[i] << " ";
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