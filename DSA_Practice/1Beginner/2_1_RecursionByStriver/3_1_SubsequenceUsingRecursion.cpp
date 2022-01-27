#include<iostream>
#include<vector>
// Recursion By Striver : L6. Recursion on Subsequences | Printing Subsequences
// A contiguous/ non-contiguous sequences which follows the order
// if n is the size of input that output will have 2^n subsequences

// Using Recursion - Here we have choice in each element/character either to choose it or not to choose it so two recursion calls
// will be used
// TC - O(n*(2^n)) - As starting n is due to for loop for each subsequence
// SC - O(n) - At max stack space is having n no. of elements
void printSubsequence(int i, int arr[], int n, std::vector<int> &ds){
    if(i == n){
        for (auto x : ds){
            std::cout << x << " ";
        }

        if(ds.size() == 0)
            std::cout << "{}";  
        
        std::cout << "\n";
        return;
    }

    // Pick or take that element & considering this in subsequence
    ds.push_back(arr[i]);
    printSubsequence(i+1, arr, n, ds);
    ds.pop_back();

    // Not picking current element so that it will not consider in subsequence
    printSubsequence(i+1, arr, n, ds);
}

int main(){
    int arr[] = {3,2,1};
    int n = sizeof(arr)/sizeof(int);

    std::vector<int> ds;    // Taking 1 data structure in order to store the subsequence 
    printSubsequence(0, arr, n, ds);

    return 0;
}