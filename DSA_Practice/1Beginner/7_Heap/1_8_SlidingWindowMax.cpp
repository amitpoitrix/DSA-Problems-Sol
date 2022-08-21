#include<iostream>
#include<queue>
//Leetcode 239. Sliding Window Maximum
// Total No. of windows of size K = (N - K + 1)

// Approach 1 : Using Max Heap - TC - O(NlogN); SC - O(N)
class Solution{
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        // Step 1 : First we'll create max_heap {nums[i],i}  because we need to maintain the order through idx i
        std::priority_queue<std::pair<int,int>> max_heap;
        std::vector<int> res;

        for (int i = 0; i < nums.size(); i++){
            // Removing the out of bound elements from heap
            while(!max_heap.empty() && max_heap.top().second <= (i - k)){
                max_heap.pop();
            }
            // Pushing the new elements with idx in max_heap
            max_heap.push({nums[i], i});
            // inserting the max element of window of size k
            if(i >= (k - 1))
                res.push_back(max_heap.top().first);
        }

        return res;
    }
};


// Approach 2 : Using Deque - TC - O(N), SC - O(N)
class Solution2{
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::deque<int> dq;     // to store the index
        std::vector<int> res;   // to store greatest array elements of window size k 
        
        for (int i = 0; i < nums.size(); i++){
            // Removing the index from front of deque that are out of bound
            if(!dq.empty() && dq.front() == (i - k))
                dq.pop_front();

            // Removing all the smallest element index from back of the deque
            while(!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            // Inserting the new element index at the back of deque
            dq.push_back(i);

            // Inserting the largest element from front of deque
            if(i >= (k - 1))
                res.push_back(nums[dq.front()]);
        }
        
        return res;
    }
};


int main(){
    std::vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;

    Solution2 s;
    std::vector<int> res = s.maxSlidingWindow(nums, k);

    for (auto x : res){
        std::cout << x << " "; 
    }
    
    return 0;
}