#include <bits/stdc++.h>
using namespace std;

// Z-Function - This algorithm finds all occurrences of a pattern in a text in linear time. Let length of 
// text be n and of pattern be m, then total time taken is O(m + n) with linear space complexity

class Solution{
    vector<long long> z_algo(string tot){
        long long l = 0, r = 0;
        vector<long long> z(tot.length());
        for(long long i = 1; i < tot.length(); i++){
            if(i > r){
                l = r = i;
                while(r < tot.length() && tot[r] == tot[r-l]){
                    r++;
                }
                z[i] = r - l;
                r--;
            }
            else{
                long long idx = i - l;
                if(i + z[idx] <= r)
                    z[i] = z[idx];
                else{
                    l = i;
                    while(r < tot.length() && tot[r] == tot[r-l]){
                        r++;
                    }
                    z[i] = r - l;
                    r--;
                }
            }
        }

        return z;
    }
    
public:
    vector<long long> z_function(string txt, string pat){
        vector<long long> res;
        string tot = pat + '$' + txt;
        vector<long long> z = z_algo(tot);
        for(int i = 0; i < z.size(); i++){
            if(z[i] == pat.length())
                res.push_back(i - pat.length() -1);
        }

        return res;
    }
};

int main(){
    string txt = "abdhvfgjfabd";
    string pat = "abd";

    Solution obj;
    for(auto x: obj.z_function(txt, pat))
        cout << x << " ";
    
    cout << "\n";
    return 0;
}