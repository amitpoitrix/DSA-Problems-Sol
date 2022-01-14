#include<iostream>
#include<cstring>
// AdityaVerma DP Series : 3. Count of Subset Sum(or Perfect Sum problem)
// https://www.geeksforgeeks.org/count-of-subsets-with-sum-equal-to-x/
// Return count of subset whose sum equals to given sum
// Variation of Subset Sum Problem which itself is variation of 0/1 Knapsack Problem

// Using DP
// Approach 1 : Memoization(or Top-Down Approach)
// TC - O(N*sum) , SC - O(N*sum)
class SolutionDP1{
private:
    int dp[101][101];   // make dp[1001][1001] for test cases to passed 
    int mod = 1e9 + 7;
public:
    int countSubsetSum(int arr[], int n, int sum){
        if(sum == 0 && n == 0)
            return 1;

        else if(n <= 0)
            return 0;

        else if(dp[n][sum] != -1)
            return dp[n][sum];
        
        else if(arr[n-1] <= sum)
            return dp[n][sum] = (countSubsetSum(arr, n-1, sum - arr[n-1]) + countSubsetSum(arr, n-1, sum)) % mod;

        else
            return dp[n][sum] = (countSubsetSum(arr, n-1, sum)) % mod;
    }

    int perfectSum(int arr[], int n, int sum){
        std::memset(dp, -1, sizeof(dp));
        return countSubsetSum(arr, n, sum);
    }
};

// Approach 2 : Tabulation(or Bottom-Up Approach)
// TC/SC - O(sum*N)
class SolutionDP2{
public:
    int mod = 1e9 + 7;  // As ans can be very large  1e9 + 7 = 1000000007

    int perfectSum(int arr[], int n, int sum){
        int dp[n+1][sum+1];
        // Initialize dp[][]
        // if sum is 0 than store 1..... as we are only initializing the dp[0][0] instead of entire 1st column 
        // becoz of 0 as element in given array & target sum is 0 so it will consider both {} & {0} as count 1(total count = 2)
        dp[0][0] = 1;
   
        // if sum is not 0 than store 0 & start i from 1
        for (int i = 1; i < sum+1; i++){
            dp[0][i] = 0;
        }

        for (int i = 1; i < n+1; i++){
            // Here we are starting j from 0 instead of 1 becoz j = 0(1st column) is not initialised yet
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
    int arr[] = {0,0,1,0};
    int N = sizeof(arr)/sizeof(int);
    int sum = 0;

    SolutionDP1 obj;
    std::cout << obj.perfectSum(arr, N, sum);

    return 0;
}