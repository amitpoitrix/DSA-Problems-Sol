#include<iostream>
#include<cstring>
// AdityaVerma DP Series : 1.Subset Sum Problem
// https://www.geeksforgeeks.org/subset-sum-problem-dp-25/
// Return True/False if there exist a subset whose sum equals to a given Sum
// First variation of 0/1 Knapsack Problem

// Naive Approach - Using Recursion
// TC - Exponential, SC - O(N) (Auxiliary Space)
class Solution{
public:
    bool isSubsetSum(int N, int arr[], int sum){
        // if sum is 0
        if(sum == 0)
            return true;
        
        // if no other element is left
        else if(N <= 0)
            return false;
        
        // if current element in array is less than or equal to sum than we make a choice of choosing it or not
        else if(arr[N-1] <= sum)
            return isSubsetSum(N-1, arr, sum - arr[N-1]) || isSubsetSum(N-1, arr, sum);

        // arr[N-1] > sum i.e, when we are not considering the element
        else
            return isSubsetSum(N-1, arr, sum);
    }
};

// Using DP
// Approach 1 - Memoization(or Top-Down Approach)
// TC - O(N*sum), SC - O(N*sum) (Auxiliary Space)
class SolutionDP1{
public:
    // Taking Global matrix
    int dp[101][101];   // take size dp[1001][1001] for test case to pass

    bool checkSubsetSum(int N, int arr[], int sum){
        if(sum == 0)
            return 1;
        
        else if(N <= 0)
            return 0;

        // If dp[N-1][sum] is already computed before
        else if(dp[N-1][sum] != -1)
            return dp[N-1][sum];

        // else if dp[N-1][sum] is not yet computed than compute it and store it in dp[][]
        else if(arr[N-1] <= sum)
            return dp[N-1][sum] = checkSubsetSum(N-1, arr, sum - arr[N-1]) || checkSubsetSum(N-1, arr, sum);
        
        else
            return dp[N-1][sum] = checkSubsetSum(N-1, arr, sum);
    }

    bool isSubsetSum(int N, int arr[], int sum){
        std::memset(dp, -1, sizeof(dp));
        return checkSubsetSum(N, arr, sum);
    }
};

// Approach 2 - Tabulation(or Bottom-Up Approach)
// TC - O(N*sum), SC - O(N*sum)
class SolutionDP2{
public:
    bool isSubsetSum(int N, int arr[], int sum){
        bool dp[N+1][sum+1];
        // Initialize the dp matrix for Subset Sum
        // When sum is 0 store true in 1st column only when result is ask in boolean
        for (int i = 0; i < N+1; i++)
            dp[i][0] = true;
        
        // When sum is not 0 store false & start i from 1 as dp[0][0] should be true
        for (int i = 1; i < sum+1; i++)
            dp[0][i] = false;
        
        // Starting loop from 1 as index 0 of i(0..N) & j(0..sum) is already processed
        for (int i = 1; i < N+1; i++){
            for (int j = 1; j < sum+1; j++){
                // replacing wt[] with arr[] & ignoring val[] in 0/1 knapsack 
                if(arr[i-1] <= j){
                    // suppose in subset we already consider 3 i.e., {3, } than whether to consider 8(which is next element) or not
                    dp[i][j] = dp[i-1][j - arr[i-1] ] || dp[i-1][j];
                }
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[N][sum];
    }
};

// Space Complexity Optimization in Tabulation Approach
// TC - O(N*sum) , SC - O(2*sum)
class SolutionDP3{
public:
    bool isSubsetSum(int N, int arr[], int sum){
        bool dp[2][sum+1];

        for (int i = 0; i < N+1; i++){
            for (int j = 0; j < sum+1; j++){
                // if sum is 0
                if(j == 0)
                    dp[i % 2][j] = true;
                
                // Sum is not 0
                else if(i == 0)
                    dp[i % 2][j] = false;
                
                else if(arr[i-1] <= j)
                    dp[i % 2][j] = dp[(i-1) % 2][j - arr[i-1] ] || dp[(i-1) % 2][j];

                else
                    dp[i % 2][j] = dp[(i-1) % 2][j];
            }
        }
        
        return dp[N % 2][sum];
    }
};

int main(){
    int arr[] = {3,34,4,12,5,2};
    int N = sizeof(arr)/sizeof(int);
    int sum = 9;

    SolutionDP1 obj;
    if(obj.isSubsetSum(N, arr, sum))
        std::cout << "Yes";
    else
        std::cout << "No";

    return 0;
}