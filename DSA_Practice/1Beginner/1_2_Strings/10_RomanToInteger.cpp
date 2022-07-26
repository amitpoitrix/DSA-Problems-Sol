#include<bits/stdc++.h>
using namespace std;

// Approach 1: Using Hashmap
// TC - O(n)
// SC - O(7) ~ O(1)
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp = 
        {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        
        int n = s.size(), sum = 0;
        for(int i = 0; i < n-1; i++){
            int curr = mp[s[i]], next = mp[s[i+1]];
            if(curr < next)
                sum -= curr;
            else
                sum += curr;
        }
        sum += mp[s.back()];
        
        return sum;
    }
};

// Approach 2: Using switch statement
// TC - O(n)
// SC - O(1)
class Solution {
private:
    int roman(char ch){
        switch(ch){
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return 0;
        }
    }
    
public:
    int romanToInt(string s) {
        int n = s.size(), sum = 0;
        for(int i = 0; i < n-1; i++){
            int curr = roman(s[i]), next = roman(s[i+1]);
            if(curr < next)
                sum -= curr;
            else
                sum += curr;
        }
        sum += roman(s.back());
        
        return sum;
    }
};

int main(){
    return 0;
}