#include<bits/stdc++.h>
using namespace std;

// Lt: 973. K Closest Points to Origin
// https://leetcode.com/problems/k-closest-points-to-origin/

// Using MaxHeap + Distance Formulae as Key
// TC - O(nlogk)
// SC - O(k)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        // Here key for Max Heap is distance i.e., x^2 + y^2
        // And value are the coordinates {x, y}
        
        priority_queue<pair<int, pair<int, int>>> maxH;
        for(int i = 0; i < n; i++){
            // {x^2 + y^2, {x, y}}
            maxH.push({points[i][0] * points[i][0] + points[i][1] * points[i][1], {points[i][0], points[i][1]}});
                
            if(maxH.size() > k)
                maxH.pop();
        }
        
        // vector<vector<int>> res(k, vector<int> (2, 0));
        // res[j][0] = maxH.top().second.first;
        // res[j][1] = maxH.top().second.second;
        vector<vector<int>> res(k);
        int j = 0;
        while(!maxH.empty() && j < k){
            res[j].push_back(maxH.top().second.first);
            res[j].push_back(maxH.top().second.second);
            maxH.pop();
            j++;
        }
        
        return res;
    }
};

int main(){
    return 0;
}