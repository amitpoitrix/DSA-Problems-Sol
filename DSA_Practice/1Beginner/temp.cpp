#include<iostream>
#include<vector>
#include<cstring>

class Solution {
public:
    std::vector<std::string> divideString(std::string s, int k, char fill) {
        std::vector<std::string> res;
        if(s.size() < k){
            return res;
        }

        for(int i = 0; i < s.size();i++){
            if(s.size() % k == 0){
                std::string s1 = "";
                while (k--){
                    s1 = s1 + s[i];
                    i++;
                }
                res.push_back(s1);
            }
            else{
                std::string s1 = "";
                while (k--){
                    s1 = s1 + s[i];
                    i++;
                    if(i >= s.size()){
                        int x = k - (s.size() % k);
                        while (x--){
                            s1 = s1 + std::to_string(fill);
                        }
                        res.push_back(s1);
                        return res;
                    }
                    res.push_back(s1);
                }
            }
        }

        return res;
    }
};


class Solution2 {
public:
    std::vector<std::string> divideString(std::string s, int k, char fill) {
        std::vector<std::string> res;
        if(s.size() < k){
            return res;
        }

        bool flag = false;
        std::string last = "";
        for(int i = 0; i < s.size();i++){
            std::string s1 = "";
            while (k--){
                s1 = s1 + s[i];
                i++;
                if(i >= s.size()){
                    flag = true;
                    last = s1;
                    break;
                }
            }
            res.push_back(s1);
        }

        if(flag){
            int x = k - (s.size() % k);
            while (x--){
                last = last + std::to_string(fill);
            }
            res.push_back(last);

            return res;
        }

        return res;
    }
};



int main(){
    std::string s = "abcdefghi";
    char fill = 'x';
    int k = 3;

    Solution2 obj;
    std::vector<std::string> result = obj.divideString(s, k, fill);
    for (auto x : result){
        std::cout << x << " ";
    }

    return 0;
}