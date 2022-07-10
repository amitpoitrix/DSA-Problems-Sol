#include<iostream>
#include<vector>
using namespace std;

// Maximum product subset of an array 
// https://practice.geeksforgeeks.org/problems/maximum-product-subset-of-an-array/1/#

class Solution{
private:
    int mod = 1e9 + 7;
        
public:
    long long int findMaxProduct(vector<int>&a, int n){
        //Write your code here  
        if(n == 1) return a[0];
        
        long long int product = 1;
        int count_neg = 0, count_zero = 0, max_neg = -1e9;
        for(int i = 0; i < n; i++){
            if(a[i] == 0) {
                count_zero++;
                continue;
            }
            
            if(a[i] < 0) {
                count_neg++;
                max_neg = max(max_neg, a[i]);
            }
            
            product = (product * a[i]) % mod;
        }
        
        if(count_zero == n) return 0;
        
        if(count_neg == 1 && count_zero > 0 && count_zero + count_neg == n) return 0;
        
        if(count_neg & 1){
            product /= max_neg;
        }
        
        return (int)product;
    }
};

int main(){
    return 0;
}