#include<iostream>
// Recursion by Striver

// Reverse an Array/String
// 1. Using Linear approach - one pointer
// As string is pass by value so we use '&' before string parameter to make changes in original string
void reverseString(std::string &s, int n){
    for (int i = 0; i < n; i++){
        if(i <= n/2)
            std::swap(s[i], s[n-i-1]);
    }
}

// 2. Using Recursive approach - one pointer
// Array is pass by reference
void reverseArray(int i, int n, int arr[]){
    if(i > n/2)
        return;

    std::swap(arr[i], arr[n-i-1]);
    reverseArray(i+1, n, arr);
}

int main(){
    std::string s = "hello";
    int n = s.size();
    reverseString(s, n);
    for (int i = 0; i < n; i++){
        std::cout << s[i] << " ";
    }

    // int arr[] = {1,2,3,4,5};
    // int n1 = sizeof(arr)/sizeof(int);
    // reverseArray(0, n1, arr);
    // for (int i = 0; i < n1; i++){
    //     std::cout << arr[i] << " ";
    // }
    
    return 0;
}