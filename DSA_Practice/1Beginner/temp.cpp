#include<iostream>
#include<vector>
#include<cstring>

class Solution {
public:
    long long coutPairs(std::vector<int>& nums, int k) {
        int n = nums.size();
        long long count = 0;
        for (int i = 0; i < n - 1; i++){
          for (int j = i+1; j < n; j++){
            if((nums[i] % k == 0) || (nums[j] % k == 0) ){
              count++;
              //std::cout << nums[i] << " " << nums[j] << "\n";
            }
          }
        }

        if(-8){
          std::cout << "\n" << "true" << "\n";
        }

        return count;
    }
};

int main(){
  std::vector<int> nums = {8,10,2,5,9,6,3,8,2};
  int k = 6;
  Solution obj;
  std::cout << obj.coutPairs(nums, k);

  return 0;
}