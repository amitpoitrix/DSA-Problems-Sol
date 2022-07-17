#include<bits/stdc++.h>
using namespace std;

// Lt:239. Sliding Window Maximum
// https://leetcode.com/problems/sliding-window-maximum/

// Using Sliding Window
// Method 1
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        // Edge Case
        if(k > nums.size()){
            ans.push_back(*max_element(nums.begin(), nums.end()));
        }

        deque<int> dq;
        int i = 0, j = 0;

        while(j < nums.size()){
            // calculations
            if(dq.empty())
                dq.push_back(nums[j]);
            else{
                while(!dq.empty() && dq.back() < nums[j])
                    dq.pop_back();
                dq.push_back(nums[j]);
            }

            // if window size(k) is not achieved
            if((j - i + 1) < k)
                j++;
            
            else if((j - i + 1) == k){
                // ans
                ans.push_back(dq.front());

                // Before sliding
                if(nums[i] == dq.front())
                    dq.pop_front();
                
                // Slide the window
                i++;
                j++;
            }
        }

        return ans;
    }
};

// Method 2
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        // Edge Case
        if(k > nums.size()){
            ans.push_back(*max_element(nums.begin(), nums.end()));
        }

        deque<int> dq;
        for(int i = 0; i < k; i++){
            while(!dq.empty() && dq.back() < nums[i]){
                dq.pop_back();
            }
            dq.push_back(nums[i]);
        }
        ans.push_back(dq.front());

        for(int i = k; i < nums.size(); i++){
            if(nums[i - k] == dq.front())
                dq.pop_front();
            
            while (!dq.empty() && dq.back() < nums[i]){
                dq.pop_back();
            }
            dq.push_back(nums[i]);
            ans.push_back(dq.front());
        }

        return ans;
    }
};

int main(){
    return 0;
}