#include <bits/stdc++.h> 
using namespace std; 

// Using Heap
// TC - O(nlogk)
// SC - O(k)
class Solution{
public:
    vector<int> Kclosest(vector<int>arr, int n, int x, int k) { 
        // We'll make use of Max Heap
        priority_queue<pair<int, int>> maxH;
        
        for(int i = 0; i < n; i++){
            maxH.push({abs(arr[i] - x), arr[i]});
            
            if(maxH.size() > k){
                auto p = maxH.top();
                maxH.pop();
                // If diff is same than consider the smallest element
                if(p.first == maxH.top().first && p.second < maxH.top().second){
                    maxH.pop();
                    maxH.push(p);
                }
            }
        }
        
        vector<int> res;
        while(!maxH.empty()){
            res.push_back(maxH.top().second);
            maxH.pop();
        }
        
        sort(res.begin(), res.end());
        
        return res;
    }  
};

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n,x,k;
		cin>>n>>x>>k; 
		vector <int> array(n);
		for (int i = 0; i < n; ++i)
			cin>>array[i];
        
        Solution obj;
		vector <int> result = obj.Kclosest(array, n, x, k); 
		for (int i = 0; i < result.size(); ++i)
		{
			cout<<result[i]<<" ";
		}
		cout<<"\n";
	}

	return 0; 
} 