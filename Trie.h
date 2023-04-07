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
using namespace std;
//----------------------------------------------------------------
// TrieNode::constructor
//----------------------------------------------------------------
struct TrieNode {
    TrieNode *children[26];
    bool endWord;
};
 
//----------------------------------------------------------------
// Trie::class
//----------------------------------------------------------------
class Trie {
public:
bool insert(string);
int count();
int getSize();
bool find(string);
int completeCount(string);
vector<string> complete(string);
Trie& operator=(const Trie&);
TrieNode* insertHelper(string, TrieNode*, int, char, int);
TrieNode* node = new TrieNode();
};