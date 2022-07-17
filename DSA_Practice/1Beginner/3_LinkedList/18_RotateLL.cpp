#include<iostream>
using namespace std;

// Lt: 61. Rotate List
// https://leetcode.com/problems/rotate-list/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0)
            return head;
        
        int cnt = 1;
        ListNode * temp = head;
        while(temp->next != NULL){
            cnt++;
            temp = temp->next;
        }
        
        k = k % cnt;    // What if k >= cnt
        // if k becomes 0 than no rotation required
        if(k == 0)
            return head;
        
        temp->next = head;
        k = cnt - k;
        ListNode * dummy = head;
        int inc = k-1;
        while(inc--){
            dummy = dummy->next;
        }
        
        head = dummy->next;
        dummy->next = NULL;
        
        return head;
    }
};

int main(){
    return 0;
}