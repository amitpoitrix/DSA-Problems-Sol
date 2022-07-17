#include<iostream>
#include<vector>
using namespace std;

// Lt: 744. Find Smallest Letter Greater Than Target
// https://leetcode.com/problems/find-smallest-letter-greater-than-target/

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char res = letters[0];
        int n = letters.size(), start = 0, end = n - 1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(letters[mid] == target) start = mid + 1;
            else if(letters[mid] > target){
                res = letters[mid];
                end = mid - 1;
            }
            else start = mid + 1;
        }
        return res;
    }
};

int main(){
    return 0;
}