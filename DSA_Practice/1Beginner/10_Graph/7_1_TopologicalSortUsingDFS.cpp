#include<iostream>
#include<vector>
#include<stack>
// Striver Graph Series : Topological Sort Using DFS
// This sort is a linear ordering of vertices such that if there is an edge u->v, then u will appear before v in that ordering
// Topological Sort only works on DAG(Directed Acyclic Graph)
// There can be multiple topological sort for a given DAG

// Algo (BFS):
// 1. Maintain a visited[] and stack to store the topological sort
// 2. If adjacents of current node are done than push it into the stack(that means dfs of current node is done & there is 
// no further adjecent node left to visit)

// TC - O(V+E)
// SC - O(V) + O(V) + O(V); first one is for visited array, 2nd for recursive stack space, 3rd one is for stack DS used
class Solution{
private:
    void graphSort(int node, std::vector<int> &vis, std::stack<int> &st, std::vector<int> adj[]){
        vis[node] = 1;  // Marking the node as visited

        for (auto x : adj[node]){
            if(!vis[x]){
                graphSort(x, vis, st, adj);
            }
        }
        
        // As DFS call is over for current node, just push this node into the stack becoz it's LIFO property help us in 
        // determining Topological sort
        st.push(node);
    }

public:
	//Function to return list containing vertices in Topological order. 
	std::vector<int> topoSort(int V, std::vector<int> adj[]) {
	    std::vector<int> vis(V, 0);
        std::stack<int> st;

        for (int i = 0; i < V; i++){
            if(!vis[i]){
                graphSort(i, vis, st, adj);
            }
        }

        std::vector<int> res;
        while (!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        
        return res;
	}
};

int main(){

    return 0;
}