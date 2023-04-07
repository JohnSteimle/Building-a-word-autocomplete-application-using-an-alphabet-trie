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
    cout << tree.insert("and");
}