#include<iostream>
#include<vector>
#include<algorithm>
// Striver Trie Series : Maximum XOR of Array with Queries
// Online Queries - Solve in the same order and return ans in same order
// Offline Queries - Solve by modifying the order of queries & return ans in original order of query

// Using Trie
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

std::vector<int> maxXorQueries(std::vector<int> &arr, std::vector<std::vector<int>> &queries){
    // We'll create an offline Querie(xi, ai) & sort on the basis of ai as in ques elements from array should be <= ai
    std::vector<std::pair<int, std::pair<int, int>>> offlineQuery;
    int q = queries.size();

    // Inserting the queries elements in offlineQuery( { ai, {xi, i} } )
    for (int i = 0; i < q; i++){
        offlineQuery.push_back({queries[i][1], {queries[i][0], i}});
    }

    // Sorting the offlineQuery acc. to ai  - O(QlogQ)
    std::sort(offlineQuery.begin(), offlineQuery.end());

    // Sorting arr
    std::sort(arr.begin(), arr.end());
    int n = arr.size();

    // Creating return vector
    std::vector<int> result(q, 0);

    Trie * trie = new Trie();
    int i = 0;
    // O((Q + N) * 32)
    for (auto it : offlineQuery){
        while(i < n && arr[i] <= it.first){
            trie->insertBit(arr[i]);
            i++;
        }
        // To return the resultant vector in same order we're storing element(max) as per offlineQuery index
        if(i != 0)
            result[it.second.second] = trie->getMax(it.second.first);
        else
            result[it.second.second] = -1;
    }
    
    return result;
}

int main(){
    std::vector<int> arr = {0,1,2,3,4};
    std::vector<std::vector<int>> queries = {{1,3}, {5,6}};

    std::vector<int> res = maxXorQueries(arr, queries);

    for (auto x : res){
        std::cout<< x << " ";
    }
    
    return 0;
}