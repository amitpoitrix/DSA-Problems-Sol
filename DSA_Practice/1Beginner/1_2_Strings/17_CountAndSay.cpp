#include <bits/stdc++.h>
using namespace std;

// Lt: 38. Count and Say
// https://leetcode.com/problems/count-and-say/

// TC - O(n * s.length())
// SC - O(s.length())
class Solution {
public:
    string countAndSay(int n) {
        // 1st base case
        if(n == 1) return "1";
        // 2nd base case
        if(n == 2) return "11";
        
        string s = "11";
        // Starting from n = 3 and taking previous (n-1)th string i.e., "11"
        for(int i = 3; i <= n; i++){
            string t = "";  // Computing current iteration string
            s += "$";   // Adding extra char at end to add last computed char
            int cnt = 1;    // every character will have atleast 1 count
            // traversing from j -> 0 to s.length()
            for(int j = 1; j < s.length(); j++){
                // If string doesn't match than add previous same digit count + actual digit
                if(s[j] != s[j-1]){
                    t += to_string(cnt);    // First adding count
                    t += s[j-1];    // Than actual digit value
                    cnt = 1;    // For next iteration
                }
                else
                    cnt++;  // If digit is same than keep on inc its count
            }
            s = t;  // Assign t to s for next iteration
        }
        
        return s;
    }
};

int main(){
    return 0;
}