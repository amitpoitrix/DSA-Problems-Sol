Recursion Problems

1. [Reverse String](https://leetcode.com/problems/reverse-string/description/)

**Approach:** Using Recursion

```java
class Solution {
    public void reverseString(char[] s) {
        reverse(0, s.length, s);
    }

    private void reverse(int i, int n, char[] s) {
        // Base Case
        if(i >= n / 2)
            return;

        // swap
        char temp = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = temp;

        reverse(i + 1, n, s);
    }
}
```

1. https://www.geeksforgeeks.org/problems/reverse-a-stack/1

**Approach 1:** Using Auxiliary Space

The function uses recursion to reverse the stack, pushing the top element to the bottom during each recursive call. 

After reversing the stack, the method creates a temporary stack (temp) to hold the reversed elements temporarily. Then, it pushes the top element back to the original stack, effectively placing it at the bottom, and finally, it pushes the remaining elements from the temporary stack back to the original stack, resulting in a reversed order of elements in the original stack.

**Time Complexity:** O(n)

**Auxiliary Space Complexity:** O(n)

```java
class Solution { 
    static void reverse(Stack<Integer> st) {
        // Base Case
        if(st.isEmpty()) {
            return;
        }
        
        // Recursive Step
        int top = st.pop();
        
        reverse(st);
        
        // This will take auxiliary space of O(n)
        Stack<Integer> temp = new Stack<>();
        while(!st.isEmpty()) {
            temp.push(st.pop());
        }
        
        st.push(top);
        
        while(!temp.isEmpty()) {
            st.push(temp.pop());
        }
    }
}
```

**Approach 2:** Without any Auxiliary Space

In this approach, we use two methods: insertAtBottom and Reverse. 

The insertAtBottom method is designed to insert an element at the bottom of a given stack. If the stack is empty, it simply pushes the provided element onto the stack; otherwise, it recursively pops the top element, calls itself with the remaining stack, and then pushes the popped element back on top. 

This recursive process effectively inserts the specified element at the bottom of the stack. The Reverse method, on the other hand, aims to reverse the order of elements in a given stack. It first checks if the stack is empty and returns if it is. Then, it pops the top element, recursively calls itself to reverse the remaining stack, and utilizes the insertAtBottom method to insert the popped element at the bottom of the reversed stack. This combination of recursion and the insertAtBottom operation results in the reversal of the original stack.

**Time Complexity:** O(n)

**Auxiliary Space Complexity:** O(1)

```java
class Solution { 
    static void reverse(Stack<Integer> st) {
        // Base Case
        if(st.isEmpty()) {
            return;
        }
        
        // Recursive Step
        int top = st.pop();
        
        reverse(st);
        
        insertAtBottom(st, top);
    }
    
    // Helper function which makes use of recursion to insert element at bottom
    private static void insertAtBottom(Stack<Integer> st, int element) {
        // Base Case
        if(st.isEmpty()) {
            // Now we add our element as stack is empty
            st.push(element);
            return;
        }
        
        int top = st.pop();
        
        insertAtBottom(st, element);
        
        st.push(top);
    }
}
```

1. https://www.geeksforgeeks.org/problems/tower-of-hanoi-1587115621/1

**Approach:** Using Recursion

![alt text](https://prod-files-secure.s3.us-west-2.amazonaws.com/6ccccabc-9cb5-4b96-a8d1-60cdb356c5a8/3dbc44ac-3465-40dd-a7d5-1cb035b64be9/image.png)

So if we have to move N disks from from_rod to to_rod than we’ll follow below steps:

1. first we’ll move **smallest disk (1)** from **from_rod** to **to_rod**.
2. Than **middle disk (2)** from **from_rod** to **aux_rod**
3. Than **smallest disk (1)** from **to_rod** to **aux_rod**
4. Now we’ll move **largest disk (2)** from **from_rod** to **to_rod**
5. Than **smallest disk (1)** from **aux_rod** to **from_rod**
6. Than **middle disk (2)** from **aux_rod** to **to_rod**
7. And than finally **smallest disk (1)** from **from_rod** to **to_rod**

In this total 7 steps (which is minimum) steps it took to move all the disks from from_rod to to_rod

![image.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/6ccccabc-9cb5-4b96-a8d1-60cdb356c5a8/2e4fb7db-9a48-46f9-8123-c8b9cbc5ff29/image.png)

**Story from Diagram: Just 2 lines of code**

1. Now Step No. 1,2 & 3 can be interpret as **moving** **(n-1) disks** from **from_rod** to **aux_rod** represented by 1st recursive call **using to_rod**
2. Step 4 can be interpret as **just moving disk** from **from_rod** to **to_rod** represented by 2nd line of code
3. Step 5,6 & 7 can be interpret as **moving rest (n-1) disks** from **aux_rod** to **to_rod** in 2nd recursive call **using from_rod**

![image.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/6ccccabc-9cb5-4b96-a8d1-60cdb356c5a8/f74dc98e-7636-477d-bcaf-b1e1adfc2983/image.png)

**Approach Summary:**

1. The Tower of Hanoi problem involves moving a stack of n disks from one rod to another, using a third rod as an auxiliary, such that no larger disk is placed on top of a smaller one during the process. 
2. The toh method takes four parameters: n (number of disks), from (source rod), to (destination rod), and aux (auxiliary rod). 
3. The function recursively solves the Tower of Hanoi problem, printing the steps to move each disk from the source rod to the destination rod. 
4. The count of total moves is returned. 
5. The base case is when n is 1, in which case it directly moves the disk and returns 1. Otherwise, it recursively solves the problem for n-1 disks, prints the move for the current disk, and then again recursively solves the problem for n-1 disks on the auxiliary rod. 
6. The total count of moves is calculated and returned.

**Time Complexity:** O(2^n)

**Space Complexity:** O(n)

```java
class Hanoi {
    public long toh(int n, int from, int to, int aux) {
        // Base Case
        if(n == 1) {
            System.out.println("move disk " + n + " from rod " + from + " to rod " + to);
            return 1;   
        }
        
        // Recursive Process
        // 1st Recursive Call
        long count = toh(n - 1, from, aux, to);
        
        // Here we're just moving our nth disk from source(from_rod) to destination(to_rod)
        System.out.println("move disk " + n + " from rod " + from + " to rod " + to);
        count++;
        
        // 2nd Recursive Call
        count += toh(n - 1, aux, to, from);
        
        return count;
    }
}
```

1. https://www.geeksforgeeks.org/problems/merge-sort/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

**Approach:** Using Recursion

1. Divide among into 2 parts
2. Get both parts sorted via recursion
3. Merge the sorted parts

**Summary:**

1. In the code, there are two public methods: **merge** and **mergeSort**. 
2. The **mergeSort** method performs the merge sort on the array arr in the specified range [l, r]. It recursively divides the array into halves until individual elements are reached and then merges them back in a sorted manner using the merge method. This algorithm follows the divide-and-conquer approach, where the array is continuously divided into smaller segments until the base case is reached (single-element arrays), and then the sorted segments are merged to produce the final sorted array. The mergeSort method serves as the entry point for sorting an entire array.
3. The **merge** method takes an array arr and three indices l, m, and r, and it merges two sorted subarrays within the array, one from index l to m and the other from index m+1 to r, in ascending order. 

**Time Complexity:** O(nlogn)

**Space Complexity:** O(n); // because o=f Auxiliary Space taken

```java
class Solution {
    void mergeSort(int arr[], int l, int r) {
        // Base Case: When there is only 1 element
        if(l == r) {
            return;
        }
        
        // Step 1: finding mid
        int mid = l + (r - l) / 2;
        
        // Step 2: breaking them into two parts recursively
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        
        // Step 3: merging them back in sorted manner
        merge(arr, l, mid, r);
    }
    
    void merge(int[] arr, int l, int m, int r) {
        int n1 = m - l + 1; // arr1 -> [l, m]
        int n2 = r - m; // (r - (m + 1) - 1) arr2 -> [(m + 1), r]
        
        // Now I'll create length of size n1 & n2
        int[] arr1 = new int[n1];
        int[] arr2 = new int[n2];
        
        // Now we'll blindly insert elements in arr1 & arr2
        int k = l;
        int i = 0;
        while(i < n1) {
            arr1[i] = arr[k];
            i++; 
            k++;
        }
        
        int j = 0;
        while(j < n2) {
            arr2[j] = arr[k];
            j++; 
            k++;
        }
        
        // Now populating original array with sorted elements from arr1 & arr2
        i = 0; j = 0; k = l;
        while(i < n1 && j < n2) {
            if(arr1[i] <= arr2[j]) {
                arr[k] = arr1[i];
                i++;
            } else {
                arr[k] = arr2[j];
                j++;
            }
            
            k++;
        }
        
        // Now rest of the elements
        while(i < n1) {
            arr[k] = arr1[i];
            i++;
            k++;
        }
        
        while(j < n2) {
            arr[k] = arr2[j];
            j++;
            k++;
        }
    }
}
```

1. https://www.geeksforgeeks.org/problems/quick-sort/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

**Approach:** Using Recursion

The algorithm works by selecting a "pivot" element from the array and partitioning the other elements into two sub-arrays based on whether they are less than or greater than the pivot. In this way atleast pivot element is placed in its correct position

This process is then applied recursively to the sub-arrays. 

The key to QuickSort's efficiency lies in its ability to sort small partitions independently and in-place, minimizing the need for additional memory. 

While QuickSort has excellent average-case performance, its worst-case time complexity can be O(n^2) if the pivot selection consistently results in unbalanced partitions. 

To mitigate this, various techniques such as randomized pivot selection are often employed. Overall, QuickSort is a versatile and efficient sorting algorithm, widely used in practice for its speed and simplicity.

**Time Complexity:**

1. **Best & Avg Case:** O(nlogn)
2. **Worst Case:** O(n^2); // when partition element idx is always the first of subarrays

**Space Complexity:** O(1); // No auxiliary space

```java
class Solution {
    //Function to sort an array using quick sort algorithm.
    static void quickSort(int arr[], int low, int high) {
        // Base Case: When there is 1 element or no element at all
        if(low >= high) {
            return;
        }
        
        // finding partitionIndex i.e., pIdx
        int pIdx = partition(arr, low, high);
        
        // Now based on partition index we're going to divide arrays
        quickSort(arr, low, pIdx - 1);
        quickSort(arr, pIdx + 1, high);
    }
    
    static int partition(int arr[], int low, int high) {
        // Step 1: Choose the pivot element i.e., mostly the last one
        int pivotElement = arr[high];
        
        // Step 2: Now based on this pivotElement we're going to move elements
        // to either right or left
        
        // Here pivotIdx is possible idx of pivot element, after finding its value
        // we'll place pivotElement at its correct sorted idx i.e., pivotIdx
        int pivotIdx = low;
        for(int i = low; **i < high**; i++) {
            // not equal to high as we already consider it as pivotElement
            if(arr[i] <= pivotElement) {
                swap(i, pivotIdx, arr);
                pivotIdx++;
            }
        }
        
        // Now placing pivotElement at its correct idx
        swap(pivotIdx, high, arr);
        
        return pivotIdx;
    }
    
    static void swap(int first, int second, int[] arr) {
        int temp = arr[first];
        arr[first] = arr[second];
        arr[second] = temp;
    }
}

```

1. https://www.geeksforgeeks.org/problems/flatten-bst-to-sorted-list--111950/1
    
    **Approach Summary:**
    
    - The function takes a binary search tree (BST) node root as input and flattens it into a linked list in ascending order.
    - The function recursively traverses the BST, flattening the left and right subtrees and then connecting them appropriately.
    - The linked list is constructed by modifying the left and right pointers of the BST nodes.
    - The resulting linked list is returned with the head node pointing to the smallest value in the original BST.
    
    **Time Complexity:** O(N)
    
    **Space Complexity:** O(H), where H is the height of BST
    
    **Similar Questions:**
    
    1. BST Flatten to Doubly Linked List
    2. Nested list to simple sorted list
    
    ```java
    class Solution {
        public Node flattenBST(Node root) {
            // Base Case
            if(root == null)
                return root;
            
            // Recursive Flow
            Node left = flattenBST(root.left); // trust
            root.left = null;
            Node right = flattenBST(root.right); // trust
            
            // Moving temp pointer to extreme right
            if(left != null) {
                Node temp = left;
                
                while(temp.right != null) {
                    temp = temp.right;
                }
                
                temp.right = root;
            }
            
            root.right = right;
            
            // if left is null than root will be the smallest element
            if(left == null)
                return root;
                
            return left;
        }
    }
    ```
    
2. https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1
    
    **Approach:** Using Recursion
    
    1. The provided code implements a function to merge two linked lists in sorted order, and another function to flatten a linked list of linked lists. 
    2. The mergeTwoLists function takes two sorted linked lists (head1 and head2) and merges them into a single sorted linked list. It uses a recursive approach, comparing the nodes of the input lists and merging them accordingly. 
    3. The flatten function is designed to flatten a linked list of linked lists. It recursively flattens the remaining linked lists after the current one (temp) and then merges the current linked list (head) with the flattened result using the mergeTwoLists function. 
    4. The final result is a single sorted linked list containing all the elements from the original linked lists. 
    5. Overall, this code demonstrates a recursive approach to merge sorted linked lists and flatten a linked list of linked lists while maintaining the sorted order.
    
    **Time Complexity:** O(N * M); // Assuming each node have M size bottom linked list
    
    **Space Complexity:** O(N)
    
    ```java
    class Solution {
        // Function to flatten a linked list
        Node flatten(Node root) {
            // Base Case
            if(root == null)
                return root;
                
            // Recursive Code
            Node flattenSortedList = flatten(root.next); // trust
            
            return mergeSortedList(root, flattenSortedList);
        }
        
        // Standard Question: To merge 2 sorted linked list
        // Note: Instead of next we'll use bottom pointer acc. to question
        Node mergeSortedList(Node l1, Node l2) {
            // Base Case
            if(l1 == null)
                return l2;
                
            if(l2 == null)
                return l1;
                
            // Recursive Code
            Node result = null;
            
            if(l1.data < l2.data) {
                result = l1;
                result.bottom = mergeSortedList(l1.bottom, l2);
            } else {
                result = l2;
                result.bottom = mergeSortedList(l1, l2.bottom);
            }
            
            return result;
        }
    }
    ```
    

1. https://leetcode.com/problems/generate-parentheses/description/
    
    **Approach 1:** Using Simple Recursion
    
    **When in ques, if it asks for:**
    
    Generate All possible → Combinations, Permutations, subsets etc than always think of using **Backtracking** (which is nothing but recursion).
    
    ![image.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/6ccccabc-9cb5-4b96-a8d1-60cdb356c5a8/55326c01-c430-40dd-9b87-8a3afb494ca2/image.png)
    
    **Basic Backtracking Template:**
    
    - Do something
    - explore - recursion
    - undo
    
    - Do something
    - explore - recursion
    - undo
    
    ![image.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/6ccccabc-9cb5-4b96-a8d1-60cdb356c5a8/2c4468ea-0edc-4e1f-afae-6199365dccc5/image.png)
    
    **Smart way of checking parentheses is valid or not instead of using stack**
    
    ![image.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/6ccccabc-9cb5-4b96-a8d1-60cdb356c5a8/fbe0507a-317d-4979-b632-066079fb080b/image.png)
    
    Using **count** variable (+1 for open bracket & -1 for close bracket) and if sum is 0 parentheses is valid.
    
    But above approach will fail for below example:
    
    (    )   )   (
    
    1 -1 -1 +1
    
    So for this we can avoid it when count becomes -ve we return false means invalid.
    
    **Steps:**
    
    1. This approach uses a recursive function to generate all possible combinations of parentheses.
    2. The isValid function checks whether a given combination is valid or not by maintaining a balance of open and close parentheses.
    3. The main recursive function (generate) explores all possibilities by adding an open parenthesis and a close parenthesis in each recursive call.
    
    **Complexity:**
    
    **Time:** O(2n* (2^(2n)) - Removing constant - O(n * (2^n))
    
    **Space:** O(2*n) - Removing constant - O(n * (2^n)) - recursion stack space - Max depth of recursion tree
    
    ```java
    class Solution {
        public List<String> generateParenthesis(int n) {
            // Approach 1: Using Simple Recursion(or Backtracking)
            List<String> result = new ArrayList<>();
            StringBuilder sb = new StringBuilder();
    
            solve(sb, n, result);
    
            return result;
        }
    
        private void solve(StringBuilder current, int n, List<String> result) {
            // Base Case
            if(current.length() == 2 * n) {
                if(isValidParentheses(current.toString())) {
                    result.add(current.toString());
                }
                
                return;
            }
    
            // Now I've 2 options:
            // 1st: Considering open bracket "(" and exploring further
            current.append("(");
            solve(current, n, result);
            current.deleteCharAt(current.length() - 1);   // undo
    
            // 2nd: Considering close bracket ")" and exploring further
            current.append(")");
            solve(current, n, result);
            current.deleteCharAt(current.length() - 1);   // undo
        }
    		
    		// Smart way of finding valid parentheses
        private boolean isValidParentheses(String str) {
            int count = 0;
    
            for(char ch: str.toCharArray()) {
                if(ch == '(') {
                    count++;
                } else {
                    count--;
                }
    
                // Edge Case: if count becomes -ve than its invalid
                if(count < 0)
                    return false;
            }
    
            return count == 0;
        }
    }
    ```
    
    **Approach 2:** Using Smart Recursion
    
    1. This approach also uses a recursive function, but it is optimized to generate only valid combinations.
    2. The generateAll function explores possibilities by only adding an open parenthesis when the count of open parentheses is less than n and adding a close parenthesis when the count of close parentheses is less than the count of open parentheses.
    3. This approach avoids generating invalid combinations, reducing the overall time complexity.
    
    **Complexity:**
    
    **Time:** O(2^n)
    
    **Space:** O(2*n) - Removing constant - O(n * (2^n)) - recursion stack space - Max depth of recusion tree
    
    ```java
    class Solution {
        public List<String> generateParenthesis(int n) {
            // Approach 2: Using Smart Recursion(or Backtracking)
            List<String> result = new ArrayList<>();
            StringBuilder sb = new StringBuilder();
    
            solve(sb, n, result, 0, 0);
    
            return result;
        }
    
        private void solve(StringBuilder current, int n, List<String> result, int open, int close) {
            // Base Case: Always valid
            if(current.length() == 2 * n) {
                // checking with 2 * n as n pairs were given
                result.add(current.toString());
    
                return;
            }
    
            // Now I've 2 options:
            // 1st: Considering open bracket "(" and exploring further
            **if(open < n)** {
                current.append("(");
                solve(current, n, result, open + 1, close);
                current.deleteCharAt(current.length() - 1);   // undo
            }
    
            // 2nd: Considering close bracket ")" and exploring further
            **if(close < open)** {
                current.append(")");
                solve(current, n, result, open, close + 1);
                current.deleteCharAt(current.length() - 1);   // undo
            }
        }
    }
    ```
    
2. https://leetcode.com/problems/valid-palindrome/description/

```java
class Solution {
    public boolean isPalindrome(String s) {
        String resultantString = removeAlphaNumeric(s.toLowerCase());

        return checkPalindrome(0, resultantString.length(), resultantString);
    }

    private String removeAlphaNumeric(String s) {
        StringBuilder result = new StringBuilder();

        for(char ch: s.toCharArray()) {
            // Considering only AlphaNumeric
            if((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) {
                result.append(ch);
            }
        }

        return result.toString();
    }
		
		// Checking Palindrome using recursion
    private boolean checkPalindrome(int i, int n, String resultantString) {
        // Base Case
        if(i >= n / 2)
            return true;

        if(resultantString.charAt(i) != resultantString.charAt(n - i - 1))
            return false;

        return checkPalindrome(i + 1, n, resultantString);
    }
}
```

1. **Count Zeroes**

**Approach:** Using Recursion

- **function argument decision:** As we’ve to **count** so we’ll pass the count variable as argument while calling the function along with number **nums**
- **Return Type:** As function needs to return total zero count so we’ll return count (int)
- **Body:** if nums % 10 is 0 than increment the count.
- Now if we want to return count from our function just return it when you hit **base condition.** And normally just call recursive function at the end i.e.,
    
    **return** recursiveFunction(nums, count);
    
- **Base Condition:** if nums is 0 means nums doesn’t exist anymore so **return count** (i.e., count so far)

```java
public class CountZeroes {
    public static void main(String[] args) {
        System.out.println("Count num of zeroes");
        int count = 0;
        int result = countZeroes(2000, count);
        System.out.println(result);
    }

    private static int countZeroes(int n, int count) {
        // base condition
        if(n <= 0)
            return count;

        if(n % 10 == 0)
            count++;

        return countZeroes(n/10, count);
    }
}
```

1. https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/

```java
public class NoOfStepsToReduceToZero {
    public static void main(String[] args) {
        System.out.println("Number of steps to reduce a no to zero");
        System.out.println(reduceNoToZero(123, 0));
    }

    private static int reduceNoToZero(int n, int count) {
        // base condition
        if(n == 0)
            return count;

        if((n & 1) == 1)
            return reduceNoToZero(n-1, count + 1);
        return reduceNoToZero(n / 2, count + 1);
    }
}
```

1. **Find all Permutations of a given string?**
- **Permutation:** Rearranging
- **Total no. of Permutations** for String of size n is **n! (n factorial)**
    - eg: “abc” ⇒ [abc], [acb], [bac], [bca], [cab], [cba] ⇒ 6
    - 3! = 3 * 2 = 6
- Here, you will observe in recursion tree that no. of recursive calls is being increased at each step(i.e., variable no. of recursive calls) that means no. of recursive call depends on size of processed string
    - i.e., No. of recursive call at each step = size of processed string + 1

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/6ccccabc-9cb5-4b96-a8d1-60cdb356c5a8/891b3966-b6e7-40b8-8b91-e2a568c25a70/Untitled.png)

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/6ccccabc-9cb5-4b96-a8d1-60cdb356c5a8/d30a469d-2c57-48c9-8328-8bc6c26ebde9/Untitled.png)

```java
import java.util.ArrayList;

public class Permutations {
    public static void main(String[] args) {
        System.out.println("All Permutations of a String");

        printAllPermutations("", "abc");

        System.out.println(permutationsInArrayRet("", "abc"));

        ArrayList<String> result = new ArrayList<>();
        permutationsInArray("", "abc", result);
        System.out.println(result);

        System.out.println(countTotalPermutations("", "abc"));
    }

    private static void printAllPermutations(String p, String up){
        // Base Condition
        if(up.isEmpty()) {
            System.out.println(p);
            return;
        }

        char ch = up.charAt(0);

        // As here we've variable no. of recursive calls
        // here we'll call (processed string length + 1) times
        for (int i = 0; i <= p.length(); i++) {
            String f = p.substring(0, i);   // [0, i) -> exclusive
            String s = p.substring(i);  // [i, p.length())
            printAllPermutations(f + ch + s, up.substring(1));
        }
    }

    private static ArrayList<String> permutationsInArrayRet(String p, String up){
        // Base Condition
        if(up.isEmpty()) {
            ArrayList<String> ans = new ArrayList<>();
            ans.add(p);
            return ans;
        }

        ArrayList<String> res = new ArrayList<>();  // To store the result from each recursive call
        char ch = up.charAt(0);

        for (int i = 0; i <= p.length(); i++) {
            String f = p.substring(0, i);   // [0, i) -> exclusive
            String s = p.substring(i);  // [i, p.length())
            res.addAll(permutationsInArrayRet(f + ch + s, up.substring(1)));
        }

        return res;
    }

    private static void permutationsInArray(String p, String up, ArrayList<String> result){
        // Base Condition
        if(up.isEmpty()) {
            result.add(p);
            return;
        }

        char ch = up.charAt(0);

        for (int i = 0; i <= p.length(); i++) {
            String f = p.substring(0, i);   // [0, i) -> exclusive
            String s = p.substring(i);  // [i, p.length())
            permutationsInArray(f + ch + s, up.substring(1), result);
        }
    }

    private static int countTotalPermutations(String p, String up) {
        // Base Condition
        if(up.isEmpty()){
            return 1;   // i.e., Found 1 permutations when hit base condition
        }

        int count = 0;
        char ch = up.charAt(0);
        for (int i = 0; i <= p.length(); i++) {
            String f = p.substring(0, i);
            String s = p.substring(i);

            count += countTotalPermutations(f + ch + s, up.substring(1));
        }

        return count;
    }
}
```

1. **How many no. of ways are there to form target on a dice ?**

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/6ccccabc-9cb5-4b96-a8d1-60cdb356c5a8/4de31c77-30a9-4fbe-b43a-aaf30d492872/Untitled.png)

```java
import java.util.ArrayList;

public class DiceRollTarget {
    public static void main(String[] args) {
        System.out.println("Number of Dice Rolls With Target Sum");
        int target = 3;
        printDifferentDiceCombination("", target);

        ArrayList<String> result = new ArrayList<>();
        returnDifferentDiceCombinationWithFaces("", 3, 6, result);
        System.out.println(result);

        System.out.println(countDifferentDiceCombination(3));
    }

    private static void printDifferentDiceCombination(String p, int target) {
        // Base Condition
        if(target == 0){
            System.out.println(p);
            return;
        }

        for (int i = 1; i <= 6 && i <= target ; i++) {
            printDifferentDiceCombination(p + i, target - i);
        }
    }

    private static void returnDifferentDiceCombinationWithFaces(String p, int target, int face, ArrayList<String> result) {
        // Base Condition
        if(target == 0){
            result.add(p);
            return;
        }

        for (int i = 1; i <= face && i <= target ; i++) {
            returnDifferentDiceCombinationWithFaces(p + i, target - i, face, result);
        }
    }

    private static int countDifferentDiceCombination(int target) {
        // Base Condition
        if(target == 0){
            return 1;
        }

        int count = 0;

        for (int i = 1; i <= 6 && i <= target ; i++) {
            count += countDifferentDiceCombination(target - i);
        }

        return count;
    }
}
```

1. **Finding All Paths from A → B in a Matrix**
    - Counting Paths - Moving Right & Down only
    
    ![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/6ccccabc-9cb5-4b96-a8d1-60cdb356c5a8/5e8c74af-72f8-4ba6-b788-a39918a60e63/Untitled.png)
    

```java
public class CountingPaths {
    public static void main(String[] args) {
        System.out.println("Finding All Paths in a matrix");
        System.out.println(countPaths(3, 3));   // rows = 3, col = 3
    }

    // Count paths when you only have to move Right or Down
    private static int countPaths(int row, int col) {
        // Base Condition
        if(row == 1 || col == 1) {
						// Just hit the matrix boundary first and we count it as one path
            return 1;
        }

        // Moving Right
        int right = countPaths(row, col - 1);
        // Moving Down
        int down = countPaths(row - 1, col);

        return right + down;
    }
}
```

- Printing Paths - Moving Right & Down only

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/6ccccabc-9cb5-4b96-a8d1-60cdb356c5a8/6cffc938-b796-4fb1-903a-02851861c848/Untitled.png)

```java
		// Here we're starting from (3,3)	
 		private static void printingPaths(String p, int row, int col) {
        // Base Condition
        if(row == 1 && col == 1) {
            System.out.println(p);
            return;
        }

        // Moving Right
        if(col > 1)
            printingPaths(p + 'R', row, col - 1);

        // Moving Down
        if(row > 1)
            printingPaths(p + 'D', row - 1, col);
    }

    private static void pathsInArray(String p, int row, int col, ArrayList<String> result) {
        // Base Condition
        if(row == 1 && col == 1) {
            result.add(p);
            return;
        }

        // Moving Right
        if(col > 1)
            pathsInArray(p + 'R', row, col - 1, result);

        // Moving Down
        if(row > 1)
            pathsInArray(p + 'D', row - 1, col, result);
    }

    private static ArrayList<String> pathsInArrayReturn(String p, int row, int col) {
        // Base Condition
        if(row == 1 && col == 1) {
            ArrayList<String> list = new ArrayList<>();
            list.add(p);
            return list;
        }

        ArrayList<String> result = new ArrayList<>();

        // Moving Right
        if(col > 1)
            result.addAll(pathsInArrayReturn(p + 'R', row, col - 1));

        // Moving Down
        if(row > 1)
            result.addAll(pathsInArrayReturn(p + 'D', row - 1, col));

        return result;
    }
```

- Printing Paths - Moving Vertical, Horizontal & Diagonal

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/6ccccabc-9cb5-4b96-a8d1-60cdb356c5a8/f62691cc-4b44-4a26-8ff6-aefb031de328/Untitled.png)

```java
    private static void printingDiagonalPaths(String p, int row, int col) {
        // Base Condition
        if(row == 1 && col == 1) {
            System.out.println(p);
            return;
        }

        // Moving Diagonal
        if(col > 1 && row > 1)
            printingDiagonalPaths(p + 'D', row - 1, col - 1);

        // Moving Horizontally
        if(col > 1)
            printingDiagonalPaths(p + 'H', row, col - 1);

        // Moving Vertically
        if(row > 1)
            printingDiagonalPaths(p + 'V', row - 1, col);
    }
```

1. **Maze with Obstacles**
    
    ![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/6ccccabc-9cb5-4b96-a8d1-60cdb356c5a8/8ff836dc-035a-4fba-9075-b6efdf356765/Untitled.png)
    
    ![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/6ccccabc-9cb5-4b96-a8d1-60cdb356c5a8/421b8100-40de-479f-9b95-34724ad1bd2b/Untitled.png)
    
    ```java
    public class MazePathsWithObstacles {
        public static void main(String[] args) {
            System.out.println("Maze Paths with Obstacles");
    
            boolean[][] maze = {
                    {true, true, true},
                    {true, false, true},
                    {true, true, true},
            };
    	
    				// Here we're starting from (0,0)
            mazePathsWithObstacles("", 0, 0, maze);
        }
    
        private static void mazePathsWithObstacles(String p, int row, int col, boolean[][] maze) {
            // Base Condition
            if(row == maze.length - 1 && col == maze[0].length - 1) {
                System.out.println(p);
                return;
            }
    
            // If there is obstacle than just return
            if(!maze[row][col])
                return;
    
            // Moving Right
            if(col < maze.length - 1)
                mazePathsWithObstacles(p + 'R', row, col + 1, maze);
    
            // Moving Down
            if(row < maze[0].length - 1)
                mazePathsWithObstacles(p + 'D', row + 1, col, maze);
        }
    }
    ```
    

1. https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
    
    ![IMG_3239.jpeg](https://prod-files-secure.s3.us-west-2.amazonaws.com/6ccccabc-9cb5-4b96-a8d1-60cdb356c5a8/4468b0fb-27c9-4e7d-a5c9-bcc08527697b/IMG_3239.jpeg)
    
    **Time Complexity:** O(4^d), As for each digit in the input, the function makes recursive calls for each corresponding letter. If there are “d" digits and each digit can map to up to 4 letters (e.g., '7' and '9' map to 4 letters), the number of combinations is 4^d
    
    **Space Complexity:** O(d * 4^d)
    
    ```java
    class Solution {
        public List<String> letterCombinations(String digits) {
            String[] alpha = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
            List<String> result = new ArrayList<>();
            
            if(digits.isEmpty())
                return result;
    
            findCombinations(Integer.parseInt(digits), "", result, alpha);
    
            return result;
        }
    
        private void findCombinations(int num, String substring, List<String> result, String[] alpha) {
            // Base Case
            if(num == 0) {
                result.add(substring);
                return;
            }
    
            int current = num % 10;
            
            String currentAlpha = alpha[current - 2];
    
            for(char ch: currentAlpha.toCharArray()) {
                findCombinations(num / 10, ch + substring, result, alpha);
            }
        }
    }
    ```
    

1. https://leetcode.com/problems/regular-expression-matching/description/
    
    **Approach 1:** Using Recursion (using substring)
    
    - The solution uses recursion to check if a given text matches a pattern with wildcard characters **‘.' and '*'**.
    - It handles base cases, matches the first character, and deals with '' by exploring two possibilities
    
    ![image.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/6ccccabc-9cb5-4b96-a8d1-60cdb356c5a8/61cd3bb6-42ee-486e-b491-033d1968e32a/image.png)
    

**Recursive Tree Diagram for Regular Expression Matching:**

![image.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/6ccccabc-9cb5-4b96-a8d1-60cdb356c5a8/3c4d1c82-fc0c-479d-ab50-4ca172608f2b/image.png)

![image.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/6ccccabc-9cb5-4b96-a8d1-60cdb356c5a8/9a84a3ca-8e84-4ab9-a26e-e1d1d9ba496c/image.png)

**Complexity:**

**Time:** O(2^(n + m)); Exponential and n is the length of input string & m is the length of pattern string

**Space:** O(n + m); where n is the length of the input string & m is the length of pattern string

```java
class Solution {
    public boolean isMatch(String s, String p) {
        return solve(s, p);
    }

    private boolean solve(String s, String p) {
        // Base case
        if(p.length() == 0) {
            return s.length() == 0;
        }

        // Recursive Case
        boolean firstCharChecked = false;
        
        if(s.length() > 0 && (s.charAt(0) == p.charAt(0) || p.charAt(0) == '.')) {
            firstCharChecked = true;
        }

        if(p.length() > 1 && p.charAt(1) == '*') {
            // means 2nd character (1st idx) is '*', so either we can take it or ignore it
            
            // nonPick: we pass the input string sb as it is but pattern string should skip 1st 2 characters
            boolean nonPick = **solve(s, p.substring(2));**
            
            // pick: when we're considering than we're shifting by just 1 position from input string but 
            // pattern should be remain as it is as it might match with future input string
            boolean pick = firstCharChecked == false ? false: **(firstCharChecked && solve(s.substring(1), p));**

            return nonPick || pick;
        } else {
            // means there is no '*'
            return firstCharChecked == false ? false: **(firstCharChecked && solve(s.substring(1), p.substring(1)));**
        }
    }
}
```

**Approach 2:** Using Recursion (with pointers instead of substring)

**Complexity:**

**Time:** O(2^(n + m)); Exponential and n is the length of input string & m is the length of pattern string

**Space:** O(n + m); where n is the length of the input string & m is the length of pattern string

```java
class Solution {
    public boolean isMatch(String s, String p) {
        // Approach 2: Using pointer instead of using substring
        return solve(0, 0, s, p);
    }

    private boolean solve(int i, int j, String s, String p) {
        // Base case
        if(j == p.length()) {
            return i == s.length();
        }

        // Recursive Case
        boolean firstCharChecked = false;
        **if(i < s.length() && (s.charAt(i) == p.charAt(j) || p.charAt(j) == '.'))** {
            firstCharChecked = true;
        }

        **if(j + 1 < p.length() && p.charAt(j + 1) == '*')** {
            // means 2nd character (1st idx) is '*', so either we can take it or ignore it
            
            // nonPick: we pass the input string s as it is but pattern string should skip 1st 2 characters
            boolean nonPick = **solve(i, j + 2, s, p);**
            
            // pick: when we're considering '<ch> *' than we're shifting by just 1 position from input string 
            // but pattern should be remain as it is as it might match with future input string
            boolean pick = firstCharChecked == false ? false: **(firstCharChecked && solve(i + 1, j, s, p));**

            return nonPick || pick;
        } else {
            // means there is no '*', so shift by just 1 position in both the string
            return firstCharChecked == false ? false: **(firstCharChecked && solve(i + 1, j + 1, s, p));**
        }
    }
}
```

**Approach 3:** Using DP (Memoization)

**Complexity:**

**Time:** O(n * m)

**Space:** O(n * m)

```java
class Solution {
    public boolean isMatch(String s, String p) {
        // Approach 2: Using pointer instead of using substring
        int[][] dp = new int[21][21];
        for(int[] row: dp) {
            Arrays.fill(row, -1);
        }

        return solve(0, 0, s, p, dp);
    }

    private boolean solve(int i, int j, String s, String p, int[][] dp) {
        // Base case
        if(j == p.length()) {
            return i == s.length();
        }

        if(dp[i][j] != -1) {
            return dp[i][j] == 1 ? true: false;
        }

        // Recursive Case
        boolean firstCharChecked = false;
        if(i < s.length() && (s.charAt(i) == p.charAt(j) || p.charAt(j) == '.')) {
            firstCharChecked = true;
        }

        if(j + 1 < p.length() && p.charAt(j + 1) == '*') {
            // means 2nd character (1st idx) is '*', so either we can take it or ignore it

            // nonPick: we pass the input string sb as it is but pattern string should skip 1st 2 characters
            boolean nonPick = **solve(i, j + 2, s, p, dp);**

            // pick: when we're considering than we're shifting by just 1 position from input string but 
            // pattern should be remain as it is as it might match with future input string
            boolean pick = firstCharChecked == false ? false: **(firstCharChecked && solve(i + 1, j, s, p, dp));**

            dp[i][j] = nonPick == true || pick == true ? 1: 0;
            return nonPick || pick;
        } else {
            // means there is no '*'
            boolean pick = firstCharChecked == false ? false: **(firstCharChecked && solve(i + 1, j + 1, s, p, dp));**

            dp[i][j] = pick == true ? 1: 0;
            return pick;
        }
    }
}
```