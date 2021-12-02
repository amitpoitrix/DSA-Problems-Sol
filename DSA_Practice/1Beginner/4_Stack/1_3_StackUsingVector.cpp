#include<iostream>
#include<vector>
using namespace std;
// Stack Implementation Using Vectors

class Stack{
    vector<int> arr;
public:
    // 1. PUSH Method
    void push(int data){
        arr.push_back(data);
    }

    // 2. POP Method
    void pop(){
        arr.pop_back();
    }

    // 3. TOP Method
    int Top(){
        int lastIdx = arr.size()-1;
        return arr[lastIdx];
    }

    // 4. EMPTY Method
    bool empty(){
        return arr.size()==0;
    }
};

int main(){
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    while (!st.empty()){
        cout << st.Top() << endl;
        st.pop();
    }

//     Stack st;
//     st.push(1);
//     st.push(2);
//     st.push(3);
//     cout << st.Top() << endl;

//     st.pop();
//     cout << st.Top() << endl;

//     st.pop();
//     st.pop();
//     cout << st.empty() << endl;

//     cout << endl;
//     return 0;
}