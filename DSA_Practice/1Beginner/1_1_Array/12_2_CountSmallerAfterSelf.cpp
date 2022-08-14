#include <bits/stdc++.h>
using namespace std;

// Lt: 315. Count of Smaller Numbers After Self
// https://leetcode.com/problems/count-of-smaller-numbers-after-self/

// Using Merge Sort in Descending Order
// TC - O(nlogn)
// SC - O(n)
class Solution {
private:
    void merge(vector<pair<int, int>> &v, vector<int> &count, int left, int mid, int right){
        int i = left, j = mid, k = 0;
        vector<pair<int, int>> temp(right - left + 1);
        
        while((i <= mid-1) && (j <= right)){
            // nums[i] <= nums[j]
            if(v[i].first <= v[j].first)
                temp[k++] = v[j++]; // {nums[j], j} is assign to temp
            
            else{    // nums[i] > nums[j]
                count[v[i].second] += (right - j + 1);  // First insert count
                temp[k++] = v[i++]; // then assign values
            }
        }
        
        while(i <= mid-1){
            temp[k++] = v[i++];
        }
        
        while(j <= right){
            temp[k++] = v[j++];
        }
        
        // Assigning sorted element in desc back to v[] from temp[]
        for(int x = left; x <= right; x++){
            v[x] = temp[x - left];
        }
    }
    
    void mergeSort(vector<pair<int, int>> &v, vector<int> &count, int left, int right){
        int mid = 0;
        if(left < right){
            mid = left + (right - left) / 2;
            
            mergeSort(v, count, left, mid);
            mergeSort(v, count, mid + 1, right);
            
            merge(v, count, left, mid + 1, right);
        }
    }
    
public:
    vector<int> countSmaller(vector<int>& nums) {
        // pair<nums[i], i>
        vector<pair<int, int>> v;
        for(int i = 0; i < nums.size(); i++){
            v.push_back({nums[i], i});
        }
        
        vector<int> count(nums.size(), 0);
        mergeSort(v, count, 0, nums.size()-1);
        
        return count;
    }
};

int main(){
    return 0;
}