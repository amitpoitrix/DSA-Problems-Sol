#include<iostream>
#include<cstring>
// AdityaVerma DP Series : 0/1 Knapsack Problem 
// Its a Parent Problem of DP having 6 varations

// memset() comes under <cstring> header file & should be used under some function else it'll through error
// and usually used to initialize 0 & -1

// Using DP - TC - O(N*W), SC - O(N*W)
// Approach 1 : Using Memoization(or Top-Down Approach) - Recursive Method of DP
class Solution{
public:
    // We take matrix[n][W] paremeters whose value change after each recursive calls
    // take matrix of size of contraints+1
    int dp[101][101];   // As system can't handle [1001][1001]
    int knp(int W, int wt[], int val[], int n){
        // Base condition
        if(W == 0 || n == 0)
            return 0;
        
        if(dp[n][W] != -1)
            return dp[n][W];

        // Recursive condition
        // Here we start checking weight from last[n-1] item weights
        if(wt[n-1] <= W){
            return dp[n][W] = std::max(val[n-1] + knp(W - wt[n-1], wt, val, n-1), knp(W, wt, val, n-1));
        }
        else if(wt[n-1] > W)
            return dp[n][W] = knp(W, wt, val, n-1);
    }

    int KnapSack(int W, int wt[], int val[], int n){
        std::memset(dp, -1, sizeof(dp));
        return knp(W, wt, val, n);
    }

};

// Approach 2 : Tabulation(or Bottom-Up Approach) - Iterative Method of DP
class Solution2{
public:
    int KnapSack(int W, int wt[], int val[], int n){
        int dp[n+1][W+1];
        // Initialize dp[][] having 1st row & column as 0
        for (int i = 0; i < n+1; i++){
            for (int j = 0; j < W+1; j++){
                dp[i][j] = 0;   // Here 0 is the base case return value of Memoization approach
            } 
        }

        // Now we'll start loop from 1
        for (int i = 1; i < n+1; i++){
            for (int j = 1; j < W+1; j++){
                // Here we start checking weight from first[0] item weights
                if(wt[i-1] <= j){
                    dp[i][j] = std::max(val[i-1] + dp[i-1][ j - wt[i-1] ], dp[i-1][j]);
                }
                else    
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[n][W];
    }
};

int main(){
    int val[] = {1,2,3};
    int wt[] = {4,5,1};
    int W = 4;
    int n = sizeof(val)/sizeof(int);

    Solution2 obj;
    std::cout << "Max Profit : " << obj.KnapSack(W, wt, val, n);

    return 0;
}