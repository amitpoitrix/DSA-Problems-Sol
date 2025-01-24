/**
 * 1267. Count Servers that Communicate
 * Link: https://leetcode.com/problems/count-servers-that-communicate/description/?envType=daily-question&envId=2025-01-23
 * 
 * 
 * Approach 1: Bruteforce Approach
 * Traverse each cell in the grid and check for other servers in the same row and column. 
 * If any are found, mark the current server as communicable. 
 * This approach is straightforward but involves redundant checks.
 * 
 * Complexity: 
 * Time: O(m * n * (m + n))
 * Space: O(1)
 */

class Solution1 {
    public int countServers(int[][] grid) {
        // Approach 1: Bruteforce Approach
        int m = grid.length;
        int n = grid[0].length;

        int countServers = 0;

        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(grid[row][col] == 1) {
                    // Means we got 1 server, now we'll check if there is any server in its entire row or col
                    // First we'll check entire row
                    boolean gotAnotherServer = false;
                    for(int j = 0; j < n; j++) {
                        if(grid[row][j] == 1 && j != col) {
                            // We got one server other than the current one
                            countServers++;
                            gotAnotherServer = true;
                            break;
                        }
                    }

                    if(gotAnotherServer == false) {
                        // Now we'll check entire column as we couldn't find any other server
                        for(int i = 0; i < m; i++) {
                            if(grid[i][col] == 1 && i != row) {
                                countServers++;
                                break;
                            }
                        }
                    }
                }
            }
        }

        return countServers;
    }
}


/**
 * Approach 2: Better Approach
 * Precompute the count of servers in each row and column. 
 * During a second traversal, a server is communicable if its row or column has more than one server. 
 * This reduces redundant checks by leveraging preprocessing.
 * 
 * Complexity:
 * Time: O(m * n)
 * Space: O(m * n)
 */

class Solution2 {
    public int countServers(int[][] grid) {
        // Approach 2: Better Approach
        int m = grid.length;
        int n = grid[0].length;

        // Step 1: Preprocess no. of servers for each row & col at there respective array
        int[] rowServerCount = new int[m];
        int[] colServerCount = new int[n];

        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(grid[row][col] == 1) {
                    rowServerCount[row]++;
                    colServerCount[col]++;
                }
            }
        }

        // Step 2: Now wherever we find server we'll check if there is any other server in respective array which is more than 2 if yes than we'll increment the server count
        int countServers = 0;

        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(grid[row][col] == 1) {
                    // means server is there now we need to check is there is any other server in entire row or col
                    if(rowServerCount[row] > 1 || colServerCount[col] > 1) {
                        countServers++;
                    }
                }
            }
        }

        return countServers;
    }
}