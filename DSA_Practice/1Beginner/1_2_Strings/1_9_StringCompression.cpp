#include<iostream>
#include<vector>
using namespace std;

// 443. String Compression
// https://leetcode.com/problems/string-compression/

// Algo:
// 1. Here we've to solve in-place (i.e., without using extra space) so for this we'll take two pointer first to traverse 
// the original string and second to store the valid char in the same original string.
// 2. For count of each repeating characters we'll take another pointer that will help us in counting repeating characters.
// 3. We'll use to_string(count) method to convert int to string & traverse over each digit of count using for each
// loop to store it in original string

// TC - O(n)
// SC - O(1)

class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;  // For traversing the chars
        int ansIdx = 0; // Idx for storing valid char
        int n = chars.size();
        
        while(i < n){
            // starting j from next pos of i
            int j = i+1;
            // incrementing j till found similar elements
            while(j < n && chars[j] == chars[i]){
                j++;
            }
            // storing current ith char & incrementing ansIdx simultaneously
            chars[ansIdx++] = chars[i];
            // Counting repeating char
            int count = j - i;
            // storing repeating char counts if count is greater than 1
            if(count > 1){
                string str = to_string(count);
                for(char &num: str){
                    chars[ansIdx++] = num;
                }
            }
            // checking for next different element
            i = j;
        }
        
        return ansIdx;
    }
};

int main(){
    return 0;
}