#include<iostream>
using namespace std;

// Lt: 141. Linked List Cycle
// https://leetcode.com/problems/linked-list-cycle/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return false;
        
        ListNode * fast = head;
        ListNode * slow = head;
        
        while(fast->next != NULL && fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
                return true;
        }
        
        return false;
    }
};

int main(){
    return 0;
}