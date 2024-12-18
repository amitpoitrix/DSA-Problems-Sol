/**
 * 1792. Maximum Average Pass Ratio
 * Link: https://leetcode.com/problems/maximum-average-pass-ratio/description/?envType=daily-question&envId=2024-12-15
 * 
 * 
 * Approach 1: Brute Force Approach (TLE)
 * Logic: 
 * For every extra student, iterate over all classes to calculate the potential improvement (delta) in the pass ratio 
 * for each class. 
 * Select the class with the maximum delta and assign the student.
 * 
 * Complexity:
 * Time: O(extraStudents * n), For each of the extraStudents, an O(n) operation is performed to find the class with the maximum delta.
 * Space: O(n), Requires space for storing the current pass ratios (PR) and the updated pass ratios (updatedPR).
 * 
 * Drawbacks: This approach is computationally expensive and may lead to Memory Limit Exceeded (MLE) for large inputs 
 * due to recalculating all deltas repeatedly for each student.
 * 
 * Use Case: Not suitable for large datasets due to inefficiency in handling multiple iterations.
 */

class Solution1 {
    public double maxAverageRatio(int[][] classes, int extraStudents) {
        int n = classes.length;

        while(extraStudents-- > 0) {
            int idx = 0;
            double maxDelta = 0.0;

            for(int i = 0; i < n; i++) {
                double currentPassRatio = (double)(classes[i][0]) / classes[i][1];
                double updatedPassRatio = (double)(classes[i][0] + 1) / (classes[i][1] + 1);

                if(updatedPassRatio - currentPassRatio > maxDelta) {
                    maxDelta = updatedPassRatio - currentPassRatio;
                    idx = i;
                }
            }

            // Assigning extra student to the class having max delta
            classes[idx][0]++;
            classes[idx][1]++;
        }

        double result = 0.0;
        for(int i = 0; i < n; i++) {
            result += (double)(classes[i][0]) / classes[i][1];
        }

        return result / n;
    }
}


/**
 * Approach 2: Optimised: Using maxHeap
 * Logic: 
 * Use a max-heap (priority queue) to efficiently keep track of the class with the maximum delta. 
 * For each extra student, extract the class with the maximum delta, update its pass ratio, and reinsert it into the 
 * heap with the recalculated delta.
 * 
 * Complexity:
 * Time: O(extraStudents * log(n))
 * Space: O(n), The max-heap stores n elements, one for each class.
 */

class Solution2 {
    public double maxAverageRatio(int[][] classes, int extraStudents) {
        int n = classes.length;

        Queue<Pair> maxHeap = new PriorityQueue<>(
            new Comparator<Pair> () {
                @Override
                public int compare(Pair p1, Pair p2) {
                    return Double.compare(p2.delta, p1.delta);
                }
            }
        );

        for(int i = 0; i < n; i++) {
            // Note: Instead of Integer divison do double divison by first converting numerator to double and than divide
            double currentPassRatio = (double)(classes[i][0]) / classes[i][1];
            double updatedPassRatio = (double)(classes[i][0] + 1) / (classes[i][1] + 1);

            // Storing delta in maxHeap
            maxHeap.offer(new Pair(updatedPassRatio - currentPassRatio, i));
        }

        while(extraStudents-- > 0) {
            Pair p = maxHeap.poll();

            classes[p.idx][0]++;
            classes[p.idx][1]++;

            // Updating maxHeap with new delta after addition of extraStudent
            double currentPassRatio = (double) (classes[p.idx][0]) / classes[p.idx][1];
            double updatedPassRatio = (double) (classes[p.idx][0] + 1) / (classes[p.idx][1] + 1);

            maxHeap.offer(new Pair(updatedPassRatio - currentPassRatio, p.idx));
        }

        double result = 0.0;
        for(int i = 0; i < n; i++) {
            result += (double) (classes[i][0]) / classes[i][1];
        }

        return result / n;
    }

    static class Pair {
        double delta;
        int idx;

        Pair(double delta, int idx) {
            this.delta = delta;
            this.idx = idx;
        }
    }
}