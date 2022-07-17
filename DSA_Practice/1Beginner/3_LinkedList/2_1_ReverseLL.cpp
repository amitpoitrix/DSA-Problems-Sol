#include<bits/stdc++.h>
using namespace std;

// Lt: 206. Reverse Linked List
// https://leetcode.com/problems/reverse-linked-list/

 // Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Iterative Approach
// TC - O(n)
// SC - O(n)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode * dummy = NULL;
        while(head != NULL){
            ListNode * nextptr = head->next;
            head->next = dummy;
            dummy = head;
            head = nextptr;
        }
        return dummy;
    }
};

// Recursive Approach
// TC - O(n)
// SC - O(1)
class Solution2{
public:
    ListNode* reverseList(ListNode* head) {
        // Base Case
        if(head == NULL || head->next == NULL)
            return head;
            
        ListNode * newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;

        return newHead;
    }
};

int main(){
    return 0;
}