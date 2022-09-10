#include <iostream>
using namespace std;

void turne(int *arr1, int *arr2){
    int temp = *arr1;
    *arr1 = *arr2;
    *arr2 = temp;
}

bool UniqueNumberOccurrence(int arr[], int n){
    for (int i = 0; i < n; i++){
        if (i+1 < n && arr[i] > arr[i + 1]){
            turne(&arr[i], &arr[i + 1]);
        }
    }
    int array[n];
    int i = 0, k = 0;
    while (i < n){
        int count = 0;
        for (int j = i + 1; j < n; j++){
            if (array[i] = array[j]){
                count++;
            }
            array[k] = count;
            k++;
            i = i + count;
        }
        turne(&array[i], &array[i + 1]);
        for (int i = 0; i < sizeof(array)/sizeof(array[0]) - 1; i++){
            if (array[i] == array[i+1])
                return false;
        }
    }
    return true;
}

int main(){
    int size, a[size];
    cout << "Enter the size of array";
    cin >> size;

    cout << "Enter array values  ";
    for (int i = 0; i < size; i++){
        cin >> a[i];
    }
    cout << "Enter values are  ";

    for (int i = 0; i < size; i++){
        cout << a[i] << " ";
    }

    cout << UniqueNumberOccurrence(a, size);

    return 0;
}