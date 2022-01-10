#include<iostream>
// AdityaVerma DP Series : 3. Count of Subset Sum(or Perfect Sum problem)
// Return count of subset whose sum equals to given sum
// Variation of Subset Sum Problem which itself is variation of 0/1 Knapsack Problem
// TC/SC - O(sum*N)

class Solution{
public:
    int mod = 1e9 + 7;  // As ans can be very large  1e9 + 7 = 1000000007

    int perfectSum(int arr[], int n, int sum){
        int dp[n+1][sum+1];
        for (int i = 0; i < n+1; i++){
            for (int j = 0; j < sum+1; j++){
                // Initializing dp[0][0] = 1 becoz of empty subset {} that counts to 1
                if(i == 0 && j == 0)
                    dp[i][j] = 1;

                // Only initializing first row as 0 from j = 1...sum
                else if(i == 0)
                    dp[i][j] = 0;
            }
        }

        for (int i = 1; i < n+1; i++){
            // Here we are starting j from 0 instead of 1 due to 0 as elements in given array
            for (int j = 0; j < sum+1; j++){
                if(arr[i-1] <= j)
                    dp[i][j] = (dp[i-1][j - arr[i-1] ] + dp[i-1][j]) % mod; // replacing || with + in subset Sum prblm
                
                else
                    dp[i][j] = (dp[i-1][j]) % mod;
            }
        }
        
        return (dp[n][sum]) % mod;
	}
};

int main(){
    int arr[] = {2,3,5,6,8,10};
    int N = sizeof(arr)/sizeof(int);
    int sum = 10;

    Solution obj;
    std::cout << obj.perfectSum(arr, N, sum);

    return 0;
}