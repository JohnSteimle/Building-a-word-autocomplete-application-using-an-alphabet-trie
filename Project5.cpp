#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include "Trie.h"
using namespace std;
int main() {
    Trie tree = Trie();
    cout << tree.insert("hello");
    cout << tree.insert("an");
    cout << tree.insert("and") << endl;
    cout << tree.find("an");
    cout << tree.find("and");
    cout << tree.find("andy");
    cout << tree.insert("andy");
    cout << tree.find("andy");
    cout << tree.count() << endl;
    cout << tree.insert("andling");
    cout << tree.insert("andlingl");
    cout << tree.insert("andlingkc") << endl;
    cout << tree.completeCount("an") << endl;
    cout << tree.getSize() << endl;
    vector<string> words = tree.complete("an");
    for(int i=0; i<words.size(); i++){
        cout << words.at(i) << endl;
    }
}