#include <iostream>
using namespace std;
// Leetcode(medium) - 75 : Sort Colors

// Sort the array containg only 0s 1s & 2s element without sort function 
// Logic : will trace the mid pointer i.e., a[mid] starting from 0 till n-1 and it'll replace the element with a[low] & a[high] and both will increment
// when mid encounter 1 than we do nothing just mid++
// when mid encounter 2 swap with higher element and reduce high-- and mid will remain unchange as after swap mid still have unprocessed element
void sort012(int *a, int n){
    int low = 0;
    int mid = 0;
    int high = n-1;
    while (mid<=high){
        switch (a[mid]){
        case 0:
            swap(a[low++], a[mid++]);   
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(a[mid], a[high--]);
            break;
        }
    }
}

int main(){
    int a[] = {1,2,0,2,0,1,2,0,1,2,2,2,1,1,1,0};
    int n = sizeof(a)/sizeof(int);
    sort012(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}