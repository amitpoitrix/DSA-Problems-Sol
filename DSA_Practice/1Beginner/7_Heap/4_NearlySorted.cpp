#include<bits/stdc++.h>
using namespace std;

// Nearly sorted
// https://practice.geeksforgeeks.org/problems/nearly-sorted-1587115620/1

// Using Min heap
// TC - O(nlogk)
// SC - O(n)
class Solution{
public:
    vector <int> nearlySorted(int arr[], int num, int K){
        // As we've to sort in ascending so using Min Heap
        priority_queue<int, vector<int>, greater<int>> minH;
        vector<int> res(num, 0);

        int j = 0;
        for(int i = 0; i < num; i++){
            minH.push(arr[i]);
            
            if(minH.size() > K){
                res[j] = minH.top();
                minH.pop();
                j++;
            }
        }
        
        // Inserting the remaining elements in minH 
        while(!minH.empty()){
            res[j] = minH.top();
            minH.pop();
            j++;
        }
        
        return res;
    }
};

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    Solution ob;
	    vector <int> res = ob.nearlySorted(arr, num, K);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	        
	    cout<<endl;
	}
	
	return 0;
}