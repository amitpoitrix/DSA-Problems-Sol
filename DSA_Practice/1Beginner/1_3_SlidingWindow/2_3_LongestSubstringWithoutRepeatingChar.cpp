#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

// Lt: 3. Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //if string of length zero comes simply return 0
        if(s.length()==0)
            return 0;   

        //create map to store frequency,get to know all unique characters
        unordered_map<char,int> mp;
        int len = - 1e9; 
        int i = 0,j = 0;

        while(j < s.length()){
            mp[s[j]]++;

            // whem map size is equal to the window size means suppose window size is 3 and 
            // map size is also three that means in map all unique characters are their
            if(mp.size() == (j-i+1)){
                len = max(len, j-i+1);
                j++;
            }
            
            // if the map size is less than the window size means there is some duplicate present 
            // like window size = 3 and map size = 2 means there is a duplicates
            else if(mp.size() < (j-i+1)){
                //so till the duplicates are removed completely
                while(mp.size() < (j-i+1))  {
                    mp[s[i]]--;
                    if(mp[s[i]]==0)
                        mp.erase(s[i]); //remove it completely
                    i++;
                }
                j++;
            }
        }
        return len;
    }
};

// Another Approach using Sliding window + set
class Solution {
private:
    int max(int a, int b){
        if(a > b) return a;
        return b;
    }
    
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0,ans=0;
        unordered_set <int> st;

        while (j < s.size()){
            if (st.find(s[j]) != st.end()){
                while (st.find(s[j]) != st.end()){
                    st.erase(s[i]);
                    i++;
                }
            }
            st.insert(s[j]);
            j++;
            ans = max(ans,st.size());
        }
        return ans;
    }
};

int main(){
    return 0;
}