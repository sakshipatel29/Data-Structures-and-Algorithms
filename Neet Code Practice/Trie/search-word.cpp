//TC: O(N)
//SC: O(N)

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        struct trieNode{
            bool isEndOfWord;
            trieNode* children[26];
            string word;
        };
    
        trieNode* getNode(){
            trieNode* newNode = new trieNode();
            newNode->isEndOfWord = false;
            for(int i = 0; i<26; i++){
                newNode->children[i] = nullptr;
            }
            return newNode;
        }
        
        trieNode* root = getNode();
    
        void insert(string word){
            trieNode* crawl = root;
            for(int i = 0; i<word.size(); i++){
                char ch = word[i];
                int idx = ch - 'a';
                if(crawl->children[idx] == nullptr){
                    crawl->children[idx] = getNode();
                }
                crawl = crawl->children[idx];
            }
            crawl->isEndOfWord = true;
            crawl->word = word;
        }
    
        void dfs(vector<vector<char>>&board, int row, int col, trieNode* node, vector<string>&result){
            char ch = board[row][col];
            int idx = ch - 'a';
    
            if(node->children[idx] == nullptr) return;
    
            node = node->children[idx];
    
            if(node->isEndOfWord){
                result.push_back(node->word);
                node->isEndOfWord = false;
            }
    
            board[row][col] = '#';
    
            int prow[4] = {-1, 1, 0, 0};
            int pcol[4] = {0, 0, -1, 1};
    
            for (int k = 0; k < 4; k++) {
            int nrow = row + prow[k];
            int ncol = col + pcol[k];
            if (nrow >= 0 && ncol >= 0 && nrow < board.size() && ncol < board[0].size() && board[nrow][ncol] != '#') {
                dfs(board, nrow, ncol, node, result);
            }
        }
    
        board[row][col] = ch;
        }
    
    
    
        vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
            int n = board.size();
            int m = board[0].size();
            
            for(auto &word:words){
                insert(word);
            }
            vector<string>result;
            for(int i = 0; i<n; i++){
                for(int j = 0; j<m; j++){
                    dfs(board, i, j, root, result);
                }
            }
            return result;
        }
    };