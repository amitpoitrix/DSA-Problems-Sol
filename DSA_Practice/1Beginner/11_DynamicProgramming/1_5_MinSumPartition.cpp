#include<iostream>
#include<vector>
#include<numeric>
#include<limits.h>
// AdityaVerma DP Series : 4. Minimum Sum Partition (or Min Subset Sum difference)
// https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/
// Return min diff of two subset sum of a array
// Variation of Subset Sum Problem which itself is variation of 0/1 Knapsack Problem

// Naive Approach - Using Recursion
// TC - O(2^N), SC - ?
class Solution{
private:
    int countMinDifference(int arr[], int n, int calculatedSum, int sum){
        // If last element is reach than return abs(S1 - S2) or abs(sum - 2*S1)
        if(n == 0)
            return abs(sum - 2 * calculatedSum);
        
        // If last element is not yet reach than we'll take min(S1, S2) where two case arise
        // 1. if current elment arr[n-1] to be consider in S1
        // 2. if we won't consider current elment arr[n-1] than it is being used in S2 
        else
            return std::min(countMinDifference(arr, n-1, calculatedSum + arr[n-1], sum), countMinDifference(arr, n-1, calculatedSum, sum));
    }

public:
    int minDifference(int arr[], int n){
        int sum = 0;
        for (int i = 0; i < n; i++){
            sum += arr[i];
        }
        
        return countMinDifference(arr, n, 0, sum);
    } 
};


// Using DP
// Approach 1 : Memoization(or Top-Down Approach)
// TC - O(N*sum), SC - O(N*sum)
class SolutionDP1{
private:
    int countMinDifference(int arr[], int n, int calculatedSum, int sum, std::vector<std::vector<int>> &dp){
        if(n == 0)
            return abs(sum - 2 * calculatedSum);
        
        else if(dp[n][calculatedSum] != -1)
            return dp[n][calculatedSum];
        
        // Returning min becoz below return statement is returning min(S1 - S2)
        else
            return dp[n][calculatedSum] = std::min(countMinDifference(arr, n-1, calculatedSum + arr[n-1], sum, dp),
             countMinDifference(arr, n-1, calculatedSum, sum, dp));
    }

public:
    int minDifference(int arr[], int n){
        // Calc sum using accumulate(first, last, initial_sum_value, (optional) myfunc) comes under #include <numeric> .. [first, last)
        int sum = std::accumulate(arr, arr+n, 0);
        // 2D vector [n+1][sum+1] that initializes to -1   as dp[1001][1001] is failing test case
        std::vector<std::vector<int>> dp(n+1, std::vector<int> (sum + 1, -1));
        
        return countMinDifference(arr, n, 0, sum, dp);
    }
};


//Approach 2 : Tabulation(or Bottom-Up Approach)
// TC - O(N*sum), SC - O(N*sum)
class SolutionDP2{
private:
    int minSubsetDiff(int arr[], int n, int sum){
        // using Subset Sum logic & last row of dp[][] in order to get minSubsetSumDiff
        bool dp[n+1][sum+1];
        // Intialization of Subset sum matrix
        // if sum = 0 store true
        for (int i = 0; i < n+1; i++)
            dp[i][0] = true;

        // if sum != 0 store false
        for (int j = 1; j < sum+1; j++)
            dp[0][j] = false;
        
        for (int i = 1; i < n+1; i++){
            for (int j = 1; j < sum+1; j++){
                if(arr[i-1] <= j)
                    dp[i][j] = dp[i-1][j - arr[i-1] ] || dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }

        std::vector<int> res(sum/2+1);
        // We'll traverse till sum/2 as S1 will be from 0...sum/2
        for (int j = 0; j <= sum/2; j++){
            // We'll take sum(i.e., j) from last row of dp[][] which are True as these are the elements that comprise set S1
            if(dp[n][j])
                res.push_back(j);
        }
        
        // j should be as closest to sum/2 than 2*j will be as close to sum as possible that will make (sum-2*j) as min as possible
        // As elements are being inserted in increasing order so returning last element of vector(containg sum as j)
        return sum - 2 * res[res.size() - 1];
    }

public:
    int minDifference(int arr[], int n){ 
	    int sum = 0;
        for (int i = 0; i < n; i++){
            sum += arr[i];
        }
        
        return minSubsetDiff(arr, n, sum);
	} 
};

int main(){
    int arr[] = {1,6,11,5};
    int n = sizeof(arr)/sizeof(int);
    
    SolutionDP1 obj;
    std::cout << "Min Difference : " << obj.minDifference(arr, n);

    return 0;
}