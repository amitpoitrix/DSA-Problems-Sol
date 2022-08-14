#include<iostream>
#include<vector>
using namespace std;

// Find Missing And Repeating
// https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

// Approach 1: Optimised Approach - Using sum of n numbers
// TC - O(n)
// SC - O(1)
class Solution{
public:
    vector<int> Solution::repeatedNumber(const vector<int> &nums) {
        // s -> sum of n natural no. p -> sum of square of n natural no.
        long long int n = nums.size(), s = 0, p = 0, missingNo = 0, duplicateNo = 0;

        s = (n * (n + 1)) / 2;  // sum of n natural no.
        p = (n * (n + 1) * (2 * n + 1)) / 6;   // sum of sqaure of n natural no.
        
        for(int i = 0; i < n; i++){
            s -= (1LL * nums[i]);   // s` = s - s1
            p -= nums[i] * 1LL * nums[i];    // p` = p - p1
        }
        
        // from derivation
        missingNo = (s + p/s) / 2;  
        duplicateNo = missingNo - s;
        
        vector<int> res;
        res.push_back(duplicateNo);
        res.push_back(missingNo);
        return res;
    }
};

// Approach 2: Using swap sort
// TC - O(n)
// SC - O(1)
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int * res = new int[2];
        int i = 0;
        while(i < n){
            if(arr[i] != arr[arr[i] - 1])
                swap(arr[i], arr[arr[i] - 1]);
            else
                i++;
        }
        
        for(int i = 0; i < n; i++){
            if(arr[i] != i+1){
                res[0] = arr[i];
                res[1] = i+1;
            }
        }
        
        return res;
    }
};

int main(){
    return 0;
}