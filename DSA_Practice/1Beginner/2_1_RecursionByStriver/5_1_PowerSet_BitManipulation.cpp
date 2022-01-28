#include<iostream>
#include<vector>
#include<algorithm>
// By striver - Power Set | Print all Subsequences or Subsets
// Power Set P(S) of a set S is the set of all subsets of S. 
// For example S = {a, b, c} then P(S) = {{}, {a}, {b}, {c}, {a,b},{a, c}, {b, c}, {a, b, c}}.
// If S has n elements in it then P(S) will have 2^n elements

// TC - O(2^n)
// SC - O(n * 2^n); where n is the length of the string
class Solution{
public:
	std::vector<std::string> AllPossibleStrings(std::string s){
	    int n = s.size();
        int len = (1 << n) - 1;
        std::vector<std::string> res;

        // traversing from 0 to (2^n - 1) where 2^n is also written as (1 << n)
        for (int i = 0; i <= len; i++){
            std::string ans = "";
            // Traversing from 0 to n-1 i.e., n -> length of string
            for (int j = 0; j < n; j++){
                if(i & (1 << j))
                    ans += s[j];
            }
            // Ignoring the element having 0 size
            if(ans.size() > 0)
                res.push_back(ans);
        }

        // Sorting as we have to return ans in lexicographical-sorted order
        std::sort(res.begin(), res.end());
        return res;
	}
};

int main(){
    std::string str = "abc";

    Solution obj;
    for (auto x : obj.AllPossibleStrings(str)){
        std::cout << x << " ";
    }
    
    return 0;
}