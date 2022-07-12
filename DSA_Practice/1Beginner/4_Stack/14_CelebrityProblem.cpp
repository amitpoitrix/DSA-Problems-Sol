#include<bits/stdc++.h>
using namespace std;

// The Celebrity Problem 
// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1

// Approach 1:
// TC - O(n^2)
// SC - O(n)
class Solution{
public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) {
        int in[n] = {0};
        int out[n] = {0};
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(M[i][j] == 1){
                    in[j]++;
                    out[i]++;
                }
            }
        }
        
        // Checking for celebrity from 0th to (n-1)th person
        for(int i = 0; i < n; i++){
            if(in[i] == n-1 && out[i] == 0)
                return i;
        }
        
        return -1;
    }
};

// Approach 2:
// TC - O(n)
// SC - O(1)
class Solution2{
public:
    int celebrity(vector<vector<int> >& M, int n) {
        int c = 0;
        for(int i = 1; i < n; i++){
            if(M[c][i] == 1)
                c = i;
        }
        
        for(int i = 0; i < n; i++){
            if(i != c && (M[c][i] == 1 || M[i][c] == 0))
                return -1;
        }
        
        return c;
    }
};

int main(){
    return 0; 
}