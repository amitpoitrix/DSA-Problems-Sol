#include<iostream>
using namespace std;

// Allocate minimum number of pages 
// https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1/

class Solution {
private:
    bool isValid(int A[], int N, int M, int mid){
        int student = 1;
        int sum = 0;
        for(int i = 0; i < N; i++){
            sum += A[i];
            if(sum > mid){
                student++;
                sum = A[i];
            }
            if(student > M)
                return false;
        }
        
        return true;
    }
        
public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) {
        int maxii = A[0];
        int sum = 0;
        for(int i = 0; i < N; i++){
            maxii = max(maxii, A[i]);
            sum += A[i];
        }
        
        int start = maxii, end = sum, res = -1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(isValid(A, N, M, mid) == true){
                res = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }
        
        return res;
    }
};

int main(){
    return 0;
}