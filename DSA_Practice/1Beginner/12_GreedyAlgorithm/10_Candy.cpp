#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

// Lt: 135. Candy
// https://leetcode.com/problems/candy/

// Approach 1
// TC - O(n)
// SC - O(n)
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candy(n, 1);
        // From left to right [1 -> n-1]
        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i-1] && candy[i] <= candy[i-1])
                candy[i] = candy[i-1] + 1;
        }
        // From right to left [n-2 -> 0]
        for(int i = n-2; i >= 0; i--){
            if(ratings[i] > ratings[i+1] && candy[i] <= candy[i+1])
                candy[i] = candy[i+1] + 1;
        }
        
        return accumulate(candy.begin(), candy.end(), 0);
    }
};

// Approach 2
// TC - O(n)
// SC - O(1)
class Solution1 {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int i = 1, minCandy = n;
        while(i < n){
            if(ratings[i] == ratings[i-1]){
                i++;
                continue;
            }
            
            int peak = 0;
            while(i < n && ratings[i] > ratings[i-1]){
                peak++;
                minCandy += peak;
                i++;
                if(i == n)
                    return minCandy;
            }
            
            int valley = 0;
            while(i < n && ratings[i] < ratings[i-1]){
                valley++;
                minCandy += valley;
                i++;
            }
            
            minCandy -= min(peak, valley);
        }
        
        return minCandy;
    }
};

int main(){
    return 0;
}