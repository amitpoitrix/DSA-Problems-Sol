#include<iostream>
// Striver Trie Series : Trie Implementation II
// Operation - insert(), countWordsEqualTo(), countWordsStartingWith() & erase()

// Node structure of Trie Implementation II
struct Node{
    Node * links[26];
    int cntEndWith = 0;
    int cntPrefix = 0;

    bool containsKey(char ch){
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node * node){
        links[ch - 'a'] = node;
    }

    Node * get(char ch){
        return links[ch - 'a'];
    }

    void increaseEnd(){
        cntEndWith++;
    }

    void increasePrefix(){
        cntPrefix++;
    }

    void reduceEnd(){
        cntEndWith--;
    }

    void reducePrefix(){
        cntPrefix--;
    }

    int getEnd(){
        return cntEndWith;
    }

    int getPrefix(){
        return cntPrefix;
    }
};

class Trie{
private:
    Node * root;
public:
    Trie(){
        root = new Node();
    }

    // 1. insert()
    void insert(std::string word){
        Node * node = root;
        for (int i = 0; i < word.size(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    // 2. countWordsEqualTo()
    int countWordsEqualTo(std::string word){
        Node * node = root;
        for (int i = 0; i < word.size(); i++){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
            }
            else
                return 0;
        }

        return node->getEnd();
    }

    // 3. countWordsStartingWith()
    int countWordsStartingWith(std::string word){
        Node * node = root;
        for (int i = 0; i < word.size(); i++){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
            }
            else
                return 0;
        }
        return node->getPrefix();
    }

    // 4. erase()
    void erase(std::string word){
        Node * node = root;
        for (int i = 0; i < word.size(); i++){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
                node->reducePrefix();
            }
            else
                return;
        }

        node->reduceEnd();
    }
};

int main(){
    Trie * obj = new Trie();
    obj->insert("samsung");
    obj->insert("samsung");
    obj->insert("vivo");
    obj->insert("vivo");

    std::cout << obj->countWordsEqualTo("samsung") << "\n";
    std::cout << obj->countWordsStartingWith("vi") << "\n";

    return 0;
}