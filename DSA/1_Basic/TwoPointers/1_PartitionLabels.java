/**
 * 763. Partition Labels
 * Link: https://leetcode.com/problems/partition-labels/description/?envType=daily-question&envId=2025-03-30
 * 
 * Approach 1:
 * As we've to make as much partition as we can so the approach is to first store the last position of each character 
 * in map and than use 2 pointers to manage the first and last position of partition string
 * 2nd pointer will keep on moving starting from 1st one till end pointer where end pointer is the last position of 
 * 2nd pointer character
 * So when 2nd pointer matches with end pointer than we got our partition with size as 2nd pointer - 1st pointer + 1
 * 
 * Complexity:
 * Time: O(n)
 * Space: O(1)
 */

class Solution {
    public List<Integer> partitionLabels(String s) {
        Map<Character, Integer> map = new HashMap<>();

        int n = s.length();

        for(int i = 0; i < n; i++) {
            char ch = s.charAt(i);
            map.put(ch, i);
        }

        List<Integer> result = new ArrayList<>();

        int i = 0;
        int j = i;
        int end = map.get(s.charAt(i));

        while(i < n) {
            end = Math.max(end, map.get(s.charAt(j)));

            if(j == end) {
                result.add(j - i + 1);
                i = j + 1;
            }

            j++;
        }

        return result;
    }
}