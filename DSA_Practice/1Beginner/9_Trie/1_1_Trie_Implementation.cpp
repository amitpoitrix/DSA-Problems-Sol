#include<iostream>
// Striver Trie Series : Trie Implementation I
// Operations : insert(), search() & startWith() TC - O(len) where len is the length of given word

/* Not working here as it works fine on CodeStudio & Replit Online C++ compiler*/

// Node structure of Trie Implementation I
struct Node{
    // Node * pointing to Array of type Node* of size 26 - No. of alphabets (0 - a.... 25 - z)
    Node * links[26];
    bool flag = false;

    // Function to check whether ch present or not
    bool containsKey(char ch){
        return links[ch - 'a'] != NULL;
    }

    //Function to add new ch & points/refer it to new Trie node
    void put(char ch, Node * node){
        links[ch - 'a'] = node;     
    }

    // Function to return Node* that char ch is pointing to 
    Node * get(char ch){
        return links[ch - 'a'];
    }

    // Once a word is complete make its flag to true
    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    } 
};

class Trie{
private:
    Node * root;
public:
    // Constructor to initialise the Trie DS
    Trie(){
        root = new Node();
    }

    // Insert a word into Trie
    void insert(std::string word){
        Node * node = root; // Creating a dummy node
        for (int i = 0; i < word.size(); i++){
            // If word char ch is not there than add its char and reference it to new Trie node
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            // Incrementing Node pointer
            node = node->get(word[i]);
        }
        // After Word char finish
        node->setEnd();
    }

    // Search - Function to check whether a word is there in Trie or not
    bool search(std::string word){
        Node * node = root;
        for (int i = 0; i < word.size(); i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            // else increment node to check rest of the word char
            node = node->get(word[i]);
        }
        // After traversal return the flag of last node
        return node->isEnd();
    }

    // StartWith - Function to check whether there is any word in Trie that contains prefix
    bool startWith(std::string prefix){
        Node * node = root;
        for (int i = 0; i < prefix.size(); i++){
            if(!node->containsKey(prefix[i])){
                return false;
            }
            node = node->get(prefix[i]);
        }

        return true;
    }
};

int main(){
    Trie * obj = new Trie();
    obj->insert("Apple");
    obj->insert("Aps");
    obj->insert("Banana");
    obj->insert("Ban");

    std::cout << obj->search("Apple") << "\n";
    std::cout << obj->search("Apple") << "\n";
    std::cout << obj->startWith("Bana") << "\n";

    return 0;
}
