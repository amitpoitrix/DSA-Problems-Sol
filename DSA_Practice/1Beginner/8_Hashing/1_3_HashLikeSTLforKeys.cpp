#include<iostream>
#include<unordered_set>
// unordered_set is a STL that works like Hash Table but only on keys and all its operations take O(1) in avg case

int main(){
    // set is a collection of keys
    // Each insertion take O(1) time
    std::unordered_set<int> s{3,8,12,89,45,67};

    // Insert
    s.insert(112);

    // Delete O(1)
    s.erase(12);

    // search O(1)
    int key;
    std::cin >> key;

    if(s.find(key) != s.end())
        std::cout << key << " is present\n";
    else
        std::cout << "Not Found\n";

    // Printing all the element of set
    for (auto x : s){
        std::cout << x << " ";
    }
    

    return 0;
}