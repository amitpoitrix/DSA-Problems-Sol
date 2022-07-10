#include<iostream>
#include<algorithm>
using namespace std;

struct Item{
    int value;
    int weight;
};

class Solution{
private:
    static bool comparator(struct Item arr1, struct Item arr2){
        double r1 = (double)arr1.value/(double)arr1.weight;
        double r2 = (double)arr2.value/(double)arr2.weight;
        return r1 > r2;
    }
    
public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n){
        // sorting acc. to desc order of val[]/wt[]
        sort(arr, arr + n, comparator);
        
        int currentWeight = 0;
        double totalValue = 0;
        for(int i = 0; i < n; i++){
            // if weights completely resides in Knapsack
            if(currentWeight + arr[i].weight <= W){
                currentWeight += arr[i].weight;
                totalValue += arr[i].value;
            }
            // if not than put fractional part of item
            else{
                int remain = W - currentWeight;
                double val = ((double)arr[i].value/(double)arr[i].weight) * (double)remain;
                totalValue += val;
                break;
            }
        }
        
        return totalValue;
    }
};

int main(){
    return 0;
}