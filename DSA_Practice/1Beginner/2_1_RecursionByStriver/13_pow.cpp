#include <iostream>
using namespace std;

// Lt: 50. Pow(x, n)
// https://leetcode.com/problems/powx-n/

// Approach 1: Iterative Approach
// TC - O(log n)
// SC - O(1)
class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        while(n){
            // When n is odd
            if(n % 2)
                ans = (n > 0) ? ans * x: ans / x;
            x *= x;
            n /= 2;
        }
        return ans;
    }
};

// Approach 2: Recursive Approach
// TC - O(log n)
// SC - O(log n); Recursive Stack Space
class Solution {
public:
    double myPow(double x, int n) {
        // Base case
        if(n == 0) return 1;
        if(n == 1) return x;
        if(n == -1) return 1/x;
        
        // Recursive call
        double res = myPow(x, n/2);
        
        // If n is even
        if(n % 2 == 0) return res * res;
        // If n is odd and +ve
        if(n > 0) return res * res * x;
        // if n is -ve
        return res * res * (1/x);
    }
};


int main(){
    return 0;
}