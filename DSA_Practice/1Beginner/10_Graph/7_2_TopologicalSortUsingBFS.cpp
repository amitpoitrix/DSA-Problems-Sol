#include<iostream>
#include<vector>
#include<queue>
// Striver Graph Series : Topological Sort Using BFS (Kahn's Algorithm)
// indegree - No. of Incoming edges to a vertex

// Idea:  Node with lesser indegree will come before than the node with greater indegree in the topological sort.

// Algo(DFS):
// 1. First get the indegree of each node & store it in an array. And becoz of this indegree[] we don't require visited[]
// 2. Push the node in queue with indegree = 0.
// 3. While queue is not empty
//      i) print the front node & pop it.
//      ii) decrement indegree of its adjacents
//      iii) If indegree becomes 0 then push the adjacent node in the queue.

// TC - O(V+E)
// SC - O(V) + O(V); 1st O(V) for Queue DS, 2nd for inDegree array
class Solution{
public:
    std::vector<int> topoSort(int V, std::vector<int> adj[]){
        std::vector<int> indegree(V, 0);
        // Finding inorder of all nodes
        for (int i = 0; i < V; i++){
            for (auto x : adj[i]){
                indegree[x]++;
            }
        }

        // Pushing the vertex/node into queue having 0 indegree
        std::queue<int> q;
        for (int i = 0; i < V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        std::vector<int> res;

        while (!q.empty()){
            int vertex = q.front();
            q.pop();
            // Now this current vertex/node from queue.front() is part of topo sort so pushing into resultant vector
            res.push_back(vertex);

            for (auto x : adj[vertex]){
                indegree[x]--;   // Reducing the indegree value of adjacent node by 1
                // And if indegree is 0 than push it into queue
                if(indegree[x] == 0){
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