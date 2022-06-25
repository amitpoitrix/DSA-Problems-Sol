#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Longest Sub-Array with Sum K
// https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1

// Using Sliding Window - Works only for +ve integers
class Solution{
public:
    int lenOfLongSubarr(int A[],  int N, int K){ 
        int len = -1e9;
        int i = 0, j = 0, sum = 0;
        
        while(j < N){
            // calculations
            sum += A[j];
            
            if(sum < K)
                j++;
            
            else if(sum == K){
                len = max(len, j - i + 1);
                j++;
            }
            
            else if(sum > K){
                while(sum > K){
                    sum -= A[i];
                    i++;
                }
                if(sum == K)
                    len = max(len, j - i + 1);
                j++;
            }
        }
        
        return len;
    } 
};

// Using Hashmap
class Solution2{
public:
    int lenOfLongSubarr(int A[],  int N, int K) { 
        // Complete the function
        int len = 0, sum = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < N; i++){
            sum += A[i];
            
            if(sum == K)
                len = max(len, i + 1);
            
            if(mp.find(sum) == mp.end())
                mp[sum] = i;
            
            if(mp.find(sum - K) != mp.end()){
                len = max(len, i - mp[sum - K]);
            }
        }
        
        return len;
    }
}; 

int main(){
    return 0;
}