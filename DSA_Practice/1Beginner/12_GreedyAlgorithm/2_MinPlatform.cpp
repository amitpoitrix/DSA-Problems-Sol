#include<iostream>
#include<algorithm>
using namespace std;

// Minimum Platforms
// https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

class Solution{
public:
    //Function to find the minimum number of platforms 
    //required at the railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n){
    	sort(arr, arr + n);
    	sort(dep, dep + n);
    	
    	// Traversing using 2 pointers
    	int i = 1, j = 0, platform = 1, maxii = platform;
    	while(i < n && j < n){
    	    if(arr[i] <= dep[j]){
    	        platform++;
    	        i++;
    	    }
    	    else{
    	        platform--;
    	        j++;
    	    }
    	    
    	    maxii = max(maxii, platform);
    	}
    	
    	return maxii;
    }
};

int main(){
    return 0;
}