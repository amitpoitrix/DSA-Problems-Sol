#include <iostream>
using namespace std;
// DSA450 Array Ques 4 & Striver SDE Sheet DAy 1 Ques 1

// Sorting the array containg only 0s 1s & 2s element without sort function using Simple method
void sort012(int *a, int n){
    // Take 3 variables that count the occurence of elements
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    // First for loop to count the no. of 0s, 1s & 2s
    for (int i = 0; i < n; i++){
        // if(a[i] == 0)
        //     count0++;
        // if(a[i] == 1)
        //     count1++;
        // if(a[i] == 2)
        //     count2++;
        switch (a[i])
        {
        case 0:
            count0++;
            break;

        case 1:
            count1++;
            break;
        
        case 2:
            count2++;
            break;
        }
    }

    // Traversing again to assign the value in correct position
    for (int i = 0; i < count0; i++)
        a[i] = 0;
    
    for (int i = count0; i < (count0 + count1); i++)
        a[i] = 1;

    for (int i = count0 + count1; i < n; i++)
        a[i] = 2;
    
}

int main(){
    int a[] = {1,2,0,2,0,1,2,0,1,2,2,2,1,1,1,0};
    int n = sizeof(a)/sizeof(int);
    sort012(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << endl;

    return 0;
}