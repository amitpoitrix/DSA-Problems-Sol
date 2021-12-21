#include<iostream>
#include<map>
#include<list>
// Creating Phonebook contaning multiple phone no. of same person

int main(){
    // Creating Order Hash Table <string, list<string>>
    std::map<std::string, std::list<std::string>> phonebook;
    // Amit -> {1111111, 1111112, 1111113}
    phonebook["Amit"].push_back("1111111");
    phonebook["Amit"].push_back("1111112");
    phonebook["Amit"].push_back("1111113");

    // Ashsih -> {1111115, 1111116}
    phonebook["Ashish"].push_back("1111115");
    phonebook["Ashish"].push_back("1111116");

    for (auto kv : phonebook){
        std::cout << kv.first << "\n";
        for (auto x : kv.second){
            std::cout << x << "  ";
        }
        std::cout << "\n";
    }
    
    return 0;
}