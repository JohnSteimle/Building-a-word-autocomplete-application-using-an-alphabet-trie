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
#include "string.h"
#include "Trie.h"
using namespace std;
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
TrieNode* Trie::insertHelper(string word, TrieNode* node, int wordLength, char letter, int i){
    if(wordLength!=0){
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
    } else {
        node->endWord = true;
        return node;
    }
}
int Trie::count(){
    return wordCount;
}
int Trie::getSize(){
    countPre=0;
    sizeHelper(node);
    return countPre;
}
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
vector<string> Trie::complete(string word){
    vector<string> words;
    TrieNode* temp = node;
    char letter;
    countPre=0;
    for(int i=0; i<word.length(); i++){
        letter = word[i];
        temp = temp->children[letter-'a'];
        if(temp->endWord==true){
            words.push_back(word);
    }
    }
    
    words = completeHelper(temp, words, word);
    return words;
}
vector<string> Trie::completeHelper(TrieNode* nodeToSearch, vector<string> words, string word){
    string wordToAdd;
    for(int i=0; i<26; i++){
        if(nodeToSearch->children[i]){
            if(nodeToSearch->endWord==true){
            char letter = 'a'+i;
            wordToAdd = word + letter;
            words.push_back(wordToAdd);
    }
            words = completeHelper(nodeToSearch->children[i], words, wordToAdd);
        }
    }
    return words;
}
Trie& Trie::operator=(const Trie& tree){}