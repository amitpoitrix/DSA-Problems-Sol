#include<iostream>
#include<vector>
using namespace std;

// Lt: 134. Gas Station
// https://leetcode.com/problems/gas-station/

// TC - O(n)
// SC - O(1)
class Solution {    
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int gasSum = 0, costSum = 0;
        for(int i = 0; i < gas.size(); i++){
            gasSum += gas[i];
            costSum += cost[i];
        }
        
        if(gasSum < costSum)
            return -1;
        
        int start = 0, currentFuel = 0;
        for(int i = 0; i < n; i++){
            currentFuel += gas[i] - cost[i];
            if(currentFuel < 0){
                start = i+1;
                currentFuel = 0;
            }
        }
        
        return start;
    }
};

int main(){
    return 0;
}