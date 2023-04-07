#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include "Trie.h"
using namespace std;
int main() {
    Trie tree = Trie();
    tree.insert("hello");
    tree.insert("an");
    tree.insert("and");
}