//----------------------------------------------------------------
// Name: John Steimle
// Project 5 Data Structures     
// Project5.cpp
// Driver file for the Alphabet Trie program
//----------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <exception>
#include "Trie.h"
using namespace std;
int main() {
    Trie tree = Trie();
    ifstream myReadFile;
    myReadFile.open("wordlist_windows.txt");
    string word;
    while(myReadFile >> word){
        tree.insert(word);
    }
    while(true){
    string prefix;
    cout << "Please enter a word prefix (or press enter to exit):";
    cin >> prefix;
    int numComp = tree.completeCount(prefix);
    cout << "There are " << numComp << " matches for the prefix " << prefix << " Show completions?(yes or no)" << endl;
    string show;
    cin >> show;
    vector<string> words = tree.complete(prefix);
    if(show == "yes"){
        cout << "---------" << endl;
        for(int i=0; i<words.size(); i++){
            cout << words.at(i) << endl;
        }
    }
    }
    
}