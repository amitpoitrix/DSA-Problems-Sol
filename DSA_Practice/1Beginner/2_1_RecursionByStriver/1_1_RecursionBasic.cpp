#include<iostream>
// Recursion by Striver
// Using Parameterised Recursion - i.e., recursion using extra parameters & return type is void

// 1. Printing Names N times
void printName(int i, int n){
    if(i >= n)
        return;
    
    std::cout << "Amit" << "\n";
    printName(i+1, n);
}

// 2. print 1 to N
void print1toN(int i, int n){
    if(i > n)
        return;
    
    std::cout << i << "\n";
    print1toN(i+1, n);
}

// 3. print N to 1
void printNto1(int i){
    if(i < 1)
        return;

    std::cout << i << "\n";
    printNto1(i-1);
}

// Using parameterised backtracking
// 4. print 1 to n
void print1toNBacktracking(int i){
    if(i < 1)
        return;
    
    print1toNBacktracking(i-1);
    std::cout << i << "\n";
}

// 5. print n to 1
void printNto1Backtracking(int i, int n){
    if(i > n)
        return;
    
    printNto1Backtracking(i+1, n);
    std::cout << i << "\n";
}

int main(){
    int n;
    std::cin >> n;

    // 1. printName()
    // printName(0, n);

    // 2. print1toN()
    // print1toN(1, n);

    // 3. printNto1()
    // printNto1(n);

    // 4. print1toNbacktracking()
    // print1toNBacktracking(n);

    // 5. printNto1backtracking()
    printNto1Backtracking(1, n);

    return 0;
}