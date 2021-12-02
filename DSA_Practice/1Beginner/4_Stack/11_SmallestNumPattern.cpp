#include<iostream>
#include <string>
#include <stack>
using namespace std;
// Pepcoding : Smallest Number following pattern

void smallestNumPattern(string str){
    stack<int> st;
    int num = 1;    // taking num =1 as variable as we need to increase it by once for every iteration
    for (int i = 0; i < str.size(); i++){
        char ch = str[i];
        // when encounter d - decreasing
        if(ch == 'd'){
            st.push(num);
            num++;
        }
        // when encounter i - increasing
        else{
            st.push(num);
            num++;
            while (!st.empty()){
                cout << st.top() << " ";
                st.pop();
            }
        }
    }
    // As max size of str can be 8 and num are from 1-9 so inorder to insert last element
    st.push(num);
    while (!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}

int main() {
    string str;
    cin >> str;

    smallestNumPattern(str);
    return 0;
}