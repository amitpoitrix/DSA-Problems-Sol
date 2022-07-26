#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool kmpAlgo(string txt, string pat){
        vector<int> lps(pat.length());
        for(int i = 1; i < pat.length(); i++){
            int j = lps[i-1];
            while(j > 0 && pat[i] != pat[j]){
                j = lps[j-1];
            }
            if(pat[i] == pat[j])
                lps[i] = j + 1;
            else if(j == 0)
                lps[i] = j;
        }
        
        int i = 0, j = 0;
        while(i < txt.length()){
            if(txt[i] == pat[j]){
                i++, j++;
            }
            
            if(j == pat.length())
                return true;
            
            else if(txt[i] != pat[j]){
                if(j == 0) i++;
                else j = lps[j-1];
            }
        }
        
        return false;
    }
    
public:
    int repeatedStringMatch(string a, string b) {
        int count = 1;
        
        string tmp = a;
        cout << tmp << "\n";
        while(a.length() <= b.length()){
            a += tmp;
            count++;
        }

        // cout << "a :" << a << "\n";
        // cout << "b :" << b << "\n";

        // if(kmpAlgo(a, b) == true)
        //     return count;
        
        a += tmp;
        cout << "tmp :" << tmp << "\n";
        cout << "a :" << a << "\n";
        cout << "b :" << b << "\n";

        if(kmpAlgo(a, b) == true)
            return count;
        
        return -1;
    }
};


int main(){
    string txt = "abcd";
    string pat = "cdabcdab";

    Solution obj;
    cout << obj.repeatedStringMatch(txt, pat) << "\n";
    
    cout << "\n";

    return 0;
}
