#include<iostream>
#include<vector>
// Recusrion By Striver : L18. K-th Permutation Sequence
// Leetcode : 60. Permutation Sequence

// Brute Force Approach
// We can use Recursion to get all the Permutations and return the (k-1)th element as Ans
// TC - O(n! * n) where n! is the no. of permutation formed and another n is the time require to insert each permutation in DS

// Optimized Approach without Recursion
// TC - O(n^2) becoz O(n) time to pick each element and O(n) to remove each element from Array/String
class Solution {
public:
    std::string getPermutation(int n, int k) {
        // Here we have to return (k-1)th string(or No.) of n! in 0 based indexing
        
        // Step 1: Initially we'll calculate (n-1)! and it will divide K so as to get the index of first element of the Kth String/Array
        int fact = 1;   // As we are calculating factorial so it should be initialise to 1
        std::vector<int> number;    // This will store the Numbers in Each Iteration ({1,2,3,4}, {1,2,4}, {1,4}, {1}) if there are 4 iteration
        for (int i = 1; i < n; i++){
            // Calculating (n-1)!
            fact = fact * i;
            // Meanwhile store digits (1 to n) in number Array
            number.push_back(i);
        }
        // As loop is working for (n-1) times so inserting the last element i.e., n
        number.push_back(n);   

        k = k - 1;  // As for 0 based indexing we'll return (k-1)th element
        std::string res = "";

        while (true){
            // First we'll store the first no. by getting its index from k/fact
            res = res + std::to_string(number[k/fact]);
            // We'll Remove that number[k/fact]
            number.erase(number.begin() + k/fact);

            // After any no. removal from number array we'll check whether its empty or not
            if(number.size() == 0)
                break;
            
            // Calculate next iteration position(i.e., k)
            k = k % fact;
            // Calculate next iteration fact i.e., (n-1-1)!
            fact = fact/number.size();  // here number array is already reduce by 1
        }
        
        return res;
    }
};

int main(){
    Solution obj;
    std::cout << obj.getPermutation(3, 1);

    return 0;
}