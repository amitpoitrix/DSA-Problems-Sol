#include<iostream>
#include<queue>
// Leetcode 295. Find Median from Data Stream
// Using Heap Concept TC - O(NlogN), SC - O(N)

// Concept - First half will store in Max Heap and 2nd half is store in Min heap
// If n = odd than return MaxHeap.top() else (max + min)/2
class MedianFinder {
private:
    // Declaring min_heap & max_heap
    std::priority_queue<int> max_heap;
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        max_heap.push(num);
        min_heap.push(max_heap.top());
        max_heap.pop();
        // If Odd no. of elements that first half should be inserted with last num added
        if(min_heap.size() > max_heap.size()){
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    
    double findMedian() {
        if(max_heap.size() > min_heap.size())
            return max_heap.top();

        return (max_heap.top() + min_heap.top()) / 2.0;
    }
};

int main(){
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    std::cout << mf.findMedian() << "\n";
    mf.addNum(3);
    std::cout << mf.findMedian() << "\n";

    return 0;
}