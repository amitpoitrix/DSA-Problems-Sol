#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Job{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

class Solution{
private:
    static bool comparator(struct Job arr1, struct Job arr2){
        return arr1.profit > arr2.profit;
    }
    
public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n){ 
        // First sort the Job arr[] according to desc order of their profit
        sort(arr, arr + n, comparator);
        // Now creating array of size max of deadline
        int maxii = 0;
        for(int i = 0; i < n; i++){
            maxii = max(maxii, arr[i].dead);
        }
        vector<int> slot(maxii + 1, -1);
        
        int countJob = 0, profit = 0;
        for(int i = 0; i < n; i++){
            for(int j = arr[i].dead; j > 0; j--){
                if(slot[j] == -1){
                    slot[j] = arr[i].id;
                    countJob++;
                    profit += arr[i].profit;
                    break;  // As we've to perform only 1 job/day
                }
            }
        }
        
        vector<int> res(2);
        res[0] = countJob;
        res[1] = profit;
        return res;
    } 
};

int main(){
    return 0;
}