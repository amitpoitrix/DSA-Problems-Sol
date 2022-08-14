#include<bits/stdc++.h>
using namespace std;

// IB: Subarray with given XOR
// https://www.interviewbit.com/problems/subarray-with-given-xor/

// Using Kadane's Algorithm - Single traversal using hashmap
// TC - O(nlogn)
// SC - O(n)
class Solution{
    int countSubarray(vector<int> &A, int B) {
        // Taking hashmap<prefix XOR, count>
        unordered_map<int, int> mp;
        int cnt = 0, xxor = 0, n = A.size();
    
        for(int i = 0; i < n; i++){
            xxor ^= A[i];   // Keep on computing XOR of all elements at each iteration
        
            if(xxor == B)   // Ans: If xxor becomes equal to B than inc. count
                cnt++;
        
            if(mp.find(xxor ^ B) != mp.end())   // If (xxor ^ B) is there in hashmap than also add its count
                cnt += mp[xxor ^ B];
        
            mp[xxor] += 1;  // Add current xxor in hashmap or inc. its count
        }
    
        return cnt;
    }
};

int main(){
    return 0;
}