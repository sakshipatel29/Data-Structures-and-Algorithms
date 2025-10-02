#include <iostream>
#include <string>
using namespace std;

//TC: O(N)
//SC: O(N)

struct Node{
    Node *links[26];
    bool flag = false;
    bool containsKey(char ch){
        return (links[ch - 'a'] != NULL);
    } 
    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }
    Node* get(char ch){
        return links[ch - 'a'];
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
};
class WordDictionary {
private:
    Node* root;
    bool dfs(string &word, int idx, Node* node) {
        if (!node) return false;
        if (idx == word.size()) return node->isEnd();

        char ch = word[idx];
        if (ch == '.') {
            // Try all possible 26 children
            for (int j = 0; j < 26; j++) {
                if (node->links[j] && dfs(word, idx + 1, node->links[j]))
                    return true;
            }
            return false;
        } else {
            if (!node->containsKey(ch)) return false;
            return dfs(word, idx + 1, node->get(ch));
        }
    }
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for(int i = 0 ; i< word.size(); i++){
            if(!node->containsKey(word[i])) node->put(word[i], new Node());
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */