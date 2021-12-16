#include <iostream>

// Heap Data Structure or Priority Queue
// Implemention of Max Binary Heap using Vector

#define N 100

class PriorityQueue{
private:
    // Creating Array of size 100
    int A[N];

    // current size of array
    int size = 0;

    // returns parent of A[i]
    int PARENT(int i){
        return (i - 1) / 2 ;
    }
    // return left child of A[i]
    int LEFT(int i){
        return (2*i + 1);
    }
    // return right child of A[i]
    int RIGHT(int i){
        return (2*i + 2);
    }

    // Maintain heap property during POP() & while swapping root with last element & moving A[i] from top to bottom
    void heapify_down(int i){
        int left = LEFT(i);
        int right = RIGHT(i);

        int largest = i;

        if(left < size && A[left] > A[largest]){
            largest = left;
        }

        if(right < size && A[right] > A[largest]){
            largest = right;
        }

        if(largest != i){
            std::swap(A[i], A[largest]);
            heapify_down(largest);
        }
    }

    // Maintain heap property while PUSH A[i] & move it from bottom to top (Recursive)  TC- O(logN), SC - O(logN)
    void heapify_up(int i){
        int parent = PARENT(i);
        // Here i should not be the root node
        if(i > 0 && A[parent] < A[i]){
            std::swap(A[parent], A[i]);
            heapify_up(parent);
        }
    }

    // heapify_up without recursion TC - O(logN), SC - O(1)
    void heapify_up2(int i){
        while (i > 0 && A[(i - 1) / 2] < A[i]){
            std::swap(A[(i - 1) / 2], A[i]);
            i = (i-1)/2;
        }
    }

public:
    // No. of elements in heap
    int heapSize(){
        return size;
    }

    // Function to check if heap is empty
    bool empty(){
        return size == 0;
    }

    // Function to insert the new key element in the heap
    void push(int key){
        if(size == N)
            std::cout << "Heap Overflow" << "\n";

        int idx = size;
        A[idx] = key;   // Inserting element at last pos of Array
        heapify_up(idx);
        size++;
    }

    // Remove the max element from heap
    void pop(){
        if(empty())
            std::cout << "Heap underflow";

        A[0] = A[size - 1];   // Copy the last element to front
        size--;   // and than remove the last element by reducing size by 1
        heapify_down(0);    // calling heapify() in order to maintain heap property
    }

    // Returning the top element
    int top(){
        if(empty())
            return -1;

        return A[0];
    }        

};

int main(){
    PriorityQueue pq;
    pq.push(2);
    pq.push(20);
    pq.push(12);
    pq.push(23);

    std::cout << pq.heapSize() << "\n";
    std::cout << pq.top() << "\n";
    pq.pop();

    return 0;
}