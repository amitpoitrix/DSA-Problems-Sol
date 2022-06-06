#include<iostream>
#include<vector>
using namespace std;
// Recusrion By Striver : L18. K-th Permutation Sequence
// Leetcode : 60. Permutation Sequence

// Brute Force Approach
// We can use Recursion to get all the Permutations and return the (k-1)th element as Ans
// TC - O(n! * n) where n! is the no. of permutation formed and another n is the time require to insert each 
// permutation in DS

// Optimized Approach without Recursion
// TC - O(n^2) becoz O(n) time to pick each element and O(n) to remove each element from Array/String
// SC - O(n); to store ans in n-size string
class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> number;
        for (int i = 1; i < n; i++){
            fact = fact * i;

            number.push_back(i);
        }
        number.push_back(n);   

        string res = "";
        k = k - 1;
        while (true){
            int idx = (k / fact);
            res = res + to_string(number[idx]);
            number.erase(number.begin() + idx);

            if(number.size() == 0)
                break;
            
            k = k % fact;
            fact = fact/number.size();
        }
        
        return res;
    }
};

int main(){
    Solution obj;
    cout << obj.getPermutation(4, 17);

    return 0;
}