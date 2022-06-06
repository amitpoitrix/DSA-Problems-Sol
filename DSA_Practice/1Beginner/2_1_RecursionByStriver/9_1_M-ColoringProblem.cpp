#include<iostream>
// Recursion by Striver : L16. M-Coloring Problem | Backtracking - Graph Problem
// https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1#

// TC - O(N^m) where n -> no. of nodes & m -> No. of Colors
// SC - O(N) + O(N)
class Solution{
private:
    bool isSafe(int col, int node, int color[], bool graph[101][101], int V){
        // Checking if adjacent nodes have same color or not
        for (int k = 0; k < V; k++){
            if( k != node && graph[k][node] == 1 && color[k] == col){
                return false;
            }
        }
        return true;
    }

    bool mColoring(int node, int color[], bool graph[101][101], int m, int V){
        if(node == V){
            return true;
        }

        // Else will start looping for color strting from 1...m
        for (int col = 1; col <= m; col++){
            if(isSafe(col, node, color, graph, V)){
                color[node] = col;

                if(mColoring(node + 1, color, graph, m, V))
                    return true;

                color[node] = 0;
            }
        }
    
        return false;
    }

public:
    bool graphColoring(bool graph[101][101], int m, int V)
    {
        // Assigning color[] as each node having color as 0
        int color[V] = {0};
        // Starting from 0th node
        if(mColoring(0, color, graph, m, V) == true)
            return true;
    
        return false;
    }
};

int main(){


    return 0;
}