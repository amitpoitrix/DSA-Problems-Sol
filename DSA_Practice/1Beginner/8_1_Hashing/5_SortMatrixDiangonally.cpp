#include<bits/stdc++.h>
using namespace std;

// Lt: 1329. Sort the Matrix Diagonally
// https://leetcode.com/problems/sort-the-matrix-diagonally/

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        
        //map of {int, min_heap}
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp;
        
        // Storing the elements in each diagonal(determine by i-j) by making sure 
        // that smaller elements will be at top using minHeap 
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                mp[i-j].push(mat[i][j]);
            }
        }
        
        // Now traversing matrix again to get the elements back from map of minHeap
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                mat[i][j] = mp[i-j].top();
                mp[i-j].pop();
            }
        }
        
        return mat;
    }
};

int main(){
    return 0;
}