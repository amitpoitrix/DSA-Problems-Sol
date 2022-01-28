#include<iostream>
#include<vector>
#include<algorithm>
// Recursion by Striver - L10. Subset Sum I

// Bruteforce Approach - Using Power Set
// TC - O(2^n)
// SC - O(n * 2^n)
class Solution1{
public:
    std::vector<int> subsetSums(std::vector<int> arr, int N){
        int len = (1 << N) - 1;
        std::vector<int> sumSubset;

        for (int i = 0; i <= len; i++){
            int res = 0;
            for (int j = 0; j < N; j++){
                if(i & (1 << j))
                    res += arr[j];
            }
            sumSubset.push_back(res);
        }
        
        std::sort(sumSubset.begin(), sumSubset.end());
        return sumSubset;
    }
};

// Optimized Approach - Using Recursion
// TC - O(2^N)
// SC - O(2^N)
class Solution{
private:
    void calSubsetSum(int i, int sum, std::vector<int> &arr, int N, std::vector<int> &sumSubset){
        if(i == N){
            sumSubset.push_back(sum);
            return;
        }

        // Take
        calSubsetSum(i+1, sum + arr[i], arr, N, sumSubset);

        // Not Take
        calSubsetSum(i+1, sum, arr, N, sumSubset);
    }

public:
    std::vector<int> subsetSums(std::vector<int> arr, int N){
        std::vector<int> sumSubset;
        calSubsetSum(0, 0, arr, N, sumSubset);
        std::sort(sumSubset.begin(), sumSubset.end());
        return sumSubset;
    }
};

int main(){
    std::vector<int> arr = {2,5,1};
    int N = arr.size();

    Solution1 obj;
    for (auto x : obj.subsetSums(arr, N)){
        std::cout << x << " ";
    }
    
    return 0;
}