#include<iostream>
#include<vector>   
#include<algorithm>
using namespace std;

class Solution {
public:
    int minOperations(int n) {
        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            arr[i] = (2 * i) + 1;
        }
        
        int i = 0,j = 0;
        if(n % 2){
            i = n/2 - 1;
            j = n/2 + 1;
        }
        else{
            i = n/2 - 1;
            j = n/2;
        }
		cout << "i " << i << " " << "j " << j << "\n";
        
        int res = 0;
        while(i >= 0 && j < n){
            while(arr[i] != arr[j]){
                arr[i] += 1;
                arr[j] -= 1;
            }
            i--;
            j++;
            res += 1;
            cout << "arr[i] " << arr[i] << " " << "arr[j] " << arr[j] << "\n";
        }
        
        return res;
    }
};

int main()
{
	Solution obj;
	cout << obj.minOperations(3);
	return 0;
}
