#include<bits/stdc++.h>
using namespace std;

// HackerRank - Array Manipulation
// https://www.hackerrank.com/challenges/crush/problem

// Declaring Array globally
const int N = 1e7 + 10;
long arr[N];

long arrayManipulation(int n, vector<vector<int>> queries) {
    int row = queries.size();
    
    // Computing Hashing
    for(int i = 0; i < row; i++){
        int a = queries[i][0], b = queries[i][1], k = queries[i][2];
        arr[a] += k;
        arr[b + 1] -= k;
    }
    
    // Computing Prefix sum
    for(int i = 1; i <= n; i++){
        arr[i] += arr[i-1];
    }
    
    long ans = 0;
    for(int i = 1; i <= n; i++){
        if(arr[i] > ans)
            ans = arr[i];
    }
    
    return ans;
}

int main(){
    return 0;
}