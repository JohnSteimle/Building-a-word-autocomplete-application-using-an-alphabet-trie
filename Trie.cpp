//----------------------------------------------------------------
// Name: John Steimle
// Project 5 Data Structures     
// implements the functions in Trie.h
// 
//----------------------------------------------------------------
#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include "string.h"
#include "Trie.h"
using namespace std;
//----------------------------------------------------------------
// Trie::insert inserts a word into the tree
//    Returns:  bool
//    Parameters:
//       string word
//----------------------------------------------------------------
bool Trie::insert(string word){
    if(find(word)==false){
        int wordLength = word.length();
        char letter = word[0];
        insertHelper(word, node, wordLength, letter, 0);
        wordCount++;
        return true;
    } else {
        return false;
    }
}
//----------------------------------------------------------------
// Trie::insertHelper helps the insert function
//    Returns: TrieNode*
//    Parameters:
//       string word TrieNode* node, int wordLength, char letter, int i
//----------------------------------------------------------------
TrieNode* Trie::insertHelper(string word, TrieNode* node, int wordLength, char letter, int i){
    if(wordLength>0){
        TrieNode* newNode = new TrieNode();
        if(node->children[letter-'a']==nullptr){
        node->children[letter-'a'] = newNode;
        i++;
        letter = word[i];
        wordLength = wordLength-1;
        } else {
        newNode = node->children[letter-'a'];
        i++;
        letter = word[i];
        wordLength = wordLength-1;
        }
        TrieNode* plz = insertHelper(word, newNode, wordLength,letter, i);
    } else if(wordLength==0) {
        node->endWord = true;
        return node;
    }
}
//----------------------------------------------------------------
// Trie::count returns number of words in trie
//    Returns:  int
//    Parameters:
//       None
//----------------------------------------------------------------
int Trie::count(){
    return wordCount;
}
//----------------------------------------------------------------
// Trie::getSize returns number of nodes in trie
//    Returns:  int
//    Parameters:
//       None
//----------------------------------------------------------------
int Trie::getSize(){
    countPre=0;
    sizeHelper(node);
    return countPre;
}
//----------------------------------------------------------------
// Trie::sizeHelper
//    Returns:  TireNode*
//    Parameters:
//       TrieNode* nodeToCount
//----------------------------------------------------------------
TrieNode* Trie::sizeHelper(TrieNode* nodeToCount){
    if(nodeToCount){
        countPre++;
    for(int i=0; i<26; i++){
        if(nodeToCount->children[i]){
            TrieNode* nextNode = sizeHelper(nodeToCount->children[i]);
        }
    }
    }
}
//----------------------------------------------------------------
// Trie::find searches the Trie for word
//    Returns:  bool
//    Parameters:
//       string word
//----------------------------------------------------------------
bool Trie::find(string word){
    char letter = word[0];
     if(node->children[letter-'a']!=nullptr){
        int i = 0;
        TrieNode* iterator = node;
        TrieNode* temp = nullptr;
        temp = findHelp(word, letter, i, iterator); 
        if(temp==nullptr){
            return false;
        } else {
            return true;
        }
    } else {
        return false;
    }
    
}
//----------------------------------------------------------------
// Trie::findHelp helps search the Trie for word
//    Returns:  TrieNode* 
//    Parameters:
//       string word, char letter, int i, TrieNode* iterator
//----------------------------------------------------------------
TrieNode* Trie::findHelp(string word, char letter, int i, TrieNode* iterator){
    if(iterator){
    if(iterator->endWord==true && i==(word.length())){
        return node;
    }else if(i==(word.length())){
        return nullptr;
    }
    iterator = iterator->children[letter-'a'];
    i++;
    letter = word[i];
    
    TrieNode* temp = findHelp(word, letter, i, iterator);
    if(temp==nullptr){
        return nullptr;
    } else {
        return node;
    }
    } else {
        return nullptr;
    }
}
//----------------------------------------------------------------
// Trie::completeCount returns number of words matching specified prefix
//    Returns:  int
//    Parameters:
//       string word
//----------------------------------------------------------------
int Trie::completeCount(string word){
    TrieNode* temp = node;
    char letter;
    countPre=0;
    for(int i=0; i<word.length(); i++){
        letter = word[i];
        temp = temp->children[letter-'a'];
    }
    if(temp){
    }
    TrieNode* checkNode = searchNode(temp);
    return countPre;
}
//----------------------------------------------------------------
// Trie::searchNode helps the completeCount function
//    Returns:  TrieNode*
//    Parameters:
//       TrieNode* nodeToSearch
//----------------------------------------------------------------
TrieNode* Trie::searchNode(TrieNode* nodeToSearch){
    if(nodeToSearch){
    if(nodeToSearch->endWord==true){
        countPre++;
    }
    
    for(int i=0; i<26; i++){
        if(nodeToSearch->children[i]){
            TrieNode* nextNode = searchNode(nodeToSearch->children[i]);
        }
    }
    }
}
//----------------------------------------------------------------
// Trie::complete returns a vector of words matching a certain prefix
//    Returns:  vector<string>
//    Parameters:
//       string word
//----------------------------------------------------------------
vector<string> Trie::complete(string word){
    vector<string> words;
    TrieNode* temp = node;
    char letter;
    countPre=0;
    for(int i=0; i<word.length(); i++){
        letter = word[i];
        temp = temp->children[letter-'a'];
    }
    
    words = completeHelper(temp, words, word);
    return words;
}
//----------------------------------------------------------------
// Trie::completeHelper helps return a vector of words matching a certain prefix
//    Returns:  vector<string>
//    Parameters:
//       TrieNode* nodeToSearch, vector<string> words, string word
//----------------------------------------------------------------
vector<string> Trie::completeHelper(TrieNode* nodeToSearch, vector<string> words, string word){
    string wordToAdd;
    for(int i=0; i<26; i++){
        if(nodeToSearch->children[i]){
          if(nodeToSearch->children[i]->endWord==true){
            char letter = 'a'+i;
            wordToAdd = word + letter;
            words.push_back(wordToAdd);  
    } else {
        char letter = 'a'+i;
        wordToAdd = word + letter;
    }
            words = completeHelper(nodeToSearch->children[i], words, wordToAdd);
        }
    }
    return words;
}