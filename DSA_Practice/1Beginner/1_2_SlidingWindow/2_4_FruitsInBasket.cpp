#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Lt: 904. Fruit Into Baskets
// https://leetcode.com/problems/fruit-into-baskets/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int len = 0, i = 0, j = 0;
        unordered_map<int, int> mp;
        
        while(j < fruits.size()){
            mp[fruits[j]]++;
            
            if(mp.size() > 2){
                while(mp.size() > 2){
                    mp[fruits[i]]--;
                    if(mp[fruits[i]] == 0)
                        mp.erase(fruits[i]);
                    i++;
                }
            }
            len = max(len, j - i + 1);
            j++;
        }
        
        return len;
    }
};

int main(){
    return 0;
}