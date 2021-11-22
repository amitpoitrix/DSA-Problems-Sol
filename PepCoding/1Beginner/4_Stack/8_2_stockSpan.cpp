#include <bits/stdc++.h>
using namespace std;
// Pepcoding - Stock Span - Next Greater Element on Left(Index wise)

void display(vector<int>a) {
  for (int i = 0; i < a.size(); i++){
    cout << a[i] << endl;
  }
}

// Next Greatest Element on the Left (Index Wise)
vector<int> solve(vector<int>arr){
  //write your code here
    vector<int> span(arr.size());

    stack<int> st;

    st.push(0); // for first element we'll push its index value in the stack
    span[0] = 1;    // Resultant vector 0th index value will be 1 i.e., itself    

    // checking for rest of the element which starts from index value 1
    for (int i = 1; i < arr.size(); i++){
        // step 1 : POP
        while (st.size() > 0 && arr[i] >= arr[st.top()]){
            st.pop();
        }

        // Step 2 : Print
        if(st.size() == 0)
            span[i] = i+1;  // If stack is empty that means its greatest so far so print index + 1
        else
            span[i] = i - st.top(); // otherwise current index value - last greatest stock span index value

        // Step 3 : PUSH
        st.push(i); // PUSHing current index value in the stack as Index represent Day Number
    }
    
    return span;
}


int main(int argc, char** argv){
    int n;
    cin >> n;
    vector<int>arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int>span(n, 0);
    span = solve(arr);
    display(span);
    return 0;
}
// 7
// 100
// 80
// 60
// 70
// 60
// 75
// 85