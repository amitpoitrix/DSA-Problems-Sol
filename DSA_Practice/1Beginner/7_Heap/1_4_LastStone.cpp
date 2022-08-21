#include<iostream>
#include<vector>
#include<queue>
// Heap by Tech Dose : LeetCode 1046. Last Stone Weight
// In this we use Heap DS Application and make use of stl called priority_queue which is under <queue>

// Code 1
class Solution {
public:
    int lastStoneWeight(std::vector<int>& stones) {
        std::priority_queue<int> max_heap;
        int n = stones.size();

        // Pushing the element of vector in heap - TC - O(NlogN)
        // we can also make use of Build Heap which will take O(N) time
        for (int i = 0; i < n; i++){
            max_heap.push(stones[i]);
        }
        
        // Taking two variable in order to store top 2 heavy weight element
        int first, second;
        // We'll run while loop till we left with 0 or 1 element
        while (n > 1){
            first = max_heap.top();
            max_heap.pop();

            second = max_heap.top();
            max_heap.pop();

            n = n - 2;  // Reducing the size of n by 2

            if(first - second > 0){
                max_heap.push(first - second);
                n++;    // Increment size of n by 1
            }
        }

        if(!max_heap.empty())
            return max_heap.top();

        return 0;
    }
};


// Code 2
class Solution2 {
public:
    int lastStoneWeight(std::vector<int>& stones) {
        // std::priority_queue<int> max_heap(std::begin(stones), std::end(stones));
        std::priority_queue<int> max_heap(stones.begin(), stones.end());
        
        while (max_heap.size() > 1){
            int x = max_heap.top();
            max_heap.pop();
            int y = max_heap.top();
            max_heap.pop();

            if(x - y > 0)
                max_heap.push(x-y);
        }

        return max_heap.empty() ? 0 : max_heap.top();
    }
};


int main(){
    std::vector<int> stones = {2,7,4,1,8,1};
    
    Solution2 s;
    std::cout << s.lastStoneWeight(stones);

    return 0;
}