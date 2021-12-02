#include<bits/stdc++.h>
using namespace std;
// Pepcoding : Celebrity Problem
// Celebrity is define as a person who is known by everyone and he/she doesn't know anyone

// function to return index where celebrity is found
int celebrityProblem(vector<vector<int>> arr){
    // First we'll check the potential celebrity
    stack<int> st;
    for (int i = 0; i < arr.size(); i++){
        st.push(i);
    }
    
    while (st.size() >= 2){
        int i = st.top();
        st.pop();
        int j = st.top();
        st.pop();
        // 1 -> Knows ; 0 -> doesn't know
        if(arr[i][j] == 1){
            // if i knows j than i is not a celebrity
            st.push(j);
        }
        else{
            // if j knows i than j is not a celebrity
            st.push(i);
        }
    }
    // Now the potential celebrity index is
    int pot = st.top();

    // Now we'll check whether this potential celebrity is actual celebrity or not
    for (int i = 0; i < arr.size(); i++){
        if(i != pot){
            if(arr[i][pot] == 0 || arr[pot][i] == 1 ){
                return -1;
            }
        }
    }
    
    return pot;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> arr(n);

    int val;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> val;
            arr[i].push_back(val);
        }
    }

    int ans = celebrityProblem(arr);

    if(ans == -1){
        cout << "None";
    }
    else{
        cout << "Celebrity at : " << ans;
    }

    cout << endl;
    return 0;
}