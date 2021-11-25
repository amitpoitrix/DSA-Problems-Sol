#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
// Pepcoding : Merge Overlapping Intervals - TC - O(logN)
// In this some time intervals is given and we've to merge them and print in ascending order

void mergeOverlappingIntervals(vector<vector<int>>& arr) {
    // First sorting the given arr
    sort(arr.begin(), arr.end());

    stack<pair<int, int>> st;
    st.push({arr[0][0], arr[0][1]});    // Pushing the first smallest time interval into stack

    for (int i = 0; i < arr.size(); i++){
        int start1 = st.top().first;
        int end1 = st.top().second;
        int start2 = arr[i][0];
        int end2 = arr[i][1];

        if(start2 > end1){
            st.push({start2, end2});
        }
        else{
            st.pop();   // removing the top element 
            end1 = max(end1, end2);
            st.push({start1, end1});
        }
    }
    // As we need to print the elements pairwise in ascending order so taking another stack st2
    stack<pair<int, int>> st2;
    while (!st.empty()){
        st2.push(st.top());
        st.pop();
    }

    while (!st2.empty()){
        cout << st2.top().first << " " << st2.top().second << endl;
        st2.pop();
    }
}


int main() {
    int n;
    cin >> n ;

    vector<vector<int>> arr( n, vector<int>(2) );
    // input
    for (int i = 0; i < n ; i++ ) {
        cin >> arr[i][0];
        cin >> arr[i][1];
    }

    mergeOverlappingIntervals(arr);
    return 0;
}