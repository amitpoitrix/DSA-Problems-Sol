/*
 * 2064. Minimized Maximum of Products Distributed to Any Store
 * Link: https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/description/?envType=daily-question&envId=2024-11-14
 * 
 * Approach: Binary Search on Answer
 * 
 * As quantity is given for different kind of products that needs to be distributed among n shops so we'll try to 
 * find the optimal quantity (i.e., x) whose value range from [1, Max(quantities)] and once we found the value we'll
 * try to minimise it using Binary Search on answer
 * 
 * Complexity:
 * Time: O(mlogm); where m is the no. of quantities
 * Space: O(1)
 * 
 * Note: Alternative to Math.ceil(a / b) is (a + b - 1) / b
 */

class Solution {
    public int minimizedMaximum(int n, int[] quantities) {
        // Approach: Using Binary Search on Answer

        // Step 1: Define the range based on amount of product being distributed to each store of same product type
        int left = 1;   // min: 1 as a quantity we can give it to any store
        int right = 0;  // max: Max(quantities) we can give to any store
        for(int quantity: quantities) {
            right = Math.max(right, quantity);
        }

        // Step 2: Once you find the possible value (i.e., x) that needs to be given to each shop by considering all products we'll try to minimise it
        
        int result = 0; // Don't depend on left & right always try to use result
        
        while(left <= right) {
            int mid = left + (right - left) / 2; // possible x

            if(isPossible(mid, quantities, n)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }

    private boolean isPossible(int mid, int[] quantities, int shops) {
        // Now here we'll check whether quantity of similar kind of product being distributed to different shops is sufficient enough or not
        for(int quantity: quantities) {
            // no. of shops going to get similar kind of products
            
            // shops -= Math.ceil(quantity / mid); // this will not give correct quantity
            shops -= (quantity + mid - 1) / mid;

            if(shops < 0) {
                // means if shops are not sufficient enough that means quantity of similar kind of product has been wrongly distributed
                return false;
            }
        }

        return true;
    }
}