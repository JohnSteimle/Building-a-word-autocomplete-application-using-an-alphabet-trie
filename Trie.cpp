//----------------------------------------------------------------
// Name: John Steimle
// Project 5 Data Structures     
// 
// 
//----------------------------------------------------------------
#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include "Trie.h"
using namespace std;
bool Trie::insert(string word){
    if(find(word)==false){
        int wordLength = word.length();
        char letter = word[0];
        insertHelper(word, node, wordLength, letter, 0);
        return true;
    } else {
        return false;
    }
}
TrieNode* Trie::insertHelper(string word, TrieNode* node, int wordLength, char letter, int i){
    if(wordLength!=0){
        TrieNode* newNode = new TrieNode();
        node->children[letter-'a'] = newNode;
        letter = word[i];
        wordLength = wordLength-1;
        i++;
        insertHelper(word, newNode, letter, wordLength, i);
    } else {
        node->endWord = true;
        return node;
    }
}
int Trie::count(){}
int Trie::getSize(){}
bool Trie::find(string word){
    return false;
}
int Trie::completeCount(string word){}
vector<string> Trie::complete(string word){}
Trie& Trie::operator=(const Trie& tree){}