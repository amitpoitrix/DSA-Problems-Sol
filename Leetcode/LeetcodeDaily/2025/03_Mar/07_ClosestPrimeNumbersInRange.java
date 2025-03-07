/**
 * 2523. Closest Prime Numbers in Range
 * Link: https://leetcode.com/problems/closest-prime-numbers-in-range/description/?envType=daily-question&envId=2025-03-07
 * 
 * Approach 1:
 * 
 * Complexity:
 * Time: O(n * sqrt(n))
 * Space: O(1)
 */

class Solution1 {
    public int[] closestPrimes(int left, int right) {
        int[] result = new int[2];
        Arrays.fill(result, -1);

        int minDiff = Integer.MAX_VALUE;
        int lastPrime = 0;

        for(int num = left; num <= right; num++) {
            if(isPrime(num)) {
                if(result[0] == -1) {
                    result[0] = num;
                } else if(result[1] == -1){
                    result[1] = num;

                    minDiff = result[1] - result[0];
                } else {
                    if(num - lastPrime < minDiff) {
                        result[0] = lastPrime;
                        result[1] = num;

                        minDiff = num - lastPrime;
                    }
                }

                lastPrime = num;
            }
        }

        return minDiff == Integer.MAX_VALUE ? new int[]{-1, -1}: result;
    }

    // finction to check whether given num is prime or not
    private boolean isPrime(int num) {
        if(num < 2) {
            return false;
        }

        for(int i = 2; i * i <= num; i++) {
            if(num % i == 0) {
                return false;
            }
        }

        return true;
    }
}


/**
 * Approach 2:
 * This method uses the Sieve of Eratosthenes to precompute prime numbers up to the given range. 
 * It then extracts primes within the given bounds and finds the closest prime pair by iterating through the list.
 * 
 * Complexity:
 * Time: O(n * log(log(n)))
 * Space: O(1)
 */

class Solution2 {
    public int[] closestPrimes(int left, int right) {
        // Approach 2: Using Sieve of Eratosthenes
        // First get all the prime no. in list and than traverse over it to find the minDiff 
        
        // Function to give list of prime numbers from left to right
        // O(n * log(log(n)))
        ArrayList<Integer> prime = sieveOfEratosthenes(left, right);

        int[] result = new int[2];

        if(prime.size() < 2) {
            return new int[]{-1, -1};
        }

        int minDiff = Integer.MAX_VALUE;

        for(int i = 1; i < prime.size(); i++) {
            int first = prime.get(i - 1);
            int second = prime.get(i);

            // Optimization: Early Release
            if(second - first <= 2) {
                return new int[] {first, second};
            }
            else if(second - first < minDiff) {
                minDiff = second - first;

                result[0] = first;
                result[1] = second;
            }
        }

        return result;
    }
    
    // function to find list of prime numbers from [left, right] using Sieve of Eratosthenes
    private ArrayList<Integer> sieveOfEratosthenes(int left, int right){
	    // Step 1: Create a boolean array of size (N + 1) & marking all ith element as true 
	    // & taking care of edge cases
        boolean[] isPrime = new boolean[right + 1];
        Arrays.fill(isPrime, true);
        
        // Edge case: Numbers less than 2 are not prime
        isPrime[0] = false;
        isPrime[1] = false;
        
        // Step 2: looping till sqrt(n) and if ith element is prime than marking its factor as false till <= N
        for(int i = 2; i * i <= right; i++) {
            // if current ith element is prime than marking its factor as false
            if(isPrime[i] == true) {
                
                for(int j = 2; i * j <= right; j++) {
                    isPrime[i * j] = false;
                }
            }
        }
	       
	    // Step 3: Now storing only prime numbers in resultant list from [left, right]
        ArrayList<Integer> result = new ArrayList<>();
        
        for(int i = left; i <= right; i++) {
            if(isPrime[i]) {
                result.add(i);
            }
        }
        
        return result;
    }
}