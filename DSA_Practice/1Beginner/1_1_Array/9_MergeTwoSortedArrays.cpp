#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
// Striver SDE Sheet - Day2-Array-Part2
// GFG - Merge Without Extra Space

// BruteForce Approach - Taking extra space
// TC - O(n + m) + O(n + m)
// SC - O(n + m)
class Solution{
public:
    void merge(long long arr1[], long long arr2[], int n, int m) { 
        long long arr3[n + m];
        int k = 0;
        // First inserting the element from arr1 & arr2 to arr3
        for (int i = 0; i <= n - 1; i++){
            arr3[k++] = arr1[i];
        }
        
        for (int j = 0; j <= m - 1; j++){
            arr3[k++] = arr2[j];
        }

        // Sorting arr3
        sort(arr3, arr3 + n + m);

        // Again inserting back elements from arr3 back to arr1 & arr2
        k = 0;
        for (int i = 0; i <= n - 1; i++){
            arr1[i] = arr3[k++];
        }
        
        for (int j = 0; j <= m - 1; j++){
            arr2[j] = arr3[k++];
        }
        
    } 
};


// 1st Approach - without space - We'll traverse normally in arr1 and if found > first element of arr2 than we'll swap it and 
// sort the arr2 ... and repeat the same process of comparing and swapping till reaches end of arr1 
// TC - O(n * m)
// SC - O(1)
// Getting TLE
class Solution1{
public:
    void merge(long long arr1[], long long arr2[], int n, int m) {
        for (int i = 0; i < n; i++){
            // Swap only when arr1[i] contains greater element than arr2[0]
            if(arr1[i] > arr2[0]){
                swap(arr1[i], arr2[0]);
            }

            // Now sorting the arr2 using insertion sort
            int first = arr2[0];
            int j;
            for (j = 1; j < m && first > arr2[j]; j++){
                arr2[j - 1] = arr2[j];
            }
            arr2[j - 1] = first;
        }
    }
};


// Most Optimized Approach - Without Space - GAP METHOD
// Works using two nested while loop & 2 pointers which are at distance of Gap(i.e., ceil((n+m)/2)) from each other
// TC - O((n * m)log(n + m))
// SC - O(1)
class Solution2{
public:
    void merge(vector<int>& arr1, int m, vector<int>& arr2, int n) {
        // First we'll take all the elements of arr2 in arr1 if any
        for(int i = 0; i < n; i++){
            arr1[i + m] = arr2[i];
        }
        
        // Calculating gap which is ceil of (arr1(length) + arr2(length)) / 2
        int gap = ceil((float)(n + m) / 2);

        // Traversing till gap becomes 0
        while (gap > 0){
            // Taking 2 pointers
            int i = 0;
            int j = gap;

            // Nested while loop till j is less than or equal to (n+m)-1
            while (j < (n + m)){
                if(arr1[i] > arr1[j]){
                    swap(arr1[i], arr1[j]);
                }
                i++;
                j++;
            }
            
            // Checking if current gap(which is of float type) is 1 than 
            // break out else reduce gap as gap/2
            if(gap == 1)
                break;
            else
                gap = ceil((float)gap / 2);
        }
    }
};


int main(){
    return 0;
}