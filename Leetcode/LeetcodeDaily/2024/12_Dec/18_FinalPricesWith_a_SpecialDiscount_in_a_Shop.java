/**
 * 1475. Final Prices With a Special Discount in a Shop
 * Link: https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/description/?envType=daily-question&envId=2024-12-18
 * 
 * 
 * Approach: Brute Force Approach
 * This approach iterates through each price and checks subsequent prices to find the first one smaller or equal to 
 * the current price. 
 * When such a price is found, it is subtracted from the current price. 
 * This straightforward solution uses nested loops to calculate the final prices.
 * 
 * Complexity:
 * Time: O(n^2)
 * Space: O(1)
 */

class Solution1 {
    public int[] finalPrices(int[] prices) {
        // Brute Force Approach
        int n = prices.length;

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(prices[j] <= prices[i]) {
                    prices[i] -= prices[j];
                    break;
                }
            }
        }

        return prices;
    }
}


/**
 * Approach 2: Monotonic Stack
 * This approach uses a stack to efficiently find the first smaller or equal price for each element.
 * By maintaining a stack of indices in decreasing order of prices, it processes each element in a single pass. 
 * The stack helps track indices where discounts need to be applied, reducing redundant comparisons.
 * 
 * Complexity:
 * Time: O(n)
 * Space: O(n)
 */

class Solution2 {
    public int[] finalPrices(int[] prices) {
        // Monotonic Stack Approach
        int n = prices.length;

        int[] result = prices.clone();

        Stack<Integer> st = new Stack<>();

        for(int i = 0; i < n; i++) {
            while(!st.isEmpty() && result[i] <= result[st.peek()]) {
                result[st.peek()] -= result[i];
                st.pop();
            }

            st.push(i);
        }

        return result;
    }
}