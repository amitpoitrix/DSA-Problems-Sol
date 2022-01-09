#include<iostream>
// AdityaVerma DP Series : 1.Subset Sum Problem
// Return True/False if there is two or more subset exist that equals to Sum
// First variation of 0/1 Knapsack Problem
// TC/SC - O(sum*N)

// Using DP - Tabulation(or Bottom-Up Approach)
class Solution{
public:
    bool isSubsetSum(int N, int arr[], int sum){
        bool dp[N+1][sum+1];
        // Initialize the dp matrix
        for (int i = 0; i < N+1; i++){
            for (int j = 0; j < sum+1; j++){
                // when both N & sum is 0 than sum = {} can be achieve so return true
                if(i == 0 && j == 0)
                    dp[i][j] = true;
                    
                // 1. i = N = 0(i.e., there is no element) than sum can't be achieve so returning false
                else if(i == 0)
                    dp[i][j] = false; 
                
                // 2. j = sum = 0(i.e., if subset sum want is 0 that is {} empty subset) it can achieve with any no. of elements
                else if(j == 0)
                    dp[i][j] = true;
            }
        }

        // Starting loop from 1
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

int main(){
    int arr[] = {3,34,4,12,5,2};
    int N = sizeof(arr)/sizeof(int);
    int sum = 9;

    Solution obj;
    std::cout << obj.isSubsetSum(N, arr, sum);

    return 0;
}