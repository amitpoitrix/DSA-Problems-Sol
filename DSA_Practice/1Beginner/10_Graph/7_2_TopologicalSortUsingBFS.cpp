#include<iostream>
#include<vector>
#include<queue>
// Striver Graph Series : Topological Sort Using BFS (Kahn's Algorithm)
// Inorder - No. of Incoming edges to a vertex

class Solution{
public:
    std::vector<int> topoSort(int V, std::vector<int> adj[]){
        std::vector<int> inorder(V, 0);
        // Initialize an inorder vector
        for (int i = 0; i < V; i++){
            for (auto x : adj[i]){
                inorder[x]++;
            }
        }

        // Pushing the vertex in the queue having 0 inorder
        std::queue<int> q;
        for (int i = 0; i < V; i++){
            if(inorder[i] == 0){
                q.push(i);
            }
        }
        
        std::vector<int> res;

        while (!q.empty()){
            int vertex = q.front();
            q.pop();

            res.push_back(vertex);

            for (auto x : adj[vertex]){
                inorder[x]--;   // Reducing the inorder value of adjacent vertex
                if(inorder[x] == 0){
                    q.push(x);
                }
            }
        }
        
        return res;
    }
};

int main(){

    return 0;
}