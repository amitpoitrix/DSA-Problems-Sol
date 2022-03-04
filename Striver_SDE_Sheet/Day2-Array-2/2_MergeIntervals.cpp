#include<iostream>
#include<vector>
#include<algorithm>
// Striver SDE Sheet - Day2-Array-Part2
// Leetcode - 56. Merge Intervals
// for this we have to first ask interviewer whether it is sort or not if not than sort it first

// BruteForce Approach - Using 2 for loops - No TLE
// TC - O(n * m)
// SC - O(n * 2)
// ACCEPTED
class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        int n = intervals.size();
        // First sorting the intervals
        std::sort(intervals.begin(), intervals.end());

        std::vector<std::vector<int>> result;

        for (int i = 0; i <= n - 1; i++){
            // Taking two pointers as start & end
            int start = intervals[i][0];
            int end = intervals[i][1];

            // checking condn whether current start is greater than last stored end element if yes than just move on so as to avoid 
            // repetitive pairs like eg: {1,3}, {2,6} so this will store {{1,6}, {2,6}} which should be {{1,6}} only
            if(!result.empty()){
                // As we are comparing with last stored element use back() instead of [i-1]
                if(start <= result.back()[1])
                    continue;
            }

            // Else inserting the new pair(start, end)
            // Looping j from i+1
            for (int j = i + 1; j <= n - 1; j++){
                // checking whether end of current is greater than start of next & also if current end is smaller than next end
                // if yes than update the end with next end
                if(end >= intervals[j][0] && end < intervals[j][1]){
                    end = intervals[j][1];
                }
            }
            
            std::vector<int> res;
            res.push_back(start);
            res.push_back(end);

            result.push_back(res);
        }
        
        return result;
    }
};

// Optimized Approach using single loop
// TC - O(n)
// SC - O(n * 2)
// ACCEPTED
class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        int n = intervals.size();
        // sort the intervals
        std::sort(intervals.begin(), intervals.end());

        std::vector<std::vector<int>> result;

        for (int i = 0; i <= n - 1; i++){
            int start = intervals[i][0];
            int end = intervals[i][1];

            // Whether return result is empty OR if last pair end element is less than current start than add new pair else get 
            // the max current end
            if(result.empty() || start > result.back()[1]){
                // Insert the new pair(start, end)
                std::vector<int> res;
                res.push_back(start);
                res.push_back(end);

                result.push_back(res);
            }

            else{
                // that means last pair end element is greater but by how much
                result.back()[1] = std::max(result.back()[1], end);
            }
        }

        return result; 
    }
};

int main(){

    return 0;
}