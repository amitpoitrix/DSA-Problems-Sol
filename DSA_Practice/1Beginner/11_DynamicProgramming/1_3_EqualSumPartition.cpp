#include<iostream>
// AdityaVerma DP Series : 2. Partition Equal Subset Sum (or Equal Sum Partition)
// https://www.geeksforgeeks.org/partition-problem-dp-18/
// Return True/False if there exist exactly two subsets whose sum are equal
// Variation of Subset Sum Problem which itself is variation of 0/1 Knapsack Problem

// Using DP - Tabulation(or Bottom-Up Approach)
// TC/SC - O(sum*N)
class Solution{
private:
    bool subsetSum(int N, int arr[], int sum){
        int dp[N+1][sum+1];
        // When sum is 0 store true in 1st column only when result is ask in boolean
        for (int i = 0; i < N+1; i++){
            dp[i][0] = true;
        }

        // When sum is not 0 store false & start i from 1 as dp[0][0] should be true
        for (int i = 1; i < sum+1; i++){
            dp[0][i] = false;
        }

        for (int i = 1; i < N+1; i++){
            for (int j = 1; j < sum+1; j++){
                if(arr[i-1] <= j)
                    dp[i][j] = dp[i-1][j - arr[i-1] ] || dp[i-1][j];
                
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[N][sum];
    }

public:
    bool equalPartition(int N, int arr[]){
        int sum = 0;
        for (int i = 0; i < N; i++){
            sum += arr[i];
        }
        
        // If sum is odd than equal sum partition is not possible so return false
        if((sum % 2) != 0)
            return false;

        else{
            // if first subset having subset sum than both subsets have equal sum
            return subsetSum(N, arr, sum/2);
        }
    }
};

int main(){
    int arr[] = {1,5,11,5};
    int N = sizeof(arr)/sizeof(int);

    Solution obj;
    if(obj.equalPartition(N, arr))
        std::cout << "Yes, Equal sum partition is possible";
    else
        std::cout << "No, Equal sum partition is not possible";

    return 0;
}