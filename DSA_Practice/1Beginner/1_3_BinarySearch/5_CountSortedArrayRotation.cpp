#include<iostream>
using namespace std;

class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    int start = 0;
	    int end = n - 1;
	    
	    while(start <= end){
	        int mid = start + (end - start)/2;
	        int prev = (mid - 1 + n) % n;
	        int next = (mid + 1) % n;
	        
	        if(arr[mid] <= arr[prev] && arr[mid] <= arr[next])
	            return mid;
	        
	        if(arr[0] <= arr[mid])
	            start = mid + 1;
	        
	        else if(arr[mid] <= arr[n - 1])
	            end = mid - 1;
	    }
	    
	    return 0;
	}
};

int main(){
    return 0;
}