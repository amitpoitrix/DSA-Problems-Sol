#include<iostream>
#include<vector>
#include<queue>
// Striver Graph Series : Detect Cycle in Directed Graph Using BFS
// Here we'll use Kahn's Algorithm - As it is used to give Topological Sort in DAG so if it fails to create topological sort than
// definitely there is a cycle in a graph

class Solution{
public:
    bool isCyclic(int V, std::vector<int> adj[]){
        std::vector<int> inorder(V, 0);
        for (int i = 0; i < V; i++){
            for (auto x : adj[i]){
                inorder[x]++;
            }
        }

        std::queue<int> q;
        for (int i = 0; i < V; i++){
            if(inorder[i] == 0)
                q.push(i);
        }
        
        int count = 0;
        while (!q.empty()){
            int vertex = q.front();
            q.pop();
            count++;
            for (auto x : adj[vertex]){
                inorder[x]--;
                if(inorder[x] == 0)
                    q.push(x);
            }
        }
        
        if(count == V)
            return false;
        
        return true;
    }
};

int main(){

    return 0;
}