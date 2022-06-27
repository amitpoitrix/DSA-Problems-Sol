#include<iostream>
#include<vector>
using namespace std;
// DP by Striver: DP 48. Matrix Chain Multiplication | MCM | Partition DP Starts

// Memoization
// TC - O(n*n) * O(n) ~ O(n^3)
// SC - O(n^2) + O(n)
class Solution{
private:
    int f(int i, int j, vector<int> &arr, vector<vector<int>> &dp){
        // Base Case
        if(i == j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int mini = 1e9;
        for(int k = i; k <= j-1; k++){
            int steps = (arr[i-1] * arr[k] * arr[j]) 
                        + f(i, k, arr, dp) + f(k+1, j, arr, dp);
            mini = min(mini, steps);
        }
        
        return dp[i][j] = mini;
    }

public:
    int matrixMultiplication(vector<int> &arr, int N){
        vector<vector<int>> dp(N, vector<int>(N, -1));
        return f(1, N-1, arr, dp);
    }
};

// Tabulation
// TC - O(n^3)
// SC - O(n^2)
class Solution1{
public:
    int matrixMultiplication(vector<int> &arr, int N){
        vector<vector<int>> dp(N, vector<int>(N, 0));
        // Base Case - Optional
        for(int i=1; i < N; i++){
            dp[i][i] = 0;
        }
        
        for(int i=N-1; i >= 1; i--){
            for(int j = i + 1; j <= N-1; j++){
                int mini = 1e9;
                for(int k = i; k <= j-1; k++){
                    int steps = (arr[i-1] * arr[k] * arr[j]) + dp[i][k] + dp[k+1][j];
                    mini = min(mini, steps);
                }
                dp[i][j] = mini;
            }
        }
        
        return dp[1][N-1];
    }
};

int main(){
    return 0;
}