#include<iostream>
using namespace std;

// Lt: 234. Palindrome Linked List
// https://leetcode.com/problems/palindrome-linked-list/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    ListNode * reverseLL(ListNode * &head){
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode * newNode = reverseLL(head->next);
        head->next->next = head;
        head->next = NULL;
        return newNode;
    }
    
public:
    bool isPalindrome(ListNode* head) {
        ListNode * slow = head;
        ListNode * fast = head;
        
        while(fast->next != NULL && fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        slow->next = reverseLL(slow->next);
        
        slow = slow->next;
        ListNode * d = head;
        while(slow != NULL){
            if(d->val != slow->val)
                return false;
            d = d->next;
            slow = slow->next;
        }
        
        return true;
    }
};

int main(){
    return 0;
}