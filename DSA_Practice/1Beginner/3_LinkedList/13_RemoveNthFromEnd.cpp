#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// TC - O(n)
// SC - O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * dummy = new ListNode(-1);
        dummy->next = head;
        ListNode * fast = dummy;
        ListNode * slow = dummy;
        
        for(int i = 1; i <= n; i++){
            fast = fast->next;
        }
        
        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        
        ListNode * second = slow->next;
        slow->next = slow->next->next;
        delete second;
        
        return dummy->next;
    }
};

int main(){
    return 0;
}

