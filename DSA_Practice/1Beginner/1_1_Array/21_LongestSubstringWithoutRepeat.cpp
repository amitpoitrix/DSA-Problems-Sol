#include<bits/stdc++.h>
using namespace std;

// 3. Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

// BruteForce Approach: Using Kadane's Algorithm - using nested loops + set
// TC - O(n^2)
// SC - O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Base Case
        int n = s.size(), len = 0;
        if(n == 0)
            return 0;
        else if(n == 1)
            return 1;
        
        // Using kadane's algorithm i.e., by generating all subarrays using nested loops
        for(int i = 0; i < n; i++){
            unordered_set<char> st; // set for each i
            for(int j = i; j < n; j++){
                // if element is present in set than compute length till last jth & than break out
                if(st.find(s[j]) != st.end()){
                    len = max(len, j - i);
                    break;
                }

                st.insert(s[j]);    // else kept on inserting current jth element
                
                if(j == n-1)    // if given string doesn't have any repeating element
                    len = max(len, j - i + 1);
            }
        }
        
        return len;
    }
};

// Optimised Approach: Using Set + two pointers
// TC - O(2n)
// SC - O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {        
        unordered_set<char> st;
        int n = s.size(), len = 0, left = 0;
        
        for(int right = 0; right < n; right++){
            // first check if rth element already exist in set if yes than remove it from set
            if(st.find(s[right]) != st.end()){
                // Moving left till duplicate element removes from set
                while(left < right && st.find(s[right]) != st.end()){
                    st.erase(s[left]);  // first remove
                    left++; // than increment left
                }
            }
            
            len = max(len, right - left + 1);   // computing length
            
            st.insert(s[right]);    // inserting current element to set
        }
        
        return len;
    }
};

// Most Optimised Approach: Using vector as map of size 256
// TC - O(n)
// SC - O(1)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Using vector as map of size 256 i.e., total no. of ASCII Characters
        vector<int> mp(256, -1);
        int n = s.size(), len = 0, left = 0;
        
        for(int right = 0; right < n; right++){
            // If rth char already present in mp[]
            if(mp[s[right]] != -1){
                // Moving left if rth char is present previously & its within [l-r] range
                left = max(mp[s[right]] + 1, left);  
            }
            
            len = max(len, right - left + 1);   // Computing len at each iteration to get max len
            
            mp[s[right]] = right; // Assigning current rth char idx in mp[]
        }
        
        return len;
    }
};

int main(){
    return 0;
}