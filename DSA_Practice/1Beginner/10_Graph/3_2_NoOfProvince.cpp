#include <bits/stdc++.h>
using namespace std;

// GFG: Number of Provinces
// https://practice.geeksforgeeks.org/problems/number-of-provinces/1

// Using DFS Traversal (can also use BFS)
// TC - O(V) + O(V + 2E)
// SC - O(V)
class Solution {
private:
    void dfs(int node, vector<int> adjLs[], int vis[]){
        vis[node] = 1;
        
        for(auto x: adjLs[node]){
            if(!vis[x])
                dfs(x, adjLs, vis);
        }
    }
    
public:
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> adjLs[V];
        // Converting Adjacency Matrix to Adjacency List
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(adj[i][j] == 1 && i != j){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        
        // vector<int> vis(V, 0);
        int vis[V] = {0};
        int cnt = 0;
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                cnt++;
                dfs(i, adjLs, vis);
            }
        }
        
        return cnt;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}