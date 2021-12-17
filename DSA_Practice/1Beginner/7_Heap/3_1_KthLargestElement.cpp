#include<iostream>
#include<vector>
#include<queue>
// Kth Largest element

// Approach 1 : SC - 
// using Min/Max Heap
// Max Heap - pop() operation will run (K-1) times  TC - O(klogN)   SC - O(N)
// Min Heap - pop() operation will run (N-k) times  TC - O((N-K)logK)   SC - O(K)
class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        int n = nums.size();
        if((k - 1) < (n - k)){
            // Here we'll use Max Heap Approach
            std::priority_queue<int> max_heap(nums.begin(), nums.end());
            for (int i = 0; i < k - 1; i++){
                max_heap.pop();
            }
            return max_heap.top();
        }

        //Otherwise Here we'll use Min Heap Approach
        std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
        for (int num : nums) {
            min_heap.push(num);
            if (min_heap.size() > k) {
                min_heap.pop();
            }
        }
        return min_heap.top();
    }
};

// Approach 2 : Using Quick Select Algo. TC - O(N) / O(N^2) in case of worst complexity
class Solution2{
private:
    int partition(std::vector<int>& nums, int left, int right){
        int i = left - 1;
        int pivot = nums[right];

        for (int j = left; j < right; j++){
            // for kth Largest num[j] > pivot & for kth smallest num[j] < pivot
            if(nums[j] > pivot){
                i++;
                std::swap(nums[i], nums[j]);
            }
        }

        std::swap(nums[i + 1], nums[right]);
        return i + 1;
    }
public:
    int findKthLargest(std::vector<int>& nums, int k){
        int kth = 0;
        int left = 0;
        int right = nums.size() - 1;
        while (true){
            int idx = partition(nums, left, right);
            // Comparing with k-1 becoz its a 0 based indexing so Kth largest lie in (k-1)th position
            if(idx == k - 1){
                kth = idx;
                break;
            }
            else if(k - 1 > idx)
                left = idx + 1;
            else
                right = idx - 1;
        }
        return nums[kth];
    }
};

int main(){
    std::vector<int> nums = {3,2,3,1,2,4,5,5,6};
    int k = 4;

    Solution2 s;
    std::cout << s.findKthLargest(nums, k);

    return 0;
}