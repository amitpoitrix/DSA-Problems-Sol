#include<iostream>
#include<stack>
#include<queue>
using namespace std;

// Lt: 232. Implement Queue using Stacks
// https://leetcode.com/problems/implement-queue-using-stacks/

// Approach 1 : Using two Stacks
class MyQueue {
public:
    stack<int>s1, s2;
    
    MyQueue() {}
    
    void push(int x) {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        
        s1.push(x);
        
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int ans = s1.top();
        s1.pop();
        return ans;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

// Approach 2 : Using One Stack and another Function call stack
class MyQueue {
public:
    stack<int>s1, s2;
    
    MyQueue() {}
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int ans = 0;
        if(!s2.empty()){
            ans = s2.top();
            s2.pop();
            return ans;
        }
        // If s2 is empty
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        
        ans = s2.top();
        s2.pop();
        return ans;
    }
    
    int peek() {
        if(!s2.empty()) return s2.top();
        // If s2 is empty
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        
        return s2.top();
    }
    
    bool empty() {        
        if(s1.empty() && s2.empty()) return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main(){
    return 0;
}