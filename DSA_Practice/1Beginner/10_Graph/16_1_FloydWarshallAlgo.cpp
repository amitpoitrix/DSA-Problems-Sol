#include<iostream>
#include<vector>
using namespace std;

// Striver SDE Sheet: Floyd Warshall Algorithm: 
// https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/
// Is is used to find shortest path btw pair of all vertices in a graph
// It can works on -ve edge weights but fails to work on -ve edge weight cycle

// TC - O(V^3)
// SC - O(V^2); As we are using another matrix
class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
        int n = matrix.size();
	    vector<vector<int>> graph(n, vector<int>(n));

        // Copying the input matrix[][] in graph[][] 
        for(int i=0; i < n; i++){
            for(int j=0; j < n; j++){
                graph[i][j] = matrix[i][j];
            }
        }

        // Now calculating the shortest path btw pair of all vertices via intermediate vertex
        for(int k=0; k < n; k++){
            for(int i=0; i < n; i++){
                for(int j=0; j < n; j++){
                    // If intermediate node is not -1
                    if(graph[i][k] != -1 && graph[k][j] != -1){
                        if(graph[i][j] == -1)
                            graph[i][j] = graph[i][k] + graph[k][j];
                        
                        else
                            graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                    }
                }
            }
        }

        // Copying back to original array
        for(int i=0; i < n; i++){
            for(int j=0; j < n; j++){
                matrix[i][j] = graph[i][j];
            }
        }
	}
};


// In-place Method
// TC - O(V^3)
// SC - O(1)
#define MAX 1e9
class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
        int n = matrix.size();

        for(int k=0; k < n; k++){
            for(int i=0; i < n; i++){
                for(int j=0; j < n; j++){
                    // if i & k or k & i are equal or start or end & intermediate node is not reachable i.e., -1 than ignore it
                    if(i == k || j == k || matrix[i][k] == -1 || matrix[k][j] == -1){
                        continue;
                    }

                    // Replacing unreachable node from -1 to MAX
                    else if(matrix[i][j] == -1)
                        matrix[i][j] = MAX;
                    
                    // Assigning min distance for all pairs
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }
    }
};

int main(){
    return 0;
}