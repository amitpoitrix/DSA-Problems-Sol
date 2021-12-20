#include<iostream>
#include<unordered_map>
// Hash Table STL - <unordered_map> -> TC - O(1) for all the operations in avg case
// <map> -> for order Hash Table & All Insert, Search, delete & Update will take O(logN) time as its implemented internally using BST

int main(){
    std::unordered_map<std::string, int> menu;

    // Insert key value pair inside the Hash Table
    menu["maggi"] = 15;
    menu["colddrink"] = 20;
    menu["dosa"] = 60;
    menu["pizza"] = 120;
    menu["indianplatter"] = 250;

    // Update Query O(1)
    menu["dosa"] = (1 + 0.1)*menu["dosa"];

    // Deletion O(1)
    menu.erase("maggi");

    // Searching inside a collection of key value pairs (Stored inside Hash Table) - O(1)
    std::string item;
    std::cin >> item;

    if(menu.count(item) == 0)
        std::cout << item << " is not available\n";
    else
        std::cout << item << " is available and its cost is " << menu[item] << "\n";

    // We can iterate over all the key-value pair that are present
    for (std::pair<std::string, int> item : menu){
        std::cout << item.first << " - " << item.second << "\n";
    }
    
    return 0;
}