#include<iostream>
#include<vector>
// DP by Striver : DP 7. Ninja's Training | 2D CONCEPTS | Vacation | Atcoder | 2D DP |

// Using Recursion
class Solution{
private:
    int recursiveF(int day, int last, std::vector<std::vector<int>> points){
        if(day == 0){
            int maxi = 0;
            for (int task = 0; task < 3; task++){
                if(task != last){
                    maxi = std::max(maxi, points[day][task]);
                }
            }
            
            return maxi;
        }

        int maxii = 0;
        for (int task = 0; task < 3; task++){
            if(task != last){
                int maxPoint = points[day][task] + recursiveF(day - 1, task, points);
                maxii = std::max(maxii, maxPoint);
            }
        }
        
        return maxii;
    }

public:
    int ninjaTraining(int n, std::vector<std::vector<int>> &points){
        return recursiveF(n-1, 3, points);
    }
};


// Using DP
// 1st Method : Memoization(Top-Down)
// TC - O(n * 4) * 3
// SC - O(n) + O(n * 4)
class Solution1{
private:
    int recursiveF(int day, int last, std::vector<std::vector<int>> &points, std::vector<std::vector<int>> &dp){
        if(dp[day][last] != -1)
            return dp[day][last];
        
        if(day == 0){
            int maxi = 0;
            for (int task = 0; task < 3; task++){
                if(task != last){
                    maxi = std::max(maxi, points[day][task]);
                }
            }
            
            return dp[day][last] = maxi;
        }

        int maxii = 0;
        for (int task = 0; task < 3; task++){
            if(task != last){
                int maxPoint = points[day][task] + recursiveF(day - 1, task, points, dp);
                maxii = std::max(maxii, maxPoint);
            }
        }
        
        return dp[day][last] = maxii;
    }

public:
    int ninjaTraining(int n, std::vector<std::vector<int>> &points){
        std::vector<std::vector<int>> dp(n, std::vector<int>(4, -1));
        return recursiveF(n-1, 3, points, dp);
    }
};


// 2nd Method : Tabulation(Bottom-Up)
// TC - O(n * 4) * 3
// SC - O(n * 4)
class Solution2{
public:
    int ninjaTraining(int n, std::vector<std::vector<int>> &points){
        std::vector<std::vector<int>> dp(n, std::vector<int>(4, -1));

        dp[0][0] = std::max(points[0][1], points[0][2]);
        dp[0][1] = std::max(points[0][0], points[0][2]);
        dp[0][2] = std::max(points[0][0], points[0][1]);
        dp[0][3] = std::max(points[0][0], std::max(points[0][1], points[0][2]));

        for (int day = 1; day < n; day++){
            for (int last = 0; last < 4; last++){
                dp[day][last] = 0;
                int maxi = 0;
                for (int task = 0; task < 3; task++){
                    if(task != last){
                        int maxPoint = points[day][task] + dp[day - 1][task];
                        maxi = std::max(maxi, maxPoint);
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
    int ninjaTraining(int n, std::vector<std::vector<int>> &points){
        std::vector<int> prev(4, 0);

        prev[0] = std::max(points[0][1], points[0][2]);
        prev[1] = std::max(points[0][0], points[0][2]);
        prev[2] = std::max(points[0][0], points[0][1]);
        prev[3] = std::max(points[0][0], std::max(points[0][1], points[0][2]));

        for (int day = 1; day < n; day++){
            // Here just we're creating dummy array compute it and than store it in prev array
            std::vector<int> temp(4, 0);

            for (int last = 0; last < 4; last++){
                // Computing dummy array i.e., temp[] or current day(dp[day][task]) is store in temp & previous day(dp[day-1][task]) in prev
                temp[last] = 0;

                for (int task = 0; task < 3; task++){
                    if(task != last){
                        temp[last] = std::max(temp[last], points[day][task] + prev[task]);
                    }
                }
            }
            // Storing dummy array value in prev array
            prev = temp;
        }
        
        return prev[3];
    }
};


int main(){
    std::vector<std::vector<int>> points = {{10, 40, 70}, {20, 50, 80}, {30, 60, 90}};
    int n = points.size();

    Solution3 obj;
    std::cout << obj.ninjaTraining(n, points);

    return 0;
}