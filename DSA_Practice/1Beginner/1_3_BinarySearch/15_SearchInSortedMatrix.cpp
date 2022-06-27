#include<iostream>
#include<vector>
using namespace std;

// Search in a row wise and column wise sorted matrix
// https://www.geeksforgeeks.org/search-in-row-wise-and-column-wise-sorted-matrix/

class Solution{
public:
    int matSearch (int N, int M, vector<vector<int>> matrix, int x){
        int i = 0, j = M-1;
        while(i < N && j >= 0){
            if(x == matrix[i][j]) return 1;
            else if(x < matrix[i][j]) j--;
            else i++;
        }
        return 0;
    }
};

int main(){
    return 0;
}