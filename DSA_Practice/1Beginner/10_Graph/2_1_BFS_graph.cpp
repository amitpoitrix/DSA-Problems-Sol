#include<iostream>
#include<vector>
#include<queue>
//Striver Graph Series : Breadth First Search (BFS) Traversal of Graph
// Brief: A BFS traversal starting from root traverse first all its child nodes than only it move to next level
// Algo:
// 1. Take a queue & a visited array.
// 2. Push initial node in queue & mark it as visited.
// 3. while queue is not empty:
//      a) pop the front node & print it
//      b) push its adjacent nodes in queue if they are not visited & mark them visited
// 4. Repeat step 3 for each component.

// TC - O(V + E)
// SC - O(V + E) + O(V) + O(V)  ; O(V+E) -> For using Adjacency List, O(V) -> Visited Array, O(V) -> for Queue

// Application of BFS :

// 1. Shortest Path in an unweighted graph
// 2. Cycle Detection
// 3. Crawlers in Search Engine
// 4. Social Networking Search
// 5. In Garbage Collection
// 6. Broadcasting

// Leetcode Post : https://leetcode.com/discuss/interview-question/1408203/2-bfs-for-graphs

class Solution{
public:
    std::vector<int> bfsOfGraph(int V, std::vector<int> adj[]){
        std::vector<int> bfs;
        std::vector<int> visited(V, 0); // O based indexing of Graph having each value initialise to 0(i.e., Not visited)

        std::queue<int> q;
        q.push(0);  // Inserting the 1st Vertex into queue
        visited[0] = 1; // Marking 1st vertex as visisted after inserting into queue

        while (!q.empty()){
            // Removing vertex/node from queue
            int node = q.front();
            q.pop();

            //Print the node
            bfs.push_back(node);

            // Taking out all non-visited adjacent nodes of current node 
            for (auto it : adj[node]){
                if(!visited[it]){
                    q.push(it);
                    visited[it] = 1;
                }
            }
        }
        
        return bfs;
    }
};

int main(){
    int V, E;
    std::cin >> V >> E;

    // Creating Array of list of size V -> No. of Vertex
    std::vector<int> adj[V];    

    // Adding edges
    for (int i = 0; i < E; i++){
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    Solution* obj = new Solution();     // or Solution obj; // call its function with . instead of ->
    std::vector<int> res = obj->bfsOfGraph(V, adj);

    for (auto x : res){
        std::cout << x << " ";
    }
    
    return 0;
}

// Input
// 5 7
// 0 1
// 0 4
// 1 2
// 1 3
// 1 4
// 2 3
// 3 4