#include<iostream>
using namespace std;
// Merge two Linked List - Time Complexity - O(n+m)

class Node{
public:
    int data;
    Node * next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

// INSERT
void InsertAtTail(Node * &head, int data){
    Node * n = new Node(data);
    // If Linked List is empty
    if(head == NULL){
        head = n;
        return;
    }

    // Traverse till end node
    Node * temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }

    temp->next = n;
}

// DISPLAY
// Here we pass value of head as we are just printing the Linked List
void display(Node * head){
    Node * temp = head;
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// MERGE of Two Linked List
// 1. Iterative way
Node * mergeLL(Node * &head1, Node * &head2){
    Node * ptr1 = head1;
    Node * ptr2 = head2;
    // we'll create a dummyNode - After which merge sorted linked list starts and its not a pointer its a node
    Node * dummyNode = new Node(-1);
    Node * ptr3 = dummyNode;

    while (ptr1 != NULL && ptr2 != NULL){
        if (ptr1->data < ptr2->data){
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }
        else{
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        ptr3 = ptr3->next;
    }

    while (ptr1 != NULL){
        ptr3->next = ptr1;
        ptr1 = ptr1->next;
        ptr3 = ptr3->next;
    }
    
    while (ptr2 != NULL){
        ptr3->next = ptr2;
        ptr2 = ptr2->next;
        ptr3 = ptr3->next;
    }

    return dummyNode->next;
}

// 2. Recursive way
Node * mergeRecursive(Node * &head1, Node * &head2){
    // base case - if any one of the Linked List is finish traversing return the another one which is left out
    if(head1 == NULL)
        return head2;

    if(head2 == NULL)
        return head1;  

    // rec case
    Node * result;
    if(head1->data < head2->data){
        result = head1;
        result->next = mergeRecursive(head1->next, head2);
    }
    else{
        result = head2;
        result->next = mergeRecursive(head1, head2->next);
    }

    return result;
}

// Approach 1: Using Extra space
// TC - O(n1 + n2)
// SC - O(n1 + n2)
class Solution {
public:
    Node* mergeTwoLists(Node* list1, Node* list2) {        
        if(list1 == NULL && list2 == NULL)
            return list1;
        else if(list1 == NULL && list2 != NULL)
            return list2;
        else if(list1 != NULL && list2 == NULL)
            return list1;
        
        Node * d = NULL;
        if(list1->data < list2->data){
            Node * n = new Node(list1->data);
            d = n;
            list1 = list1->next;
        }
        else{
            Node * n = new Node(list2->data);
            d = n;
            list2 = list2->next;
        }
        
        Node * dd = d;
        
        while(list1 != NULL && list2 != NULL){
            if(list1->data < list2->data){
                Node * n = new Node(list1->data);
                dd->next = n;
                dd = dd->next;
                list1 = list1->next;
            }
            else{
                Node * n = new Node(list2->data);
                dd->next = n;
                dd = dd->next;
                list2 = list2->next;
            }
        }
        
        while(list1 != NULL){
            Node * n = new Node(list1->data);
            dd->next = n;
            dd = dd->next;
            list1 = list1->next;
        }
        
        while(list2 != NULL){
            Node * n = new Node(list2->data);
            dd->next = n;
            dd = dd->next;
            list2 = list2->next;
        }
        
        return d;
    }
};

// Approach 2: Inplace Sorting
// TC - O(n1 + n2)
// SC - O(1)
class Solution2{
public:
    Node* mergeTwoLists(Node* list1, Node* list2) {
        if(list1 == NULL)
            return list2;
        else if(list2 == NULL)
            return list1;
        
        if(list1->data > list2->data)
            swap(list1, list2);
        
        Node * head = list1;
        
        while(list1 != NULL && list2 != NULL){
            Node * temp = NULL;
            while(list1 != NULL && list1->data <= list2->data){
                temp = list1;
                list1 = list1->next;
            }
            
            temp->next = list2;
            swap(list1, list2);
        }
        
        return head;
    }
};

int main(){
    Node * head1 = NULL;
    Node * head2 = NULL;

    int arr1[] = {1, 4, 5, 7};
    for (int i = 0; i < 4; i++){
        InsertAtTail(head1, arr1[i]);
    }
    display(head1);

    int arr2[] = {2, 3, 6};
    for (int i = 0; i < 3; i++){
        InsertAtTail(head2, arr2[i]);
    }
    display(head1);

    // Node * newMergeHead = mergeLL(head1, head2);
    Node * newMergeHead = mergeRecursive(head1, head2);

    display(newMergeHead);

    cout << endl;
    return 0;
}