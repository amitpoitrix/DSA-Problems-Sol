#include<iostream>
#include<vector>

// Heap Sort having TC - O(NlogN) which is upgradation over Selection Sort but slower than Merge sort & quick Sort

class HeapSort{
private:
    int LEFT(int i){
        return (2*i + 1);
    }

    int RIGHT(int i){
        return (2*i + 2);
    }

    // Max Heap Recursive Heapify_down - TC - O(logN)
    void heapify_down(std::vector<int> &A, int i, int size){
        int left = LEFT(i);
        int right = RIGHT(i);

        int largest = i;

        if(left < size && A[left] > A[largest])
            largest = left;
        
        if(right < size && A[right] > A[largest])
            largest = right;
        
        if(largest != i){
            std::swap(A[i], A[largest]);
            heapify_down(A, largest, size);
        }
    }

public:
    void heapSort(std::vector<int> &A, int size){
        // Step 1 : Build a Heap - TC - O(N)
        // As Heap internal Nodes lie from 0 to (n/2) - 1
        for (int i = (size/2) - 1; i >= 0; i--){
            heapify_down(A, i, size);
        }

        // Step2: Picking the Max element by swaping it with last element and call heapify with newly swapped element at root TC - O(NlogN)
        // Here we'll traverse from last element to 2nd element(i.e., 1st Index as 0th index will already be sorted)
        for (int i = size - 1; i > 0; i--){
            std::swap(A[0], A[i]);
            heapify_down(A, 0, i);  // Here i represent size of heap till we have to heapify_down
        }
    }
};

int main(){
    std::vector<int> A = {7,4,9,2,6,4,1};
    int size = A.size();

    HeapSort hs;
    hs.heapSort(A, size);

    for (auto x : A){
        std::cout << x << " ";
    }
    
    return 0;
}