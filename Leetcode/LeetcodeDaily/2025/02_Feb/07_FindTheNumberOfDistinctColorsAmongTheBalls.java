/**
 * 3160. Find the Number of Distinct Colors Among the Balls
 * Link: https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/description/?envType=daily-question&envId=2025-02-07
 * 
 * 
 * Approach 1: Using Array and HashMap
 * The idea is to track the color of each ball using an array and maintain the count of colors using a hashmap. 
 * If a ball changes color, we update the hashmap by decrementing the count of the previous color and incrementing the 
 * count of the new one. 
 * The answer at each step is the number of unique colors. 
 * This approach uses an array for direct ball access, making updates efficient but consuming extra space.
 * 
 * Complexity:
 * Time: O(n)
 * Space: O(n); Due to extra array 
 */

// Test Case:
// Ans - [1,2,1,2,1]
// limit = 1
// [[0,1],[1,4],[1,1],[1,4],[1,1]]
//                                i

// result = 1 2 1 2 1

// Map<Ball, Color>
// In order to get ball previous color before assigning new one
// previous color of ball is needed to reduce color count from another HashMap
// 0 -> 1
// // 1 -> 4 before removing 4 just store previous color of ball 1 i.e., 4
// 1 -> 1 

// prevous color lelenge = 4

// Map<Color, Frequency>
// previous ball color is used here to reduce color frequency
// And this map size will track size of distinct color at each iteration
// 1 -> 2
// // 4 -> 1
// // 4 -> 1 removed by previous color

class Solution1 {
    public int[] queryResults(int limit, int[][] queries) {
        // Approach 1: Using Single Map + Extra Array
        int n = queries.length;

        // Map<Color, Frequency>
        Map<Integer, Integer> colorFreq = new HashMap<>();

        // Extra array to get previous color of current ball
        int[] ballColor = new int[limit + 1];   // Note: size of (limit + 1) not n
        Arrays.fill(ballColor, -1);

        int[] result = new int[n];

        for(int i = 0; i < n; i++) {
            int ball = queries[i][0];
            int color = queries[i][1];

            // Already color
            if(ballColor[ball] != -1) {
                // Getting last/previous color of current ith ball
                int previousColor = ballColor[ball];

                // Reducing previousColor frequency & if it becomes 0 than removing from colorFreq
                colorFreq.put(previousColor, colorFreq.getOrDefault(previousColor, 0) - 1);

                if(colorFreq.get(previousColor) == 0) {
                    colorFreq.remove(previousColor);
                }
            }

            ballColor[ball] = color;
            
            colorFreq.put(color, colorFreq.getOrDefault(color, 0) + 1);

            result[i] = colorFreq.size();
        }

        return result;
    }
}


/**
 * Approach 2: Using 2 HashMap
 * Instead of using an array, we directly map each ball to its color using a hashmap. 
 * Another hashmap keeps track of color frequencies. 
 * When a ball changes color, we update both hashmaps accordingly. 
 * This approach reduces space usage compared to Approach 1 but still ensures efficient updates and retrieval of unique colors.
 * 
 * 
 * Complexity:
 * Time: O(n)
 * Space: O(n); but comparitively lesser than Approach 1 which uses Array of size (limit + 1) but here we're using Map
 */

class Solution2 {
    public int[] queryResults(int limit, int[][] queries) {
        // Approach 1: Using Single Map + Extra Array
        int n = queries.length;

        // 1st Map<Color, Frequency>
        Map<Integer, Integer> colorFreq = new HashMap<>();

        // 2nd Another Map to get previous color of current ball
        Map<Integer, Integer> ballColor = new HashMap<>();

        int[] result = new int[n];

        for(int i = 0; i < n; i++) {
            int ball = queries[i][0];
            int color = queries[i][1];

            // If current ball is already color before than take the last color of current ball & reduce its frequency
            if(ballColor.containsKey(ball)) {
                // Getting last/previous color of current ball
                int previousColor = ballColor.get(ball);

                // Reducing previousColor frequency & if it becomes 0 than removing from colorFreq
                colorFreq.put(previousColor, colorFreq.getOrDefault(previousColor, 0) - 1);

                if(colorFreq.get(previousColor) == 0) {
                    colorFreq.remove(previousColor);
                }
            }

            ballColor.put(ball, color);
            
            colorFreq.put(color, colorFreq.getOrDefault(color, 0) + 1);

            result[i] = colorFreq.size();
        }

        return result;
    }
}
