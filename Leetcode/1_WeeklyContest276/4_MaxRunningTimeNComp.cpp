#include<iostream>
#include<vector>
#include<climits>
// Leetcode - Weekly Contest 276 on 16th Jan 2022
// 2141. Maximum Running Time of N Computers 

class Solution{
private:
    #define ll long long

    bool canFit(int n, ll mid, std::vector<int>& batteries){
        ll countSum = 0;
        ll totalTime = n * mid;
        for (auto x : batteries){
            if(x < mid){
                countSum += x;
            }
            else{
                countSum += mid;
            }

            if(countSum >= totalTime)
                return true;
        }
        
        return countSum >= totalTime;
    }
public:
    long long maxRunTime(int n, std::vector<int>& batteries) {
        ll totalSum = 0;
        int temp = INT_MAX;
        for (auto x : batteries){
            totalSum += x;
            temp = std::min(temp, x);
        }

        ll low = temp;
        ll high = (totalSum/n) + 1;    // [low, high]
        ll ans = 0;
        while (low < high){
            ll mid = (high + low)/2;

            if(canFit(n, mid, batteries)){
                ans = mid;
                low = mid+1;
            }
            else
                high = mid;
        }
        
        return ans;
    }
};

int main(){
    std::vector<int> questions = {10,10,3,5};
    int n = 3;

    Solution obj;
    std::cout << obj.maxRunTime(n, questions);

    return 0;
}