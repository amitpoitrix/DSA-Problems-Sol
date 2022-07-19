#include<iostream>
#include<vector>
#include<string>
using namespace std;

// Leetcode : 186. Reverse Words in a String II - See Img
// Ques - We have to reverse the order of words in a sentence not the character of sentence or each word without using 
// extra space i.e, in-order

// Algo:
// 1. Logic - First we'll reverse character of each word independently and than reverse the whole sentence
// 2. if vector<char> is passed as given parameter than we've to traverse from [0 - n] both inclusive why? because char array
// stores '/0' NULL at the end of the character string
// 3. Reversing character of each word - At each iteration we'll check whether i encounters ' ' space or '/0' NULL value if 
// so than make end pointer as i-1 & do reversal of characters from [start, end] and for next iteration make start as i+1 
// 4. After reversal of all characters(as words) we'll reverse whole sentence.

// TC - O(n^2)
// SC - O(1)

class Solution{
private:
    void reverseString(vector<char> &str){
        int n = str.size();
        int start = 0;
        int end = n - 1;

        while (start < end){
            swap(str[start++], str[end--]);
        }
    }

public:
    void reverseWords(vector<char> &s){
        int n = s.size();
        int start = 0;
        for (int i = 0; i <= n; i++){
            // comparing white space & null i.e., '\0'
            if(s[i] == ' ' || s[i] == '\0'){
                // For current iteration end will be 
                int end = i - 1;
                while (start < end){
                    swap(s[start++], s[end--]);
                }

                // For next iteration start will be
                start = i + 1;
            }
        }
        
        reverseString(s);
    }
};

int main(){
vector<char> s = {'t', 'h', 'e', ' ', 's', 'k', 'y', ' ', 'i', 's', ' ', 'b', 'l', 'u', 'e'};

    Solution obj;
    obj.reverseWords(s);
    for (auto x : s){
        cout << x << " ";
    }
    
    return 0;
}