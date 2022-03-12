#include<iostream>
#include<vector>
// Leetcode - Weekly Contest 276 on 16th Jan 2022
// 3. 2140. Solving Questions With Brainpower

// Using DP - Memoization
class Solution1 {
public:
    #define ll long long
    int n;
    std::vector<ll> p, b, dp;

    ll fmax(int i){
        if(i >= n)
            return 0;
        
        long long &ans = dp[i];
        if(ans != -1)
            return ans;
        
        return ans = std::max(fmax(i+1), p[i] + fmax(i + b[i] + 1));
    }

    long long mostPoints(std::vector<std::vector<int>>& questions) {
        for (auto x : questions){
            p.push_back(x[0]);  // this will store the points
            b.push_back(x[1]);  // this will store brainpower
        }
        
        n = p.size();
        dp.resize(n, -1);

        ll ans = 0;
        for (int i = 0; i < n; i++){
            ans = std::max(ans, fmax(i));
        }
        
        return ans;
    }
};

// Approach 2 - DP(Memoization)
class Solution2{
public:
    #define ll long long
    std::vector<ll> dp;

    ll getPoints(int idx, std::vector<std::vector<int>> &questions, int n){
        if(idx >= n)
            return 0;
        
        else if(dp[idx] != -1)
            return dp[idx];

        else if(idx == n-1)
            return questions[idx][0];
        
        else{
            ll select = questions[idx][0] + getPoints(idx + 1 + questions[idx][1], questions, n);
            ll reject = 0 + getPoints(idx + 1, questions, n);

            return dp[idx] = std::max(select, reject);
        }
    }

    long long mostPoints(std::vector<std::vector<int>>& questions) {
        int n = questions.size();
        dp.resize(n, -1);
        return getPoints(0, questions, n);
    }
};

int main(){
    std::vector<std::vector<int>> questions = {{1,1}, {2,2}, {3,3}, {4,4}, {5,5}};
    Solution2 obj;
    std::cout << obj.mostPoints(questions);

    return 0;
}