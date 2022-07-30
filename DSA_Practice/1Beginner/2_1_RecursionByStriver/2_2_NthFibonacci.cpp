#include <bits/stdc++.h>
using namespace std;
  
// Using Most Optimized Approach 
// TC - O(log n)
// SC - O(log n)
class Solution{
private:
    // Function to Multiply (2 x 2) matrix
    vector<vector<long>> multiply(vector<vector<long>> mat1, vector<vector<long>> mat2){
        vector<vector<long>> res(2, vector<long> (2, 0));
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                for(int k = 0; k < 2; k++){
                    res[i][j] += mat1[i][k] * mat2[k][j] % 1000000007;
                }
            }
        }
        
        return res;
    }

    vector<vector<long>> fib(vector<vector<long>> &mat, int n){
        // Base Case
        if(n == 1) return mat;
        // Recursive Call
        vector<vector<long>> temp = fib(mat, n/2);
        // If n is even
        if(n%2 == 0) 
            return multiply(temp, temp);
        // if n is odd
        return multiply(temp, multiply(temp, mat));
    }

public:
    int Solution::solve(int A) {
        vector<vector<long>> mat = {
            {1, 1},
            {1, 0}
        };
        
        vector<vector<long>> ans = fib(mat, A);
        return ans[1][0] % 1000000007;  // or ans[0][1]
    }
};

int main(){
    return 0;
}