#include<iostream>
#include<vector>
// Striver Trie Series : Maximum Xor of Two Numbers each from Two Arrays
// Using Trie
// This Problem is extension to the prblm of : Given a number x, find out the Max XOR of x with any elements of array
// 1. Insert all the numbers(of array in Binary Bits) into the Trie
// 2. Take x & find the Max no. from array where (no ^ x) is MAX

struct Node{
    Node * links[2];    // to store 0 or 1

    bool containsBit(int bit){
        return (links[bit] != NULL);
    }

    void put(int bit, Node * node){
        links[bit] = node;
    }


    Node * get(int bit){
        return links[bit];
    }
};

class Trie{
private:
    Node * root;
public:
    Trie(){
        root = new Node();
    }

    void insertBit(int num){
        Node * node = root;
        for (int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;   // Inorder to get the bit at pos i
            if(!node->containsBit(bit)){
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMax(int num){
        Node * node = root;
        int maxNum = 0;

        for (int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;
            // Checking if opposite of bit exist or not if yes than make set bit at pos i of maxNum
            if(node->containsBit(!bit)){
                maxNum = maxNum | (1 << i); // Setting bit at i pos as 1
                node = node->get(!bit);
            }
            else{
                node = node->get(bit);
            }
        }

        return maxNum; 
    }
};

int maxXOR(int n, int m, std::vector<int> &arr1, std::vector<int> &arr2) {
    // Trie * trie = new Trie();    // & call its function with -> instead of .
    Trie trie;
    int maxi = 0;
    // 1. Inserting all the elements of arr1 
    for (auto x : arr1){
        trie.insertBit(x);
    }
    // 2. Checking maxXor of each elements of arr2 with elements of arr1
    for (auto y : arr2){
        maxi = std::max(maxi, trie.getMax(y));
    }
    
    return maxi;
}

int main(){
    std::vector<int> arr1 = {6,8};
    int n = arr1.size();
    std::vector<int> arr2 = {7,8,2};
    int m = arr2.size();

    std::cout << maxXOR(n, m, arr1, arr2);

    return 0;
}