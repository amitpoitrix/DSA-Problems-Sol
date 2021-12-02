#include <iostream>
#include <vector>
using namespace std;

vector<int> allIndex(vector<int>& arr, int idx, int data, int count){
    // base case
    if(idx == arr.size()){
        vector<int> res(count);
        return res;
    } 

    // rec case
    if(arr[idx] == data){
        vector<int> res = allIndex(arr, idx+1, data, count+1);
        res[count] = idx;
        return res;
    }
    else{
        vector<int> res = allIndex(arr, idx+1, data, count);
        return res;
    }
}

int main() {
    int n ;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        arr.push_back(d);
    }
    int data;
    cin >> data;
    vector<int> ans = allIndex(arr, 0, data, 0);
    if (ans.size() == 0) {
        cout << endl;
        return 0;
    }
    for (int ele : ans) 
        cout << ele << endl;

    return 0;
}