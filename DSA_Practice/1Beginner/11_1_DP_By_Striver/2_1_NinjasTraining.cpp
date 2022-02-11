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
public:
    
};


int main(){
    std::vector<std::vector<int>> points = {{10, 40, 70}, {20, 50, 80}, {30, 60, 90}};
    int n = points.size();

    Solution obj;
    std::cout << obj.ninjaTraining(n, points);

    return 0;
}