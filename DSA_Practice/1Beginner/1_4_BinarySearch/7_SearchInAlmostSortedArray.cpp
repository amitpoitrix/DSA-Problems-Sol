#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int modifiedBS(vector<int> &nums, int target){
        int n = nums.size(), start = 0, end = n - 1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(target == nums[mid])
                return mid;
            else if(mid - 1 >= 0 && target == nums[mid - 1])
                return mid - 1;
            else if(mid + 1 < n && target == nums[mid + 1])
                return mid + 1;
            
            else if(mid - 1 >= 0 && target <= nums[mid - 1])
                end = mid - 2;
            else 
                start = mid + 2;
        }

        return -1;
    }
};

int main(){
    vector<int> nums = {10, 3, 40, 20, 50, 80, 70};
    int target = 90;

    Solution obj;
    cout << obj.modifiedBS(nums, target) << "\n";

    return 0;
}