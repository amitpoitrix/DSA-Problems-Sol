#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<vector>
// Leetcode 1. Two Sum
// Pair Sum Problem - Find Pair of elements who's sum is equal to K

// Using Hashing - unsorted_set & it'll take TC- O(N)
// Function for returning pair of elements that sums to k
std::vector<std::pair<int, int>> pairSum(std::vector<int> arr, int sum){
    std::unordered_set<int> s;
    std::vector<std::pair<int, int>> result;

    // We First traverse and check for x in empty set and then insert arr[i] at the end in order to avoid repetition
    for (int i = 0; i < arr.size(); i++){
        int x = sum - arr[i];
        // s.find() -> use for searching in set
        if(s.find(x) != s.end())
            result.push_back({x, arr[i]});

        // Inserting current element into set
        s.insert(arr[i]);
    }
    
    return result;
}


// Function for returning pair of index of elements whose sum equals to k - Exactly one solution
std::vector<int> twoSum(std::vector<int> arr, int sum){
    // Here we'll take unordered_map<int, int>
    std::unordered_map<int, int> map;
    for (int i = 0; i < arr.size(); i++){
        int x = sum - arr[i];
        // map.count() -> use for search in map
        if(map.count(x))
            return {map[x], i};

        map[arr[i]] = i;
    }

    return {};
}


int main(){
    std::vector<int> arr = {2,-6,4,5,18,10,2,7,3};
    int k = 4;

    // std::vector<std::pair<int, int>> res = pairSum(arr, k);

    // for (auto x : res){
    //     std::cout << "{" << x.first << " , " << x.second << "}" << "\n";
    // }

    std::vector<int> res1 = twoSum(arr, k);
    for (auto x : res1){
        std::cout << x << " ";
    }
    
    return 0;
}