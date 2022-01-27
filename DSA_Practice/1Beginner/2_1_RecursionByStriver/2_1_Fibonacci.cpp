#include<iostream>
// Recursion by Striver
// Fibonacci - 0 1 1 2 3 5 8 13 21

// Without Recursion
int fibonacciWithoutRecursion(int n){
    int arr[n+1];
    arr[0] = 0;
    arr[1] = 1;

    for (int i = 2; i <= n; i++){
        arr[i] = arr[i-1] + arr[i-2];
    }
    
    return arr[n];
}

// With Recursion
// TC - 2^n; SC - O(n)
int fibonacciWithRecursion(int n){
    if(n <= 1)
        return n;
    
    int first = fibonacciWithRecursion(n-1);
    int second = fibonacciWithRecursion(n-2);

    return first + second;
}

int main(){
    std::cout << fibonacciWithoutRecursion(8);
    std::cout << "\n";
    std::cout << fibonacciWithRecursion(8);

    return 0;
}