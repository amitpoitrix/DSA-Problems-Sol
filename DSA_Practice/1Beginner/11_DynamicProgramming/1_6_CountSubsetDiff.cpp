#include<iostream>
// AdityaVerma DP Series : 5. Count No. of Subset with given difference(same as "Target Sum" - Leetcode Problem)
// Return count of subset whose difference is equal to given diff
// Variation of countSubsetSum Problem which itself is variation of SubsetSum Problem
// TC/SC - O(sum*N)

// Using DP - Tabulation(or Bottom-Up Approach)
class Solution{
private:
    int countSubsetSum(int arr[], int n, int sum){
        int dp[n+1][sum+1];

        dp[0][0] = 1;
        for (int j = 1; j < sum+1; j++){
            dp[0][j] = 0;
        }
        
        for (int i = 1; i < n+1; i++){
            // startinh j from 0 instead of 1 as we need to take care of 0 as element in array
            for (int j = 0; j < sum+1; j++){
                if(arr[i-1] <= j)
                    dp[i][j] = dp[i-1][j - arr[i-1] ] + dp[i-1][j];
                
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[n][sum];
    }

public:
    int countSubsetDiff(int arr[], int n, int diff){
        int sum = 0;
        for (int i = 0; i < n; i++){
            sum += arr[i];
        }
        
        // 1. s1 + s2 = sum
        // 2. s1 - s2 = diff
        // eq1 - eq2 => 2*s2 = sum - diff 
        int s2 = (sum - diff)/2;    // here s2 has to store int value as fractional can't be possible with given int array elements

        // 1st condn : actual elements sum is less than diff than there is no way we can reach the diff
        // 2nd condn : if the (sum - diff) or (sum + diff) is not even than divide by 2 will be fraction & there is no way we can reach
        // fractional solution with int elements
        if(sum < diff || (sum - diff)%2 != 0)
            return 0;

        return countSubsetSum(arr, n, s2);
    }
};

int main(){
    int arr[] = {1};
    int n = sizeof(arr)/sizeof(int);
    int diff = 2;
    
    Solution obj;
    std::cout << obj.countSubsetDiff(arr, n, diff);

    return 0;
}