#include<iostream>
#include<vector>
#include<limits.h>
// AdityaVerma DP Series : 4. Minimum Sum Partition (or Min Subset Sum difference)
// Return min diff of two subset sum of a array
// Variation of Subset Sum Problem which itself is variation of 0/1 Knapsack Problem
// TC/SC - O(sum*N)

// Using DP - Tabulation(or Bottom-Up Approach)
class Solution{
private:
    int minSubsetDiff(int arr[], int n, int sum){
        // using Subset Sum logic & last row of dp[][] in order to get minSubsetSumDiff
        bool dp[n+1][sum+1];
        // Intialization of Subset sum matrix
        for (int i = 0; i < n+1; i++){
            // Having all elements and we have to achieve sum = 0 that is possible i.e., empty set {}
            dp[i][0] = true;
        }
        // As dp[0][0] should be 1 so starting traversing column from j=1
        for (int j = 1; j < sum+1; j++){
            // Having 0 elements can we achieve sum > 0 ; No
            dp[0][j] = false;
        }
        
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
            // We'll insert last row of dp[][] which are True as these are the elements that will be in set S1
            if(dp[n][j])
                res.push_back(j);
        }
        
        // int mn = INT_MAX;
        // for (int i = 0; i < res.size(); i++){
        //     mn = std::min(mn, sum - 2*res[i]);
        // }

        // return mn;

        // Treaking min(S2-S1) as min(Sum - 2 * S1) where S1 is as large as possible in order to minimize the difference
        // taking S1 as last element of vector as it is in sorted order so S1 will be as large as possible
        return sum - 2 * res[res.size() - 1];
    }

public:
    int minDifference(int arr[], int n)  { 
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
    
    Solution obj;
    std::cout << obj.minDifference(arr, n);

    return 0;
}