#include<iostream>
#include<vector>
using namespace std;
// Striver SDE Sheet - Day1-Array-Part1
// Leetcode - 75. Sort Colors

// Approach 1 : Directly Sort them but in ques we don't have to use this approach

// Approach 2 : Take the count of each element(i.e., 0,1,2) as elements are less and then store them accordingly
// TC - O(n) + O(n)
// SC - O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int count0 = 0, count1 = 0, count2 = 0;
        for (int i = 0; i <= n - 1; i++){
            switch (nums[i]){
            case 0:
                count0++;
                break;
            
            case 1:
                count1++;
                break;
            
            case 2:
                count2++;
                break;
            }
        }
        
        nums.clear();
        for (int i = 0; i <= count0 - 1; i++){
            nums.push_back(0);
        }
        
        for (int j = count0; j <= (count0 + count1) - 1; j++){
            nums.push_back(1);
        }

        for (int k = count0 + count1; k <= (count0 + count1 + count2) - 1; k++){
            nums.push_back(2);
        }
    }
};

// Approach 3 : 3 pointer approach - variation of the popular Dutch National flag algorithm

class Solution2 {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0, mid = 0, high = n - 1;

        while(mid <= high){
            if (nums[mid] == 0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            
            else if(nums[mid] == 1)
                mid++;
            
            else if(nums[mid] == 2){
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};


int main(){
    return 0;
}