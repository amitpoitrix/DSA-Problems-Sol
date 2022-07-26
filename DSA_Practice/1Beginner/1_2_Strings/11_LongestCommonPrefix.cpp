#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // minN for counting the min common no. of char btw them
        int minN = 1e9, n = strs.size();
        // Taking out the first string to compare with other
        string a = strs[0];
        // Comparing with other strings for common prefix
        for(int i = 1; i < n; i++){
            // Taking out the ith string to compare
            string temp = strs[i];
            // incrementing count when found common prefix
            int count = 0, j = 0, k = 0;
            while(j < a.size() && k < temp.size() && a[j] == temp[k])
                count++, j++, k++;
            // storing the min count if found
            minN = min(minN, count);
        }
        // returning substring from 0th string [0, minN-1]
        return a.substr(0, minN);
    }
};

int main(){
    return 0;
}