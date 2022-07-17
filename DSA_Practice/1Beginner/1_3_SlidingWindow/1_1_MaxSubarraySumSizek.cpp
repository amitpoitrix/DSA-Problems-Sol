#include<iostream>
#include<vector>
using namespace std;

// Max Sum Subarray of size K
// https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1

// Brute Force - TLE
// TC - O(n-k)
// SC - O(1)
class Solution{
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        int maxx = 0;
        for(int i = 0; i <= N-K; i++){
            int sum = 0;
            for(int j = i; j < i + K; j++)
                sum += Arr[j];    
            maxx = max(maxx, sum);
        }
        
        return maxx;
    }
};

// Optimize Approach - Using Sliding Window
// Method 1
class Solution2{
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        long ans = -1e9, maxSum = 0;
        int i = 0, j = 0;

        while(j < N){
            // Calculation
            maxSum += Arr[j];

            // Window size(K) is not achieved
            if((j - i + 1) < K)
                j++;

            // Window size(K) is achieved
            else if((j - i + 1) == K){
                // ans
                ans = max(ans, maxSum);
                // Before sliding - Here i is not yet increase
                maxSum -= Arr[i];
                // Slide the window
                i++;
                j++;
            }
        }

        return ans;
    }
};

// Method 2
class Solution2{
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        // N should always be greater than K
        if(N < K)
            return -1;

        // Calculating sum till window(k) size
        long sum = 0;
        for(int i = 0; i < K; i++){
            sum += Arr[i];
        }

        long maxx = sum;
        // Computing rest of the window size subarrays sum
        for(int i = K; i < Arr.size(); i++){
            // Here i-k because i is already increase
            sum += Arr[i] - Arr[i - K];
            maxx = max(maxx, sum);
        }

        return maxx;
    }
};

int main(){
    return 0;
}