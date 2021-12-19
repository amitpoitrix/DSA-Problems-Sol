#include<iostream>
#include<vector>
#include<queue>
// Leetcode 23. Merge k Sorted Lists

// Linked List Node structure
struct Node{
    int data;
    Node * next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

// Method 1 : Using Min heap TC - O(NlogK), SC - O(K)
class Solution {
private:
    // compare struct for min_heap as it contains Node
    struct compare{
        bool operator()(const Node* l, const Node* r){
            return l->data > r->data;
        }
    };
public:
    Node* mergeKLists(std::vector<Node*>& lists) {
        if(lists.empty())
            return NULL;

        // Creating Min Heap with compare function
        std::priority_queue<Node*, std::vector<Node*>, compare> min_heap;
        
        // First we'll insert the starting node of each K Linked List
        for (auto l : lists){
            if(l)
                min_heap.push(l);
        }

        // If vector contains the head pointers of K list and all list are pointing to NULL
        if(min_heap.empty())
            return NULL;

        // Creating return Node
        Node * result = min_heap.top();
        min_heap.pop();
        if(result->next)
            min_heap.push(result->next);
        
        Node * curr = result;   // As curr will be traverse so giving pointer to curr from result
        
        while (!min_heap.empty()){
            curr->next = min_heap.top();
            min_heap.pop();

            curr = curr->next;
            if(curr->next)
                min_heap.push(curr->next);
        }
        
        return result;
    }
};


// Method 2 : Using Divide & Conquer TC - O(NlogK), SC - O(1)
class Solution2{
private:
    Node * mergeTwoLists(Node* l1, Node* l2){
        if(l1 == NULL)
            return l2;
        else if(l2 == NULL)
            return l1;
        else{
            if(l1->data <= l2->data){
                l1->next = mergeTwoLists(l1->next, l2);
                return l1;
            }
            else{
                l2->next = mergeTwoLists(l1, l2->next);
                return l2;
            }
        }
    }
public:
    Node* mergeKLists(std::vector<Node*>& lists) {
        if(lists.empty())
            return NULL;
        
        int k = lists.size();

        while (k > 1){
            for (int i = 0; i < k/2; i++){
                lists[i] = mergeTwoLists(lists[i], lists[k - 1 - i]);
            }
            k = (k + 1)/2;
        }

        return lists.front();
    }
};


// Display Linked List
void printList(Node* head){
    while (head != NULL) {
        std::cout << head->data << " ";
        head = head->next;
    }
}
  
// Driver code
int main(){
    int k = 3;
    std::vector<Node*> list(k);
  
    // Creating k = 3 sorted lists
    list[0] = new Node(1);
    list[0]->next = new Node(3);
    list[0]->next->next = new Node(5);
    list[0]->next->next->next = new Node(7);
  
    list[1] = new Node(2);
    list[1]->next = new Node(4);
    list[1]->next->next = new Node(6);
    list[1]->next->next->next = new Node(8);
  
    list[2] = new Node(0);
    list[2]->next = new Node(9);
    list[2]->next->next = new Node(10);
    list[2]->next->next->next = new Node(11);
  
    // Merge the k sorted lists
    Solution2 s;
    Node* head = s.mergeKLists(list);
  
    // Print the merged list
    printList(head);
  
    return 0;
}