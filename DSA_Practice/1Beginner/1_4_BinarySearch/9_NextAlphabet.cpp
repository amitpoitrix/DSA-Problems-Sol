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

// Another Approach - Using concept of Favourable and Unfavourable Search Space
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0;
        int h = letters.size() - 1;
        
        while(l <= h){
            int mid = l + (h - l) / 2;
            
            // Favorable Search Space
            if(letters[mid] > target)
                h = mid - 1;
            
            // Unfavorable Search Space
            else
                l = mid + 1;
        }
        
        return (l >= letters.size())? letters[0]: letters[l];
    }
};

int main(){
    return 0;
}