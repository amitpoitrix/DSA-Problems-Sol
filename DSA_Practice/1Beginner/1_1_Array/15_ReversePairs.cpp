#include <bits/stdc++.h>
using namespace std;

// Lt: 493. Reverse Pairs
// https://leetcode.com/problems/reverse-pairs/

// Approach: Using Merge Sort
// TC - O(nlogn)
// SC - O(n)
class Solution {
private:
    int Merge(vector < int > & nums, int left, int mid, int right) {
        int count = 0, i = left, j = mid;
        // Counting the no. of reverse pairs
        while(i <= mid-1){
            // Kept on increasing j
            while(j <= right && nums[i] > 2 * 1LL * nums[j]) {
                j++;
            }
            count += (j - mid);
            i++;
        }

        // Now Merging two sorted arrays
        vector<int> temp(right - left + 1);
        int k = 0;
        i = left, j = mid;

        while ((i <= mid-1) && (j <= right)) {
            if (nums[i] <= nums[j])
                temp[k++] = nums[i++];
            else
                temp[k++] = nums[j++];
        }

        while (i <= mid-1) {
            temp[k++] = nums[i++];
        }
        while (j <= right) {
            temp[k++] = nums[j++];
        }

        for (int x = left; x <= right; x++) {
            nums[x] = temp[x - left];
        }
        return count;
    }
    
    int mergeSort(vector<int> &nums, int left, int right){
        int mid = 0, count = 0;
        if(left < right){
            mid = left + (right - left) / 2;
            count += mergeSort(nums, left, mid);
            count += mergeSort(nums, mid+1, right);
            count += Merge(nums, left, mid + 1, right);
        }
        return count;
    }
    
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};

int main(){
    return 0;
}