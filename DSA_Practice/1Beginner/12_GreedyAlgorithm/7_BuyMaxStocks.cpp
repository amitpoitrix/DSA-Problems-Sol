#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Buy Maximum Stocks if i stocks can be bought on i-th day 
// https://practice.geeksforgeeks.org/problems/buy-maximum-stocks-if-i-stocks-can-be-bought-on-i-th-day/1/

// TC - O(nlogn) + O(n)
// SC - O(n)
class Solution{
private:
    struct stock{
        int cost, day;
    };
    
    static bool comparator(struct stock m1, struct stock m2){
        return m1.cost < m2.cost;
    }

public:
    int buyMaximumProducts(int n, int k, int price[]){
        vector<stock> m(n);
        for(int i = 0; i < n; i++){
            m[i].cost = price[i];
            m[i].day = i+1;
        }
        
        sort(m.begin(), m.end(), comparator);
        
        int count = 0;
        for(int i = 0; i < n && k > 0; i++){
            count += min(k/m[i].cost, m[i].day);
            k -= m[i].cost * min(k/m[i].cost, m[i].day);
        }
        
        return count;
    }
};

int main(){
    return 0;
}