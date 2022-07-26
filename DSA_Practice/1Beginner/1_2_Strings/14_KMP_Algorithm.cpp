#include <bits/stdc++.h>
using namespace std;

// KMP Algorithm: String Matching Algo using lps[] i.e., Longest proper prefix & suffix

// TC - O(m + n)
// SC - O(m); m - pat.length()
class Solution{
public:
    vector<int> KMP_Algo(string txt, string pat){
        // Step 1: Computing LPS[] of pattern string
        int lps[pat.length()];
        lps[0] = 0;
        int i = 1, len = 0;
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
        // Step 2: Now applying KMP Algo using lps[pattern]
        i = 0;
        int j = 0;
        vector<int> res;
        while(i < txt.length()){
            if(txt[i] == pat[j]){
                i++;
                j++;
                if(j == pat.length()){
                    res.push_back(i - pat.length());
                    j = lps[j-1];   // for next iteration
                }
            }
            else{ // txt[i] != pat[j]
                if(j != 0) 
                    j = lps[j-1];
                else
                    i++;
            }
        }
        return res;
    }
};

int main(){
    string txt = "abcdabcdabcd";
    string pat = "cdabcdab";

    Solution obj;
    for(auto x: obj.KMP_Algo(txt, pat))
        cout << x << " ";
    
    cout << "\n";

    return 0;
}