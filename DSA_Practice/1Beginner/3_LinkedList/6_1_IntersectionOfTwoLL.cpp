#include<iostream>
using namespace std;

// Lt: 160. Intersection of Two Linked Lists
// https://leetcode.com/problems/intersection-of-two-linked-lists/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Approach 1:
// TC - O(2m)
// SC - O(1)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * d1 = headA;
        ListNode * d2 = headB;
        // Counting No. of nodes on each LL
        int cntA = 1, cntB = 1;
        while(d1 != NULL){
            d1 = d1->next;
            cntA++;
        }
        while(d2 != NULL){
            d2 = d2->next;
            cntB++;
        }
        
        // Getting the diff and moving larger LL till diff
        int diff = abs(cntA - cntB);
        d1 = headA;
        d2 = headB;
        for(int i = 1; i <= diff; i++){
            if(cntA > cntB)
                d1 = d1->next;
            else
                d2 = d2->next;
        }
        
        // Now moving both d1 & d2 till they are equal
        while(d1 != d2){
            d1 = d1->next;
            d2 = d2->next;
        }
        
        // If both encounter NULL than there is no intersection
        if(d1 == NULL && d2 == NULL)
            return NULL;
        return d1;
    }
};

// Approach 2
// TC - O(2m)
// SC - O(1)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)
            return NULL;
        
        ListNode * d1 = headA;
        ListNode * d2 = headB;
        
        while(d1 != d2){
            d1 = (d1 == NULL)? headB: d1->next;
            d2 = (d2 == NULL)? headA: d2->next;
        }
        
        return d1;
    }
};

int main(){
    return 0;
}