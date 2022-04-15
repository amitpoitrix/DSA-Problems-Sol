#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int, int> mp;
        for(int i=0; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        
        for(auto x : mp){
            cout << x.first << " -> " << x.second << "\n";
            if(x.second > 1)
                return x.first;
        }
        
        return 0;
    }
};

int main(){
  vector<int> nums = {1,3,4,2,2};

  Solution obj;
  cout << obj.findDuplicate(nums);

  return 0;
}