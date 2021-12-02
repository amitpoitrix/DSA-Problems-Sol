#include<bits/stdc++.h>
using namespace std;
// Pepcoding : Largest Histogram Area - Using Stack - O(N)

vector<int> rightSmallestElement(vector<int> arr){
    int n = arr.size();
    vector<int> rse(n);

    stack<int> st;
    st.push(n-1);
    rse[n-1] = n;

    for (int i = n-2; i >= 0; i--){
        // 1. POP
        while (!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }
        
        // 2. Print
        if(st.empty())
            rse[i] = n;
        else
            rse[i] = st.top();

        // 3. PUSH
        st.push(i);
    }
    
    return rse;
}

vector<int> leftSmallestElement(vector<int> arr){
    int n = arr.size();
    vector<int> lse(n);

    stack<int> st;
    st.push(0);
    lse[0] = -1;

    for (int i = 1; i < arr.size(); i++){
        // 1. POP
        while (!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }
        
        // 2. Print
        if(st.empty())
            lse[i] = -1;
        else
            lse[i] = st.top();

        // 3. PUSH
        st.push(i);
    }
    
    return lse;
}

int largestHistogramArea(vector<int> arr){
    int maxArea = 0;
    vector<int> rse = rightSmallestElement(arr);
    vector<int> lse = leftSmallestElement(arr);

    for (int i = 0; i < arr.size(); i++){
        int width = rse[i] - lse[i] - 1;
        int area = width * arr[i];
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n,0);

    for (int i = 0; i < arr.size(); i++){
        cin >> arr[i];
    }

    cout << "Max Area : " << largestHistogramArea(arr);

    cout << endl;
    return 0;
}