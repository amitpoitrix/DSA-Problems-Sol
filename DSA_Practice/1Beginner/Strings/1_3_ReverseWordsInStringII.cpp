#include<iostream>
#include<vector>
#include<string>
// Leetcode : 186. Reverse Words in a String II

class Solution{
private:
    void reverseString(std::vector<char> &str){
        int n = str.size();
        int start = 0;
        int end = n - 1;

        while (start < end){
            std::swap(str[start++], str[end--]);
        }
    }

public:
    void reverseWords(std::vector<char> &s){
        int n = s.size();
        int start = 0;
        for (int i = 0; i <= n; i++){
            // comparing white space & null i.e., '\0'
            if(s[i] == ' ' || s[i] == '\0'){
                int end = i - 1;

                while (start < end){
                    std::swap(s[start++], s[end--]);
                }

                start = i + 1;
            }
        }
        
        reverseString(s);
    }
};

int main(){
    std::vector<char> s = {'t', 'h', 'e', ' ', 's', 'k', 'y', ' ', 'i', 's', ' ', 'b', 'l', 'u', 'e'};

    Solution obj;
    obj.reverseWords(s);
    for (auto x : s){
        std::cout << x << " ";
    }
    
    return 0;
}