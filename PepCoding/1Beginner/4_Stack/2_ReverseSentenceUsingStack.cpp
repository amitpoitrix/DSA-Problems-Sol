#include<iostream>
#include<stack>
using namespace std;
// Stack Application - Reversing a sentence using stack

void reverseSentence(string s){
    stack<string> st;
    
    // Pushing each words of sentence into the stack
    for (int i = 0; i < s.size(); i++){
        string word = "";

        while (s[i] != ' ' && i < s.size()){
            word += s[i];
            i++;
        }

        st.push(word);
    }
    
    // Popping the element from top of the stack
    while (!st.empty()){
        cout << st.top() << " ";
        st.pop();   // if pop is not done that top will remain on that position
    }
}

int main(){
    string s = "Heyy, how are you doing?";
    reverseSentence(s);

    cout << endl;
    return 0;
}