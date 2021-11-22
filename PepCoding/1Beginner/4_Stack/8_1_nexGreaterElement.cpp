#include <bits/stdc++.h>
using namespace std;
// Pepcoding - Find Next Greater element of each element to the right
// Constraints - TC - O(n) ; SC - O(n)

void display(vector<int>a) {
  for (int i = 0; i < a.size(); i++)
  {
    cout << a[i] << endl;
  }
}

vector<int> solve(vector<int>arr){
    vector<int> ngeR(arr.size(), 0);   // Declared new vector ngeR of arr size that will contain NGE to the right

    stack<int> st;

    st.push(arr[arr.size()-1]); // Pushing the last element of arr in stack
    ngeR[ngeR.size()-1] = -1;   // Initializing last element NGE as -1

    // Checking for rest of the element from 2nd last till 1st element ; Algo : -(pop) , ans , +(push)
    for (int i = arr.size()-2; i >= 0; i--){
        // If arr[i] is greater or equal to the element present in stack than start popping till it founds element greater than it
        while (st.size() > 0 && arr[i] >= st.top()){
            st.pop();
        }

        // After popping of element from stack if size is 0 than assign NGE as -1 or else top element of stack
        if(st.size() == 0)
            ngeR[i] = -1;
        else
            ngeR[i] = st.top();

        // After checking than do push of arr[i]
        st.push(arr[i]);
    }
    
    return ngeR;
}


int main(int argc, char** argv){
    int n;
    cin >> n;
    vector<int>arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int>nge(n, 0);
    nge = solve(arr);
    display(nge);
    return 0;
}