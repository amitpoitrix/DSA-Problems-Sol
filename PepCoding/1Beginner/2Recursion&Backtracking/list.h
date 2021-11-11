#include <iostream>
using namespace std;
// Forward Declaration
// class List;

class Node{
    int data;

public:
    Node * next;
    // Initialize Node class data members 
    Node(int d):data(d), next(nullptr){}

    // as data is private data member so for read only purpose 
    int getData(){
        return data;
    }

    // Deleting entire Linked List... here this function will delete the Linked List node recursively
    ~Node(){
        if(next != nullptr){
            delete next;    // this will call next node till it finds NULL pointer and delete recursively from end
        }
        cout << "Deleting node with data " << data << endl;
    }

   // friend class List;
};


class List{
    // List class data members
    Node * head;
    Node * tail;

    // Recursive searchHelper()
    int searchHelper(Node * start, int key){
        // base case
        if(start == nullptr)
            return -1;
        // If key is the first element
        if(start->getData() == key)
            return 0;   // Here, 0 is the first index value
        
        // rec case
        int subIdx = searchHelper(start->next, key);

        if(subIdx == -1)
            return -1;
        return subIdx+1;
    }

public:
    // Initialize
    List():head(nullptr), tail(nullptr){}

    // Returning head
    Node * begin(){
        return head;
    }

    // Inserting node at front
    void push_front(int data){
        if(head == nullptr){
            Node * n = new Node(data);
            head = tail = n;
        }
        else{
            Node * n = new Node(data);
            n->next = head;
            head = n;
        }
    }

    // Inserting node at back
    void push_back(int data){
        if(head == nullptr){
            Node * n = new Node(data);
            head = tail = n;
        }
        else{
            Node * n = new Node(data);
            tail->next = n;
            tail = n;
        }
    }

    // Inserting node at particular position
    void insert(int data, int pos){
        // If pos is ) i.e., inserting node at front
        if(pos == 0){
            push_front(data);
            return;
        }

        // Now we have go to 1 step back of particular pos so jump required will be pos-1
        Node * temp = head;
        for (int jump = 1; jump <= pos-1; jump++){
            temp = temp->next;
        }

        // Now temp is 1 step back of pos
        Node * n = new Node(data);
        n->next = temp->next;
        temp->next = n;
    }

    // Searching an element in Linked List
    // We don't use Binary Search in Linked List as mid element will take O(n) time which is O(1) in case of array
    int search(int key){
        // for traversing we'll create a temp Node pointer
        Node * temp = head;
        int idx = 0;
        while (temp != nullptr){
            if(temp->getData() == key)
                return idx;
            idx++;
            temp = temp->next;
        }
        return -1;
    }

    // Recursive search
    int recursiveSearch(int key){
        int idx = searchHelper(head, key);
        return idx;
    }

    // Deleting the First Node
    void pop_front(){
        Node * temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
    }

    // Deleting the Last node
    void pop_back(){

    }

    // Deleting the node at a particular position
    void remove(int pos){

    }

    // Deleting entire Linked List - first under class List than in class Node
    ~List(){
        if(head != nullptr){
            delete head;    // Here After compiler reach this step it'll call the destructor ~Node()  
            head = nullptr; // After deleting entire node now we'll assign head to NULL
        }
    }
};