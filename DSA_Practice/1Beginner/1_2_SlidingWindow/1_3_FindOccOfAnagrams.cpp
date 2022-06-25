#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Count Occurences of Anagrams 
// https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1

// Using Sliding Window
// Method 1
class Solution{
public:
	int search(string pat, string txt) {
	    unordered_map<char, int> mp;
        for(auto &x: pat){
            mp[x]++;
        }

        int count = mp.size();
        int k = pat.size();
        int i = 0, j = 0, ans = 0;

        while(j < txt.size()){
            // Calculations
            if(mp.find(txt[j]) != mp.end()){
                mp[txt[j]]--;
                if(mp[txt[j]] == 0)
                    count--;
            }

            // if window size(k) is not achieved
            if((j - i + 1) < k)
                j++;
            
            // If window size(k) is achieved, find ans and slide the window
            else if((j - i + 1) == k){
                // ans is achieved
                if(count == 0)
                    ans++;
                // Before sliding the window
                if(mp.find(txt[i]) != mp.end()){
                    mp[txt[i]]++;
                    if(mp[txt[i]] == 1)
                        count++;
                }
                // Slide the window
                i++;
                j++;
            }
        }

        return ans;
	}
};

// Method 2
class Solution{
public:
	int search(string pat, string txt) {
        // Using char freq array
        vector<int> patFreq(26, 0), txtFreq(26, 0);
        // Window size k
        int k = pat.size();

        for(int i = 0; i < k; i++){
            patFreq[pat[i] - 'a']++;
            txtFreq[txt[i] - 'a']++;
        }

        int ans = 0;
        // Checking if patFreq & txtFreq are same
        if(patFreq == txtFreq)
            ans++;
        
        for(int i = k; i < txt.size(); i++){
            // Adding freq for new i & removing freq for last i in txtFreq
            txtFreq[txt[i] - 'a']++;
            txtFreq[txt[i - k] - 'a']--;

            if(patFreq == txtFreq)
                ans++;
        }

        return ans;
    }
};

int main(){
    return 0;
}