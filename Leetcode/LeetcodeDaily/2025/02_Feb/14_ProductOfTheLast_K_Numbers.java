/**
 * 1352. Product of the Last K Numbers
 * Link: https://leetcode.com/problems/product-of-the-last-k-numbers/description/?envType=daily-question&envId=2025-02-14
 * 
 * Approach 1: Using Brute force Approach
 * 
 * Complexity:
 * Time: O(n)
 * Space: O(n)
 */

class ProductOfNumbers1 {
    List<Integer> stream;

    public ProductOfNumbers() {
        stream = new ArrayList<>();
    }
    
    public void add(int num) {
        stream.add(num);
    }
    
    public int getProduct(int k) {
        int n = stream.size();

        int product = 1;

        for(int i = n - 1; i >= 0 && k > 0; i--, k--) {
            product *= stream.get(i);
        }

        return product;
    }
}


/**
 * Approach 2: Optimised Approach
 * The second approach optimizes this by maintaining a cumulative product list. 
 * Instead of recalculating the product each time, it leverages division to retrieve the product in constant time. 
 * However, handling zeroes requires resetting the list, as division is not possible with them.
 * 
 * Diagram
 * https://github.com/user-attachments/assets/bd7aec56-93b0-4f4e-a381-b8922cdb04a1
 * 
 * Complexity:
 * Time: O(1)
 * Space: O(1)
 */

class ProductOfNumbers2 {
    // Step 1: Taking cumulative product instead of normal list of numbers
    List<Integer> cumulativeProduct;

    public ProductOfNumbers() {
        cumulativeProduct = new ArrayList<>();
    }
    
    public void add(int num) {
        if(cumulativeProduct.isEmpty()) {
            // Edge Case 1: When list is empty and num is 0 than skip
            if(num == 0) {
                return;
            }
            cumulativeProduct.add(num);
        } else {
            // Edge Case 2: when given no. is 0 than make entire cumulativeProduct list empty
            if(num == 0) {
                cumulativeProduct = new ArrayList<>();
            } else {
                // computing cumulative product and adding in the end
                int product = num * cumulativeProduct.get(cumulativeProduct.size() - 1);
                cumulativeProduct.add(product);
            }
        }
    }
    
    public int getProduct(int k) {
        int n = cumulativeProduct.size();

        if(n < k) {
            // means we've deleted previous record because of 0
            return 0;
        } else if(n == k) {
            // means we've to find the product of whole elements
            return cumulativeProduct.get(n - 1);
        } else {
            // means n is greater than k so we've to divide whole number's product with (n-k-1) elements from starting
            return cumulativeProduct.get(n - 1) / cumulativeProduct.get(n - k - 1);
        }
    }
}

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers obj = new ProductOfNumbers();
 * obj.add(num);
 * int param_2 = obj.getProduct(k);
 */

// 0 1 2 3 4
// 3 0 2 5 4

// cumulative sum
// 3 0 - if encounter 0 than make list empty
//     2 10 40

// now to find product of last k numbers

// if(n < k) {
//     return 0;   as this means we've remove 0 elements from list
// } else if(n == k) {
//     return product[n-1];    means whole elements product
// } else {
//     product[n - 1] / product[n - k - 1];
// }


// 0 1 2 3 4
// 3 0 0 8 3