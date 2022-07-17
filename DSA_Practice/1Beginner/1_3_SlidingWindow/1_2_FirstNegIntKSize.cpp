#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// First negative integer in every window of size k
// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1/#

// Using Sliding Window
// Method 1
class Solurion{
public:
    vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K) {
        vector<long long> ans;
        queue<long long> q;
        int i = 0, j = 0;

        while(j < N){
            // Calculations
            if(A[j] < 0)
                q.push(A[j]);
            
            // If window size(k) is not reached
            if((j - i + 1) < K)
                j++;
            
            else if((j - i + 1) == K){
                // Ans
                if(q.empty())
                    ans.push_back(0);
                else{
                    ans.push_back(q.front());
                }

                // Before sliding the window
                if(q.front() == A[i])
                    q.pop();
                
                // slide the window
                i++;
                j++;
            }
        }

        return ans;
    }
};

// Method 2
class Solurion{
public:
    vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K) {
        vector<long long> ans;
        queue<long long> neg;

        for(int i = 0; i < K; i++){
            if(A[i] < 0)
                neg.push(i);
        }
        
        if(neg.empty() == true)
            ans.push_back(0);
        else
            ans.push_back(A[neg.front()]);
        
        for(int i = K; i < N; i++){
            if(A[i] < 0)
                neg.push(i);
            
            if(!neg.empty() && A[i-K] == A[neg.front()])
                neg.pop();
            
            if(neg.empty() == true)
                ans.push_back(0);
            else
                ans.push_back(A[neg.front()]);
        }
        
        return ans;
    }
};

int main(){
    return 0;
}