#include<iostream>
// Leetcode - Weekly Contest 276 on 16th Jan 2022
// 2. 2139. Minimum Moves to Reach Target Score

// Using Greedy Algorithm
class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        // Instead of reaching the target from 1 we'll start from target and reach back to 1
        int moves = 0;
        while (target != 1){
            if(maxDoubles){
                if(target % 2 == 0){
                    target = target/2;
                    maxDoubles--;
                }
                else{
                    target--;
                }
                moves++;
            }
            else{
                moves += target - 1;
                break;
            }
        }
        
        return moves;
    }
};

int main(){
    int target = 10;
    int maxDoubles = 4;

    Solution obj;
    std::cout << obj.minMoves(target, maxDoubles);

    return 0;
}