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
        i++;
        letter = word[i];
        wordLength = wordLength-1;
        
        TrieNode* plz = insertHelper(word, newNode, wordLength,letter, i);
    } else {
        node->endWord = true;
        return node;
    }
}
int Trie::count(){}
int Trie::getSize(){}
bool Trie::find(string word){
    char letter = word[0];
     if(node->children[letter-'a']!=nullptr){
        int i = 0;
        TrieNode* iterator = node;
        TrieNode* temp = findHelp(word, letter, i, iterator); 
        if(temp!=nullptr){
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
    
}
TrieNode* Trie::findHelp(string word, char letter, int i, TrieNode* iterator){
    if(iterator->endWord==true && i==(word.length()-1)){
        return node;
    } 
    if(i==(word.length()-1)){
        return nullptr;
    }
    iterator = iterator->children[letter-'a'];
    i++;
    letter = word[i];
    findHelp(word, letter, i, iterator);
}
int Trie::completeCount(string word){}
vector<string> Trie::complete(string word){}
Trie& Trie::operator=(const Trie& tree){}