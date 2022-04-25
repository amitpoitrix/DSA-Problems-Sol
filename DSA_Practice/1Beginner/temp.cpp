#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(string S, string T) {
        if(S.size() % 2){
            // its odd length
            int i = 0, j = S.size()-1;

            while(i < j){
                swap(S[i], S[j]);
            }

            if(S == T){
                cout << "Match";
            }
            else{
                cout << "Dont match";
            }
        }
    }
};

int main(){
//   vector<int> nums = {1,3,4,2,2};

  Solution obj;
  obj.reverseString("abcde", "edcba");

  return 0;
}