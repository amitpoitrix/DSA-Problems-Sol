#include <bits/stdc++.h>
using namespace std;

// Lt: 287. Find the Duplicate Number
// https://leetcode.com/problems/find-the-duplicate-number/

// Using Linked List Cycle Method + Tortoise Method
// TC - O(n)
// SC - O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // taking 2 pointers
        int slow = nums[0];
        int fast = nums[0];
        
        // As slow and fast are equal initially so using do while
        // so that they will atleast run for 1 iteration
        do{
            slow = nums[slow];  // Moves by 1 step
            fast = nums[nums[fast]];    // moves by 2 steps
        } while(fast != slow);
        
        fast = nums[0]; // Pointing fast to initial element

        while(fast != slow){
            // here both slow & fast moves by 1 step
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return fast;    // or slow
    }
};

int main(){
    return 0;
}