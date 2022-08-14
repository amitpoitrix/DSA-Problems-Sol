#include <bits/stdc++.h>
using namespace std;

// GFG: Largest subarray with 0 sum
// https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

class Solution{
public:
    int maxLen(vector<int>&A, int n){
        // Using Hashmap<prefixSum, index>
        unordered_map<int, int> mp;
        int len = 0, sum = 0;
        
        for(int i = 0; i < n; i++){
            sum += A[i];    // Keep on Adding A[i] to sum
            
            if(sum == 0)    // Ans: if sum becomes 0 than than entire array from 0 to i is the length
                len = max(len, i + 1);

            else{   // If not than check in hashmap
                if(mp.find(sum) != mp.end())    // Ans: if found than length will be (i - hashmap[currentSum])
                    len = max(len, i - mp[sum]);
                else    // if not than add that sum with its idx into hashmap
                    mp[sum] = i;
            }
        }
        
        return len;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}