#include<iostream>
using namespace std;

// 25. Reverse Nodes in k-Group
// https://leetcode.com/problems/reverse-nodes-in-k-group/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Approach 1:
// TC - O(n)
// SC - O(n)
class Solution {
private:
    void reverse(ListNode * start, ListNode * end){
        ListNode * prev = NULL;
        ListNode * curr = start;
        
        while(prev != end){
            ListNode * nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
    }
    
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Base Case
        if(head == NULL || head->next == NULL || k == 1)
            return head;
        
        ListNode * start = head;
        ListNode * end = head;
        
        // Move end k-1 times
        int dec = k-1;
        while(dec--){
            end = end->next;
            // if k > n, though it is mention in ques that k <= n but 
            // we're using this function as recursion 
            if(end == NULL)
                return head;
        }
        
        // Recursive call to reverse next kth size group
        ListNode * nextHead = reverseKGroup(end->next, k);
        // Reversing the 1st group of size k
        reverse(start, end);
        // As of now start & end pointer are reverse so pointing start->next to newHead
        start->next = nextHead;
        
        return end;
    }
};

// Approach 2:
// TC - O(n)
// SC - O(1)
class Solution {
private:
    void reverse(ListNode * start, ListNode * end){
        ListNode * prev = NULL;
        ListNode * curr = start;
        
        while(prev != end){
            ListNode * nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
    }
    
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 1)
            return head;
        
        ListNode * dummy = new ListNode(-1);
        dummy->next = head;    
        ListNode * beforeStart = dummy;
        ListNode * end = head;
        
        int i = 0;
        while(end != NULL){
            i++;
            if(i % k == 0){
                // calling reverse() to reverse k-size nodes
                ListNode * start = beforeStart->next;
                ListNode * temp = end->next;
                reverse(start, end);
                // Making Connections
                beforeStart->next = end;
                start->next = temp;
                // Now shifting 2 pointers
                beforeStart = start;    
                end = temp;
            }
            else
                end = end->next;
        }
        return dummy->next;
    }
};

int main(){
    return 0;
}