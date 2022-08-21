#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>

// Top K Frequent Elements
// Approach 1 : Using Min Heap - TC - O(KlogN) , SC - O(N)
class solution{
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k){
        // Creating Hash Map of {element, freq}
        std::unordered_map<int,int> map;
        for (auto num : nums){
            map[num]++;
        }
        
        // Creating Min Heap
        std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> min_heap;
        // we'll push elements in heap in {freq, element}
        for (auto kv : map){
            min_heap.push({kv.second, kv.first});
            if(min_heap.size() > k)
                min_heap.pop();
        }

        std::vector<int> res;

        while (!min_heap.empty()){
            res.push_back(min_heap.top().second);
            min_heap.pop();
        }
        
        return res;
    }
};

// Approach 2 : Using Bucket sort. TC - O(N), SC - O(N)
class solution2{
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k){
        // Creating Hash Map - {element, freq}
        std::unordered_map<int,int> map;
        for (auto num : nums){
            map[num]++;
        }

        // Creating bucket of size (nums.size() + 1) - +1 for 0th index
        std::vector<std::vector<int>> bucket(nums.size() + 1);
        // bucket[freq] ->[element1, element2,....]
        for (auto kv : map){
            bucket[kv.second].push_back(kv.first);
        }
        
        std::vector<int> res;

        for (int i = bucket.size() - 1; i >= 0 && res.size() < k; i--){
            for (auto x : bucket[i]){
                res.push_back(x);
                if(res.size() == k)
                    break;
            }
        }
        
        return res;
    }
};


int main(){
    std::vector<int> nums = {1,1,1,2,2,3};
    int k = 2;

    solution2 s;
    std::vector<int> res = s.topKFrequent(nums, k);

    for (auto x : res){
        std::cout << x << " ";
    }
    
    return 0;
}