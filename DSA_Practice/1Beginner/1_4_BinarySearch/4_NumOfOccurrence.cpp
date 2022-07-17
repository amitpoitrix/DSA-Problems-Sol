#include<bits/stdc++.h>
using namespace std;

// Number of occurrence
// https://practice.geeksforgeeks.org/problems/number-of-occurrence2259/1/

class Solution{
public:	
	int count(int arr[], int n, int x) {
	    int first = lower_bound(arr, arr + n, x) - arr;
	    if(first == n || arr[first] != x)
	        return 0;
	    
	    int last = upper_bound(arr, arr + n, x) - arr - 1;
	    
	    return last - first + 1;
	}
};

int main(){
    return 0;
}