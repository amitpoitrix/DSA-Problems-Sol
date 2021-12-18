#include<iostream>
#include<queue>
#include<vector>
// Heap by Techdose : Sort K Sorted Array
// TC - O(N + (N-K)O(logK)); SC - O(K)

class Solution{
public:
    std::vector<int> sortK(std::vector<int>& A, int k){
        // Create a min-heap of size (k+1) becoz a leftmost element can take max pos from 0 to K+1
        std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap(A.begin(), A.begin() + k + 1);

        std::vector<int> res;
        // Pushing the min element from root into res 
        for (int i = k+1; i < A.size(); i++){
            res.push_back(min_heap.top());
            min_heap.pop();
            // Pushing (N-(k+1)) elements from A starting from i = k+1
            min_heap.push(A[i]);
        }
        
        // Pushing the rest of the elements of min_heap into res
        while (!min_heap.empty()){
            res.push_back(min_heap.top());
            min_heap.pop();
        }
        
        return res;
    }
};

int main(){
    std::vector<int> A = {10, 9, 8, 7, 4, 70, 60, 50};
    int k = 4;

    Solution s;
    std::vector<int> res = s.sortK(A, k);

    for (auto x : res){
        std::cout << x << " ";
    }

    return 0;
}