#include<bits/stdc++.h>
using namespace std;

// Using Binary Saerch
// TC - O(log(n))
// SC - O(1)
class Solution{
private:
    int firstOccurrence(int start, int end, vector<int> &arr, int x){
        int first = -1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(x == arr[mid]){
                first = mid;
                end = mid - 1;
            }
            else if(x < arr[mid]) end = mid - 1;
            else start = mid + 1;
        }
        return first;
    }
    
    int lastOccurrence(int start, int end, vector<int> &arr, int x){
        int last = -1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(x == arr[mid]){
                last = mid;
                start = mid + 1;
            }
            else if(x < arr[mid]) end = mid - 1;
            else start = mid + 1;
        }
        return last;
    }
    
public:
    vector<int> firstAndLast(vector<int> &arr, int n, int x) {
        vector<int> ans;
        if(firstOccurrence(0, n - 1, arr, x) == -1){
            ans.push_back(-1);
            return ans;
        }
        ans.push_back(firstOccurrence(0, n - 1, arr, x));
        ans.push_back(lastOccurrence(0, n - 1, arr, x));
        return ans;
    }
};

// Using C++ stl 
class Solution1{
public:
    vector<int> firstAndLast(vector<int> &arr, int n, int x) {
        vector<int> ans;
        int first = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        if(first == n || arr[first] != x){
            ans.push_back(-1);
            return ans;
        }
        
        int last = upper_bound(arr.begin(), arr.end(), x) - arr.begin() - 1;
            
        ans.push_back(first);
        ans.push_back(last);
        
        return ans;
    }
};

int main(){
    vector<int> arr = {8};
    int n = 1;
    int x = 0;

    Solution1 obj;
    vector<int> res = obj.firstAndLast(arr, n, x);

    for(auto &x: res)
        cout << x << " ";

    return 0;
}