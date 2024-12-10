/**
 * 2981. Find Longest Special Substring That Occurs Thrice I
 * Link: https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i/description/?envType=daily-question&envId=2024-12-10
 * 
 * 
 * Approach 1: Brute Force - Try All Possible Substrings
 * 
 * This approach generates all possible substrings of the input string and checks for valid ones. 
 * For each substring, it counts the occurrences in the string using a map. 
 * The maximum valid substring length (frequency ≥ 3) is tracked.
 * 
 * Complexity:
 * Time: O(n^3)
 * Space: O(n^2)
 */

class Solution1 {
    public int maximumLength(String s) {
        int n = s.length();

        Map<String, Integer> map = new HashMap<>();

        for(int i = 0; i < n; i++) {

            char startingChar = s.charAt(i);

            for(int j = i; j < n; j++) {

                if(startingChar == s.charAt(j)) {
                    
                    String newSubString = s.substring(i, j + 1);
                    map.put(newSubString, map.getOrDefault(newSubString, 0) + 1);
                } else {
                    break;
                }
            }
        }

        int maxLength = -1;

        for(Map.Entry<String, Integer> entity: map.entrySet()) {
            if(entity.getValue() >= 3) {
                maxLength = Math.max(maxLength, entity.getKey().length());
            }
        }

        return maxLength;
    }
}


/**
 * Approach 2: Better Brute Force
 * 
 * Instead of storing the entire substring, this approach uses a map where the key is a pair of the character and 
 * the substring length i.e., Pair<character, count>
 * For each position in the string, it counts the consecutive identical characters and updates the map. 
 * The cumulative counts are then used to find the maximum valid substring length.
 * 
 * Complexity:
 * Time: O(n^2)
 * Space: O(n^2) (due to the map storing substring lengths and counts)
 */

class Solution2 {
    public int maximumLength(String s) {
        int n = s.length();

        Map<Pair, Integer> map = new HashMap<>();

        for(int i = 0; i < n; i++) {

            char startingChar = s.charAt(i);
            int len = 0;

            for(int j = i; j < n; j++) {

                if(startingChar == s.charAt(j)) {
                    len++;
                    Pair pair = new Pair(startingChar, len);

                    map.put(pair, map.getOrDefault(pair, 0) + 1);
                } else {
                    break;
                }
            }
        }

        int maxLength = -1;

        for(Map.Entry<Pair, Integer> entity: map.entrySet()) {
            if(entity.getValue() >= 3) {
                maxLength = Math.max(maxLength, entity.getKey().count);
            }
        }

        return maxLength;
    }
}

// Note:
// Always override equals and hashCode for objects used as keys in collections 
// like HashMap or HashSet.
class Pair {
    char ch;
    int count;

    Pair(char ch, int count) {
        this.ch = ch;
        this.count = count;
    }

    @Override
    public boolean equals(Object o) {
        if(this == o) {
            return true;
        }
        
        if(o == null || getClass() != o.getClass()) {
            return false;
        }

        Pair pair = (Pair)o;
        return ch == pair.ch && count == pair.count;
    }

    @Override
    public int hashCode() {
        int result = Character.hashCode(ch);
        result = 31 * result + Integer.hashCode(count);
        return result;
    }
}


/**
 * 2982. Find Longest Special Substring That Occurs Thrice II
 * Link: https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-ii/description/
 * 
 * 
 * Approach 3: Optimal - Using a 2D Matrix
 * 
 * This approach uses a 2D matrix where each row corresponds to a character ('a' to 'z') and each column tracks 
 * the frequency of substrings of a specific length. 
 * The input string is traversed once to fill the matrix. 
 * Cumulative frequencies are calculated in reverse to efficiently determine the maximum valid substring length.
 * 
 * Complexity:
 * Time: O(n)
 * Space: O(26 * n) ~ O(n)
 */

class Solution3 {
    public int maximumLength(String s) {
        // Step 1: Populate the similar character substring matrix
        int n = s.length();
        int[][] mat = new int[26][n + 1];

        char prev = s.charAt(0);
        int len = 0;

        for(int i = 0; i < n; i++) {

            if(prev == s.charAt(i)) {
                len++;
            } else {
                // Reset
                prev = s.charAt(i);
                len = 1;
            }

            mat[prev - 'a'][len] += 1;
        }

        // Step 2: Find cumulative sum from right to left and break the loop when cumSum is >= 3
        // Here cumSum will tell us frequency of similar characters substring
        int result = -1;
        
        for(int row = 0; row < 26; row++) {

            int cumSum = 0;

            // Traversing from right to left till 1th len col
            for(int col = n; col >= 1; col--) {

                cumSum += mat[row][col];

                // Here cumSum is frequency of substring
                if(cumSum >= 3) {
                    // Here col will be the length of the substring
                    result = Math.max(result, col);
                    // break because we're coming from right so substring length is already greater
                    break;
                }
            }
        }

        return result;
    }
}