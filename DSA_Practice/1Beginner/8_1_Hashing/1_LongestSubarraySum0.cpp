#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Largest subarray with 0 sum
// https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1/

// TC - O(n)
// SC - O(n)
class Solution{
public:
    int maxLen(vector<int>&A, int n){   
        unordered_map<int, int> mp;
        int len = 0, sum = 0;
        
        for(int i = 0; i < n; i++){
            sum += A[i];
            
            if(sum == 0)
                len = max(len, i + 1);
            else{
                if(mp.find(sum) != mp.end())
                    len = max(len, i - mp[sum]);
                else
                    mp[sum] = i;
            }
        }
        
        return len;
    }
};

int main(){
    return 0;
}