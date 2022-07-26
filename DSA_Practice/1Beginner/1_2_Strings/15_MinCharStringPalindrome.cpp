#include <bits/stdc++.h>
using namespace std;

// Minimum Characters required to make a String Palindromic
// https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/

// Approach - Using lps[] of KMP Algorithm for String Matching
// TC - O(n+n)
// SC - O(n + n)
class Solution{
private:
    int LPS(string pat){
        vector<int> lps(pat.length());
        int len = 0, i = 1;
        while(i < pat.length()){
            if(pat[i] == pat[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else{
                if(len != 0)
                    len = lps[len-1];
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
        
        return lps[pat.length() - 1];
    }

public:
    int solve(string A) {
        string B = A;
        reverse(B.begin(), B.end());
        string pat = A + "$" + B;
        
        int len = LPS(pat);
        return A.length() - len;
    }
};

int main(){
    return 0;
}