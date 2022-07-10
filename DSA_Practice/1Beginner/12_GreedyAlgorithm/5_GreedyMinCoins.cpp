#include<iostream>
#include<vector>
using namespace std;

// Minimum number of Coins 
// https://practice.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1/

class Solution{
public:
    vector<int> minPartition(int N){
        vector<int> currency = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
        vector<int> res;
        for(int i = currency.size()-1; i >= 0; i--){
            while(currency[i] <= N){
                N -= currency[i];
                res.push_back(currency[i]);
            }
        }
        return res;
    }
};

int main(){
    return 0;
}