#include <bits/stdc++.h>
using namespace std;

// Lt: 165. Compare Version Numbers
// https://leetcode.com/problems/compare-version-numbers/

// TC - O(n + m)
// SC - O(1)
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0, num1, num2;
        while(i < version1.length() || j < version2.length()){
            // For each iteration(or next Revision) initialize the number for both the string to be 0
            num1 = 0;
            num2 = 0;
            
            // Traversing on version1 till it encounters '.' or it get exhaust
            while(i < version1.length() && version1[i] != '.'){
                num1 = num1 * 10 + (version1[i] - '0');
                i++;
            }
            // Traversing on version2 till it encounters '.' or it get exhaust
            while(j < version2.length() && version2[j] != '.'){
                num2 = num2 * 10 + (version2[j] - '0');
                j++;
            }
            
            if(num1 < num2)
                return -1;
            else if(num1 > num2)
                return 1;
            
            // If both num1 & num2 are equal than increment both pointer for next iteration
            i++;
            j++;
        }
        
        return 0;
    }
};

int main(){
    return 0;
}