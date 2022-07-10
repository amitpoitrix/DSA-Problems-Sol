#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// N meetings in one room
// https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

class Solution{
private:
    struct meeting{
        int start;
        int end;
        int pos;
    };
    
    static bool comparator(struct meeting m1, struct meeting m2){
        if(m1.end < m2.end) return true;
        else if(m1.end > m2.end) return false;
        else if(m1.pos < m2.pos) return true;
        return false;
    }
    
public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<meeting> m(n);
        for(int i = 0; i < n; i++){
            m[i].start = start[i];
            m[i].end = end[i];
            m[i].pos = i + 1;
        }
        
        sort(m.begin(), m.end(), comparator);
        
        int count = 1;
        int endLimit = m[0].end;
        for(int i = 1; i < n; i++){
            if(m[i].start > endLimit){
                endLimit = m[i].end;
                count++;
            }
        }
        
        return count;
    }
};

int main(){
    return 0;
}