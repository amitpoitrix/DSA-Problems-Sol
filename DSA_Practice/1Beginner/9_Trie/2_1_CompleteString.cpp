#include<iostream>
#include<vector>
// Striver Trie Series : Complete String || Longest Word With All Prefixes

// Using Trie
struct Node{
    Node * links[26];
    bool flag;

    bool containsKey(char ch){
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node * node){
        links[ch - 'a'] = node;
    }

    Node * get(char ch){
        return links[ch - 'a'];
    }

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
    Trie(){
        root = new Node();
    }

    void insert(std::string word){
        Node * node = root;
        for (int i = 0; i < word.size(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        
        node->setEnd();
    }

    bool checkIfAllPrefixExists(std::string word){
        Node * node = root;
        bool fl = true;
        for (int i = 0; i < word.size() && fl; i++){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
                fl = fl & node->isEnd();    // If we encounter any alphabet after which word doesn't end than return false 
            }
            else{
                return false;
            }
        }
        return fl;
    }
};

std::string completeString(int n, std::vector<std::string> &a){
    Trie * trie = new Trie();

    for (auto word : a){
        trie->insert(word);
    }

    std::string longest = "";

    for (auto word : a){
        if(trie->checkIfAllPrefixExists(word)){
            if(word.size() > longest.size())
                longest = word;
            else if(word.size() == longest.size() && word < longest)
                longest = word;
        }
    }
    
    return (longest == "")? "None" : longest;
}

int main(){
    std::vector<std::string> a = {"n", "ni", "nin", "ning", "ninj", "ninja", "ninga"};
    int n = a.size();

    completeString(n, a) == "None"? std::cout<<"None" : std::cout<<completeString(n, a);

    return 0;
}