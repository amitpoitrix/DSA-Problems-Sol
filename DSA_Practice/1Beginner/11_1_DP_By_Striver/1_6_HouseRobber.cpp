#include<iostream>
#include<vector>
using namespace std;
// DP by Striver : DP 6. House Robber 2 | 1D DP | DP on Subsequences
// https://leetcode.com/problems/house-robber-ii/
// Same as Previous Lec 5

class Solution{
private:
    long long int maximumNonAdjacentSum(vector<int> &nums){
        int n = nums.size();
        long long int prev1 = nums[0];
        long long int prev2 = 0;

        for (int i = 1; i < n; i++){
            long long int pick = nums[i];
            if(i > 1)
                pick += prev2;
            long long int notPick = 0 + prev1;

            long long int cur = max(pick, notPick);
            prev2 = prev1;
            prev1 = cur;
        }
        
        return prev1;
    }

public:
    long long int houseRobber(vector<int>& valueInHouse){
        int n = valueInHouse.size();
        // Edge Case : if Array as only 1 element
        if(n == 1)
            return valueInHouse[0];

        vector<int> temp1, temp2;

        for (int i = 0; i < n; i++){
            // Ignoring the First House and inserting all the value from 1...n-1
            if(i != 0)
                temp1.push_back(valueInHouse[i]);
            
            // Ignoring the last house and inserting all the value from 0...n-2
            if(i != n-1)
                temp2.push_back(valueInHouse[i]);
        }
        
        return max(maximumNonAdjacentSum(temp1), maximumNonAdjacentSum(temp2));
    }
};

int main(){
    vector<int> valueInHouse = {1,3,2,1};

    Solution obj;
    cout << obj.houseRobber(valueInHouse);

    return 0;
}