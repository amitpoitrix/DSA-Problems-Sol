#include<iostream>
#include<queue>
using namespace std;
// Stack Implementation Using Queue

// Approach 1 : Stack Using two queues - TC - O(n) & SC - O(n)
class stack1{
    queue<int> q1;
    queue<int> q2;
public:
    // 1. PUSH Method of Stack
    void Push(int data){
        q2.push(data);

        while (!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        swap(q1, q2);
    }

    // 2. POP Method of stack
    void Pop(){
        q1.pop();
        return;
    }

    // 3. TOP Method of stack
    int Top(){
        return q1.front();
    }

    // 4. EMPTY Method of stack
    bool Empty(){
        return q1.size() == 0;
    }
};

// Approach 2 : Stack using single queue TC - O(n) & SC - O(n)
class stack2{
    queue<int> q1;
public:
    // 1. PUSH Method
    void Push(int data){
        q1.push(data);
        for (int i = 0; i < q1.size()-1; i++){
            q1.push(q1.front());
            q1.pop();
        }
    }

    // 2. POP Method of stack
    void Pop(){
        q1.pop();
        return;
    }

    // 3. TOP Method of stack
    int Top(){
        return q1.front();
    }

    // 4. EMPTY Method of stack
    bool Empty(){
        return q1.size() == 0;
    }
};

int main(){
    // stack1 st;
    stack2 st;
    st.Push(1);
    st.Push(2);
    st.Push(3);
    st.Push(4);
    st.Push(5);

    while (!st.Empty()){
        cout << st.Top() << endl;
        st.Pop();
    }

    cout << st.Empty() << endl;

    cout << endl;
    return 0;
}