import java.util.*;

/*
 * 2054. Two Best Non-Overlapping Events
 * Link: https://leetcode.com/problems/two-best-non-overlapping-events/description/?envType=daily-question&envId=2024-12-08
 * 
 * 
 * Approach 1: Brute Force Approach - TLE
 * 
 * This approach uses two nested loops to compare each event with every other event. For each pair of events, it checks whether 
 * they overlap (based on their start and end times) and calculates the maximum value possible by considering non-overlapping 
 * events. The solution simply checks every combination of two events, which leads to the quadratic time complexity. 
 * This approach is inefficient and leads to a time limit exceeded (TLE) error for large inputs.
 */

 class Solution1 {
    public int maxTwoEvents(int[][] events) {
        // Brute Force Approach
        int n = events.length;

        int result = 0;

        for(int i = 0; i < n; i++) {
            // 1st Best Event
            int maxValue = events[i][2];
            result = Math.max(result, maxValue);

            for(int j = 0; j < n; j++) {
                // Skip those element which is at ith position
                if(i == j) {
                    continue;
                }

                // 2nd Best Event
                // Non-overlapping
                if(events[j][1] < events[i][0] || events[j][0] > events[i][1]) {
                    result = Math.max(result, maxValue + events[j][2]);
                }
            }
        }

        return result;
    }
}

/*
 * Approach 2: Recursion + Memoization and Sorting
 * 
 * This optimized approach sorts the events first by their start time. 
 * Then, it uses recursion combined with memoization to explore all possible solutions. 
 * It also uses binary search (upper_bound) to efficiently find the next non-overlapping event. 
 * This reduces the need for nested loops and ensures that the solution can handle larger inputs. 
 * By memoizing results for overlapping subproblems, we avoid recalculating the same solutions multiple times. 
 * The overall time complexity is significantly improved to O(nlogn), making it suitable for larger inputs.
 */


class Solution2 {
    public int maxTwoEvents(int[][] events) {
        // Here in ques, we've to choose atmost 2 events so there is this possibility of choosing an event or not choosing 
        // (means pick & non-pick startegy) so we can apply recursion and while choosing event we'll keep track of no. of 
        // events being choosen, so if it crosses 2 we'll stop.
        // So during picking of current event, we need to choose next element from rest of the event so for this we can 
        // sort the events base don starting time and than choose those first event which doesn't violate the range with 
        // the current event using Binary Search

        // Sorting events based on starting time
        Arrays.sort(events, (a, b) -> {
            return Integer.compare(a[0], b[0]);
        });

        int[][] dp = new int[events.length][2];
        for(int[] row: dp) {
            Arrays.fill(row, -1);
        }

        int countEvents = 0;
        return solver(0, events, countEvents, dp);
    }

    private int solver(int idx, int[][] events, int countEvents, int[][] dp) {
        // Base Case: When idx crosses Array of count reaches 2
        if(idx >= events.length || countEvents == 2) {
            return 0;
        }

        if(dp[idx][countEvents] != -1)
            return dp[idx][countEvents];

        int nextIdx = binarySearch(events, events[idx][1]);
        int pick = events[idx][2] + solver(nextIdx, events, countEvents + 1, dp);

        int nonPick = solver(idx + 1, events, countEvents, dp);

        return dp[idx][countEvents] = Math.max(pick, nonPick);
    }

    // Upper Bound - first smallest idx greater than target
    private int binarySearch(int[][] events, int endTime) {
        int left = 0;
        int right = events.length - 1;

        int nextIdx = events.length;

        while(left <= right) {
            int mid = left + (right - left) / 2;

            if(events[mid][0] > endTime) {
                nextIdx = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return nextIdx;
    }
}