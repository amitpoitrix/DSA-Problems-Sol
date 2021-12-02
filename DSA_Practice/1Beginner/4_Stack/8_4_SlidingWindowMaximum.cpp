#include<bits/stdc++.h>
using namespace std;
// Pepcoding : Sliding Window Maximum - We need to find max element of k size window in an array

vector<int> slidingWindowMax(vector<int> arr, int k){
    // 1. We'll find Next Greatest Element - Index wise
    int n = arr.size();
    vector<int> nge(n);

    stack<int> st;
    st.push(n-1);
    nge[n-1] = n;   // Inserting size of vector as last index value of NGE

    for (int i = arr.size()-2; i >= 0; i--){
        while (!st.empty() && arr[st.top()] <= arr[i]){
            st.pop();
        }

        if(st.empty()){
            nge[i] = n;
        }
        else{
            nge[i] = st.top();
        }
        st.push(i);
    }

    // 2. Once find the NGE than implement problem logic
    vector<int> res(arr.size()-k+1);    // creating resultant array containg max element of window size k
    // Taking two pointers i & j to traverse the Given Array and NGE respectively
    int j = 0;
    // Traversing Given array till 'array size - k' 
    for (int i = 0; i <= (arr.size() - k); i++){
        if(j < i){
            j = i;
        }

        // checking whether NGE is under window size(i+k) or not
        while (nge[j] < i + k){
            j = nge[j];
        }

        res[i] = arr[j];
    }

    return res;
}

int main(){
    int n, k;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < arr.size(); i++){
        cin >> arr[i];
    }

    cin >> k;

    vector<int> res(arr.size()-k+1);
    res = slidingWindowMax(arr, k);

    for (auto x : res){
        cout << x << " ";
    }
    
    cout << endl;
    return 0;
}