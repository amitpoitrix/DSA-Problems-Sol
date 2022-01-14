#include<iostream>
#include<cstring>
// AdityaVerma DP Series : 0/1 Knapsack Problem 
// https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/

// Its a Parent Problem of DP having 6 varations
// 1. Subset Sum Problem
// 2. Partition Equal Subset Sum
// 3. Count Subset Sum
// 4. Min Sum Partition
// 5. Count Subset Difference
// 6. Target Sum - Leetcode Prblm same as 5th one

// memset() comes under <cstring> header file & should be used under some function else it'll through error
// and usually used to initialize 0 & -1

// Naive Approach - Normal Recursive Solution
// TC - O(2^N) i.e, Exponential Time, SC - O(1) as we are not using any extra DS for storage 
// except for recursive call stack(auxiliary space of O(N))
class Solution{
public:
    int KnapSack(int W, int wt[], int val[], int n){
        if(n == 0 || W == 0)
            return 0;
        
        // In recursion we'll check from last element [n-1] element
        else if(wt[n-1] <= W)
            return std::max(val[n-1] + KnapSack(W - wt[n-1], wt, val, n-1), KnapSack(W, wt, val, n-1));
        
        // if wt[n-1] > W
        else
            return KnapSack(W, wt, val, n-1);
    }
};

// Using DP
// Approach 1 : Using Memoization(or Top-Down Approach) - Recursive Method of DP
// TC - O(N*W), SC - O(N*W) where, N - No. of Elements, W - Knapsack(Weight)
class SolutionDP1{
public:
    // Taking Global matrix[][] in order to store state of each (ni,Wi)
    int dp[101][101];   // As system can't handle [1001][1001]

    int knp(int W, int wt[], int val[], int n){
        // Base condition - if No element or No capacity to store than return 0
        if(W == 0 || n == 0)
            return 0;   // here profit(or value or val[]) is being return as 0 
        
        // Is the state of matrix[n][W] is already computed before... than return that state value
        else if(dp[n][W] != -1)
            return dp[n][W];

        // If state of matrix[n][W] not computed before than compute it and store it in dp[n][W]
        // Here we start checking weight from last[n-1] item weights
        else if(wt[n-1] <= W){
            return dp[n][W] = std::max(val[n-1] + knp(W - wt[n-1], wt, val, n-1), knp(W, wt, val, n-1));
        }

        // else if(wt[n-1] > W)
        else
            return dp[n][W] = knp(W, wt, val, n-1);
    }

    int KnapSack(int W, int wt[], int val[], int n){
        // In memoization method we initialize matrix[][] state with -1 
        std::memset(dp, -1, sizeof(dp));
        return knp(W, wt, val, n);
    }

};

// Approach 2 : Tabulation(or Bottom-Up Approach) - Iterative Method of DP
// TC - O(N*W), SC - O(N*W)
class SolutionDP2{
public:
    int KnapSack(int W, int wt[], int val[], int n){
        int dp[n+1][W+1];   // +1 becoz indexing is from 0 as we have to return dp[n][W] as ans
        
        for (int i = 0; i < n+1; i++){
            for (int j = 0; j < W+1; j++){
                // Initialize dp[][] having 1st row & column as 0
                if(i == 0 || j == 0){
                    //when there is no element OR there is no capacity left than profit(or value) is being return as 0
                    dp[i][j] = 0;
                }   

                else if(wt[i-1] <= j){
                    dp[i][j] = std::max(val[i-1] + dp[i-1][ j - wt[i-1] ], dp[i-1][j]);
                }
                else    
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[n][W];
    }
};

// Improvement to Space Complexity of Tabulation Method(or Bottom-Up Approach)
// TC - O(N*W), SC - O(2*W)
class SolutionDP3{
public:
    int KnapSack(int W, int wt[], int val[], int n){
        // instead of taking dp[n+1][W+1] we'll take dp[2][W] as only two rows are being used all the time
        int dp[2][W+1];

        for (int i = 0; i < n+1; i++){
            for (int j = 0; j < W+1; j++){
                if(i == 0 || j == 0)
                    dp[i % 2][j] = 0; // i%2 will make sure to bound the value of i in {0,1}
                
                else if(wt[i-1] <= j)
                    dp[i % 2][j] = std::max(val[i-1] + dp[(i-1) % 2][j - wt[i-1] ], dp[(i-1) % 2][j] );
                
                else
                    dp[i % 2][j] = dp[(i-1) % 2][j];
            }
        }
        
        return dp[n % 2][W];
    }
};

int main(){
    int val[] = {1,2,3,4};
    int wt[] = {4,5,2,1};
    int W = 6;
    int n = sizeof(val)/sizeof(int);

    SolutionDP3 obj;
    std::cout << "Max Profit : " << obj.KnapSack(W, wt, val, n);

    return 0;
}