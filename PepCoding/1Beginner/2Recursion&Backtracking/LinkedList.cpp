#include <iostream>
#include "list.h"
using namespace std;
// Linked List - Coding Minutes

int main(){
    List l;
    l.push_front(1);
    l.push_front(0);
    l.push_back(3);
    l.push_back(4);
    l.insert(2,2);
    l.insert(10,0);
    l.pop_front();
    l.pop_back();
    l.remove(1);

    // Printing the Linked List
    Node * head = l.begin();
    while (head != nullptr){
        cout << head->getData() << "->";
        head = head->next;
    }

    cout << endl;

    int key;
    cin >> key;

    // cout << l.search(key) << endl;
    cout << l.recursiveSearch(key);

    cout << endl;
    return 0;
}