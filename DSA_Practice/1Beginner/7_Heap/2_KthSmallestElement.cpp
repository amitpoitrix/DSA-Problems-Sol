#include<bits/stdc++.h>
using namespace std;

// Kth smallest element
// https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1

class Solution{
public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        // For Kth smallest element we'll make use of Max Heap
        priority_queue<int> maxH;
        
        for(int i = l; i <= r; i++){
            maxH.push(arr[i]);
            // Maintaing minHeap of size k
            if(maxH.size() > k)
                maxH.pop();
        }
        
        return maxH.top();
    }
};
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}