#include<iostream>
// CodeStudio : Replace Spaces
// https://www.codingninjas.com/codestudio/problems/replace-spaces_1172172?utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_5

// Replace the white space in Input string with "@40"

// Using Extra Space
class Solution{
public:
    std::string replaceSpaces(std::string &str){
        std::string temp = "";

        for (int i = 0; i < str.size(); i++){
            if(str[i] == ' '){
                temp.push_back('@');
                temp.push_back('4');
                temp.push_back('0');
            }
            else{
                temp.push_back(str[i]);
            }
        }
        
        return temp;
    }
};

// In-place Method - No extra space
class Solution{
public:
    std::string replaceSpaces(std::string &str){
        for (int i = 0; i < str.size(); i++){
            if(str[i] == ' '){
                // Using inbuilt replace() of string stl 
                str.replace(i, 1, "@40");
            }
        }
        
        return str;
    }
};

int main(){
    return 0;
}