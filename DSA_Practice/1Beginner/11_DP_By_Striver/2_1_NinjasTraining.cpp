#include<iostream>
#include<vector>
using namespace std;
// DP by Striver : DP 7. Ninja's Training | 2D CONCEPTS | Vacation | Atcoder | 2D DP |

// Using Recursion
class Solution{
private:
    int recursiveF(int day, int last, vector<vector<int>> points){
        if(day == 0){
            int maxi = 0;
            for (int task = 0; task < 3; task++){
                if(task != last){
                    maxi = max(maxi, points[day][task]);
                }
            }
            
            return maxi;
        }

        int maxii = 0;
        for (int task = 0; task < 3; task++){
            if(task != last){
                int maxPoint = points[day][task] + recursiveF(day - 1, task, points);
                maxii = max(maxii, maxPoint);
            }
        }
        
        return maxii;
    }

public:
    int ninjaTraining(int n, vector<vector<int>> &points){
        return recursiveF(n-1, 3, points);
    }
};


// Using DP
// 1st Method : Memoization(Top-Down)
// TC - O(n * 4) * 3
// SC - O(n) + O(n * 4)
class Solution1{
private:
    int recursiveF(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp){
        if(day == 0){
            int maxi = 0;
            for (int task = 0; task < 3; task++){
                if(task != last){
                    maxi = max(maxi, points[day][task]);
                }
            }
            return dp[day][last] = maxi;
        }

        if(dp[day][last] != -1)
            return dp[day][last];

        int maxii = 0;
        for (int task = 0; task < 3; task++){
            if(task != last){
                int maxPoint = points[day][task] + recursiveF(day - 1, task, points, dp);
                maxii = max(maxii, maxPoint);
            }
        }
        
        return dp[day][last] = maxii;
    }

public:
    int ninjaTraining(int n, vector<vector<int>> &points){
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return recursiveF(n-1, 3, points, dp);
    }
};


// 2nd Method : Tabulation(Bottom-Up)
// TC - O(n * 4) * 3
// SC - O(n * 4)
class Solution2{
public:
    int ninjaTraining(int n, vector<vector<int>> &points){
        vector<vector<int>> dp(n, vector<int>(4, -1));

        dp[0][0] = max(points[0][1], points[0][2]);
        dp[0][1] = max(points[0][0], points[0][2]);
        dp[0][2] = max(points[0][0], points[0][1]);
        dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

        for (int day = 1; day < n; day++){
            for (int last = 0; last < 4; last++){
                dp[day][last] = 0;
                int maxi = 0;
                for (int task = 0; task < 3; task++){
                    if(task != last){
                        int maxPoint = points[day][task] + dp[day - 1][task];
                        maxi = max(maxi, maxPoint);
                    }
                }     
                dp[day][last] = maxi;
            }
        }
        
        return dp[n-1][3];
    }
};


// Space Complexity Optimization over Tabulation Method
// TC - O(n * 4) * 3
// SC - O(4)
class Solution3{
public:
    int ninjaTraining(int n, vector<vector<int>> &points){
        // prev[] to store previous day data
        vector<int> prev(4, 0);
        prev[0] = max(points[0][1], points[0][2]);
        prev[1] = max(points[0][0], points[0][2]);
        prev[2] = max(points[0][0], points[0][1]);
        prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

        for (int day = 1; day < n; day++){
            // temp[] to store value for current day data
            vector<int> temp(4, 0);

            for (int last = 0; last < 4; last++){
                temp[last] = 0;
                for (int task = 0; task < 3; task++){
                    if(task != last){
                        temp[last] = max(temp[last], points[day][task] + prev[task]);
                    }
                }
            }
            // storing current day data to previous day for next iteration
            prev = temp;
        }
        
        return prev[3];
    }
};


int main(){
    vector<vector<int>> points = {{10, 40, 70}, {20, 50, 80}, {30, 60, 90}};
    int n = points.size();

    Solution3 obj;
    cout << obj.ninjaTraining(n, points);

    return 0;
}