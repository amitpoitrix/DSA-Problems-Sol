#include<bits/stdc++.h>
using namespace std;

// Trapping Rain Water 
// https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1#

class Solution{
public:
    long long trappingWater(int arr[], int n){
        int maxL[n], maxR[n];
        
        // Computing Absolute max building on left
        maxL[0] = arr[0];
        for(int i = 1; i < n; i++){
            maxL[i] = max(maxL[i-1], arr[i]);
        }
        
        // Computing Absolute max building on right
        maxR[n-1] = arr[n-1];
        for(int i = n-2; i >= 0; i--){
            maxR[i] = max(maxR[i+1], arr[i]);
        }
        
        long long maxArea = 0;
        int water[n];
        for(int i = 0; i < n; i++){
            water[i] = min(maxL[i], maxR[i]) - arr[i];
            maxArea += water[i];
        }
        
        return maxArea;
    }
};

int main(){
    return 0;
}