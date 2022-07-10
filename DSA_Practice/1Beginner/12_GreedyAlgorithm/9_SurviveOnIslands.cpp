#include<iostream>
using namespace std;

// Check if it is possible to survive on Island 
// https://practice.geeksforgeeks.org/problems/check-if-it-is-possible-to-survive-on-island4922/1/

// TC - O(1)
// SC - O(1)
class Solution{
public:
    int minimumDays(int S, int N, int M){
        if(N < M || (S > 6 && (N * 6 < M * 7)))
            return -1;
        
        int days = (M * S) / N;
        if((M * S) % N != 0)
            days++;
        
        return days;
    }
};

int main(){
    return 0;
}