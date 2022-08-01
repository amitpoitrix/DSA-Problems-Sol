#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;
// Striver SDE Sheet - Day2-Array-Part2
// Leetcode - 56. Merge Intervals
// for this we have to first ask interviewer whether it is sort or not if not than sort it first

// BruteForce Approach - Using 2 for loops - No TLE
// TC - O(n * m)
// SC - O(n * 2)
// ACCEPTED
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // First sorting the intervals
        sort(intervals.begin(), intervals.end());

        int n = intervals.size();
        vector<vector<int>> result;

        for (int i = 0; i < n; i++){
            // Taking two pointers to save start interval value & end interval value
            int start = intervals[i][0];
            int end = intervals[i][1];

            // checking condn whether current start is greater than last stored end element if yes than just move on so as
            // to avoid repetitive pairs like eg: {1,3}, {2,6} so this will store {{1,6}, {2,6}} which should be {{1,6}} only
            if(!result.empty()){
                // As we are comparing with last stored element use back() instead of [i-1]
                if(start <= result.back()[1])
                    continue;
            }

            // Else inserting the new pair(start, end)
            // Looping j from i+1
            for (int j = i + 1; j < n; j++){
                // checking whether current's end is greater than start's next & also if current's end is smaller than 
                // next's end 
                if(end >= intervals[j][0] && end < intervals[j][1]){
                    end = intervals[j][1];  // Update current's end only if its smaller than next's end
                }
            }
            
            vector<int> res;
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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1)
            return intervals;

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;
        res.push_back(intervals[0]); // Inserting first element in res

        // Now inserting rest of the intervals element by compairing 
        // last interval (in res) end's value with current's start
        for (int i = 1; i < intervals.size(); i++){
            if (res.back()[1] >= intervals[i][0])
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            else
                res.push_back(intervals[i]);
        }
        return res;
    }
};

int main(){

    return 0;
}