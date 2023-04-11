//----------------------------------------------------------------
// Name: John Steimle
// Project 5 Data Structures     
// Trie.h
// creates the Trie class and TrieNode class
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
private:
    int wordCount;
public:
//----------------------------------------------------------------
// Trie::insert inserts a word into the tree
//    Returns:  bool
//    Parameters:
//       string word
//----------------------------------------------------------------
bool insert(string);
//----------------------------------------------------------------
// Trie::count returns number of words in trie
//    Returns:  int
//    Parameters:
//       None
//----------------------------------------------------------------
int count();
//----------------------------------------------------------------
// Trie::getSize returns number of nodes in trie
//    Returns:  int
//    Parameters:
//       None
//----------------------------------------------------------------
int getSize();
//----------------------------------------------------------------
// Trie::find searches the Trie for word
//    Returns:  bool
//    Parameters:
//       string word
//----------------------------------------------------------------
bool find(string);
//----------------------------------------------------------------
// Trie::completeCount returns number of words matching specified prefix
//    Returns:  int
//    Parameters:
//       string word
//----------------------------------------------------------------
int completeCount(string);
//----------------------------------------------------------------
// Trie::complete returns a vector of words matching a certain prefix
//    Returns:  vector<string>
//    Parameters:
//       string word
//----------------------------------------------------------------
vector<string> complete(string);
//----------------------------------------------------------------
// Trie::insertHelper helps the insert function
//    Returns: TrieNode*
//    Parameters:
//       string word TrieNode* node, int wordLength, char letter, int i
//----------------------------------------------------------------
TrieNode* insertHelper(string, TrieNode*, int, char, int);
//----------------------------------------------------------------
// Trie::findHelp helps search the Trie for word
//    Returns:  TrieNode* 
//    Parameters:
//       string word, char letter, int i, TrieNode* iterator
//----------------------------------------------------------------
TrieNode* findHelp(string, char, int, TrieNode*);

//----------------------------------------------------------------
// Trie::searchNode helps the completeCount function
//    Returns:  TrieNode*
//    Parameters:
//       TrieNode* nodeToSearch
//----------------------------------------------------------------
TrieNode* searchNode(TrieNode*);
//----------------------------------------------------------------
// Trie::sizeHelper
//    Returns:  TireNode*
//    Parameters:
//       TrieNode* nodeToCount
//----------------------------------------------------------------
TrieNode* sizeHelper(TrieNode*);
//----------------------------------------------------------------
// Trie::completeHelper helps return a vector of words matching a certain prefix
//    Returns:  vector<string>
//    Parameters:
//       TrieNode* nodeToSearch, vector<string> words, string word
//----------------------------------------------------------------
vector<string> completeHelper(TrieNode*, vector<string>, string);
int countPre=0;
TrieNode* node = new TrieNode();
};