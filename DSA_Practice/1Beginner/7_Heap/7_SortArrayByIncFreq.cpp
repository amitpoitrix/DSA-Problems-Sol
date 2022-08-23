#include<bits/stdc++.h>
using namespace std;

// Lt: 1636. Sort Array by Increasing Frequency
// https://leetcode.com/problems/sort-array-by-increasing-frequency/

// Using Heap - Min Heap
// TC - O(nlogk + n)
// SC - O(n)
class Solution {
private:
    class Comp{
    public:    
        bool operator()(pair<int, int> &p1, pair<int, int> &p2){
            // As we're using Min Heap we've to right condition in reverse order
            if(p1.first == p2.first){
                return p1.second < p2.second;
            }
        
            return p1.first > p2.first;
        }
    };
    
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        
        // Computing the key: Frequency
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }
        
        // Using Min Heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> minH;
        for(auto x: mp){
            minH.push({x.second, x.first});
        }
        
        vector<int> res;
        while(!minH.empty()){
            int freq = minH.top().first;
            
            while(freq--){
                res.push_back(minH.top().second);
            }
            
            minH.pop();
        }
        
        return res;
    }
};

// Using Heap - Max Heap
// TC - O(nlogk + n)
// SC - O(n)
class Solution {    
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        
        // Computing the key: Frequency
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }
        
        // Using Max Heap
        priority_queue<pair<int, int>> maxH;
        for(auto x: mp){
            maxH.push({-1 * x.second, x.first});
        }
        
        vector<int> res;
        while(!maxH.empty()){
            int freq = abs(maxH.top().first);
            
            while(freq--){
                res.push_back(maxH.top().second);
            }
            
            maxH.pop();
        }
        
        return res;
    }
};

// Using Just comparator + HashMap
// TC - O(nlogn)
// SC - O(n)
class Solution {
private:  
    static bool Comp(pair<int, int> &p1, pair<int, int> &p2){
        // If frequency is same
        if(p1.first == p2.first){
            // Than greater value comes first
            return p1.second > p2.second;
        }
        
        // else sort in terms of freq
        return p1.first < p2.first;
    }
    
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        
        // Computing the key: Frequency -> {element, freq}
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }
        
        vector<pair<int, int>> v;
        for(auto x: mp){
            // {freq, element}
            v.push_back({x.second, x.first});
        }
        
        // Sort the v[{}] acc. to the ques
        sort(v.begin(), v.end(), Comp);
        
        vector<int> res;
        for(int i = 0; i < v.size(); i++){   
            // Insert element till its freq 
            while(v[i].first--){
                res.push_back(v[i].second);
            }
        }
        
        return res;
    }
};

int main(){
    return 0;
}