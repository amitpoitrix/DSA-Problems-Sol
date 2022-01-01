#include<iostream>
#include<vector>
#include<stack>
// Striver Graph Series : Topological Sort Using DFS
// This sort is a linear ordering of vertices such that if there is an edge u->v, than u will appear before v in that ordering
// works only on DAG(Directed Acyclic Graph)
// There can be multiple topological sort for a given DAG

class Solution{
private:
    void graphSort(int node, std::vector<int> &vis, std::stack<int> &st, std::vector<int> adj[]){
        vis[node] = 1;  // Marking the node as visited

        for (auto x : adj[node]){
            if(!vis[x]){
                graphSort(x, vis, st, adj);
            }
        }
        
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