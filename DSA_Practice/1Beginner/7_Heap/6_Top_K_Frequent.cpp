#include <bits/stdc++.h>
using namespace std;

// GFG: Top K Frequent Elements in Array
// https://practice.geeksforgeeks.org/problems/top-k-frequent-elements-in-array/1

// Using Heap
// TC - O()
class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
        int n = nums.size();
        // Using Map for computing frequency
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }
        
        // For Top K Elements - Using Min Heap {freq, element}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minH;

        for(auto x: mp){
            minH.push({x.second, x.first});
            
            if(minH.size() > k){
                auto p = minH.top();
                minH.pop();
                if(p.first == minH.top().first && p.second > minH.top().second){
                    minH.pop();
                    minH.push(p);
                }
            }
        }
        
        vector<int> res;
        while(!minH.empty()){
            res.push_back(minH.top().second);
            minH.pop();
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}