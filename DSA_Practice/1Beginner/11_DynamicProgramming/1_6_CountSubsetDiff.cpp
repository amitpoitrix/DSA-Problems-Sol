#include<iostream>
// AdityaVerma DP Series : 5. Count No. of Subset with given difference
// Return count of subset whose difference is equal to given diff
// Variation of Subset Sum Problem which itself is variation of 0/1 Knapsack Problem
// TC/SC - O(sum*N)

class Solution{
private:
    int countSubsetSum(int arr[], int n, int sum){
        int dp[n+1][sum+1];
        for (int i = 0; i < n+1; i++){
            dp[i][0] = 1;
        }
        for (int j = 1; j < sum+1; j++){
            dp[0][j] = 0;
        }
        
        
        
    }

public:
    int countSubsetDiff(int arr[], int n, int diff){
        int sum = 0;
        for (int i = 0; i < n; i++){
            sum += arr[i];
        }
        
        int s2 = abs(sum - diff)/2;

        return countSubsetSum(arr, n, s2);
    }
};

int main(){

    return 0;
}