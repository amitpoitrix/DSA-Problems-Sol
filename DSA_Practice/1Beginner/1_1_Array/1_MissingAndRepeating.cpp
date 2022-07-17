#include<iostream>
using namespace std;

// Find Missing And Repeating
// https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int * res = new int[2];
        int i = 0;
        while(i < n){
            if(arr[i] != arr[arr[i] - 1])
                swap(arr[i], arr[arr[i] - 1]);
            else
                i++;
        }
        
        for(int i = 0; i < n; i++){
            if(arr[i] != i+1){
                res[0] = arr[i];
                res[1] = i+1;
            }
        }
        
        return res;
    }
};

int main(){
    return 0;
}