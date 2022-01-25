#include<iostream>
// Recursion by Striver

// 1. Sum of N numbers
// Using Parameterised Recursion - return type void
void printSum(int i, int sum){
    if(i < 1){
        std::cout << sum;
        return;
    }

    printSum(i-1, sum + i);
}

// Using functional recursion - return type int,bool etc
int printSumFR(int n){
    if(n == 0)
        return 0;
    
    return n + printSumFR(n-1);
}

// 3. Factorial using Functional Recursion
int printfactorialFR(int n){
    if(n == 1)
        return 1;
    
    return n * printfactorialFR(n-1);
}

int main(){
    int n;
    std::cin >> n;

    // for parameterised recursion... initially passing sum as 0
    // printSum(n, 0);

    // Using functional recursion
    // std::cout << printSumFR(n);

    std::cout << printfactorialFR(n);

    return 0;
}