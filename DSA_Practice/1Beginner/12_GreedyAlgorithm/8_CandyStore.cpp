#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Shop in Candy Store
// https://practice.geeksforgeeks.org/problems/shop-in-candy-store1145/1

class Solution{
public:
    vector<int> candyStore(int candies[], int N, int K){
        sort(candies, candies + N);
        vector<int> res;
        int minAmt = 0, maxAmt = 0, i = 0, j = N-1;

        // For min Amount
        while(i <= j){
            minAmt += candies[i];
            i++;
            j -= K;
        }
        res.push_back(minAmt);

        // For max Amount
        i = 0, j = N-1;
        while(i <= j){
            maxAmt += candies[j];
            j--;
            i += K;
        }
        res.push_back(maxAmt);
        
        return res;
    }
};

int main(){
    return 0;
}