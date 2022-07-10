#include<bits/stdc++.h>
using namespace std;

// Lt: 155. Min Stack
// https://leetcode.com/problems/min-stack/

class MinStack {
public:
    stack<int> s, ss;
    
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(ss.size() == 0 || val <= ss.top())
            ss.push(val);
        return;
    }
    
    void pop() {
        int ans = s.top();
        s.pop();
        if(ss.top() == ans)
            ss.pop();
        return;
    }
    
    int top() {
        if(s.size() == 0)
            return -1;
        return s.top();
    }
    
    int getMin() {
        if(ss.size() == 0)
            return -1;
        return ss.top();
    }
};


// Approach 2 : Using O(1) Space Complexity
class MinStack {
private:
    stack<long> s;
    long minElement;
    
public:
    MinStack() {}
    
    void push(int val) {
        if(s.size() == 0){
            s.push((long)val);
            minElement = (long)val;
        }
        
        else{
            if((long)val < minElement){
                s.push(2 * (long)val - minElement);
                minElement = (long)val;
            }
            else
                s.push((long)val);
        }
    }
    
    void pop() {        
        if(s.top() >= minElement) s.pop();
        else{
            minElement = 2 * minElement - s.top();
            s.pop();
        }
    }
    
    int top() {
        if(s.size() == 0) return -1;
        else if(s.top() >= minElement) return s.top();
        else return (int)minElement;
    }
    
    int getMin() {
        if(s.size() == 0) return -1;
        return (int)minElement;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(){
    return 0;
}