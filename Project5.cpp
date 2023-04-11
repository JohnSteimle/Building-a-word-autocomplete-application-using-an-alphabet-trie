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
}