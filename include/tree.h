// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <string>
#include <vector>

class Tree {
private:
    struct Node { // ...
        char val;
        std::vector<Node*> ch;
    };
    Node* root;
    std::vector<std::string> numbs;

    void crTree(Node* root, std::vector<char> _numbs) {
        if (_numbs.size() == 0)
            return;
        if (root->val != '-') {
            for (auto i = _numbs.begin(); i != _numbs.end(); ++i) {
                if (*i == root->val) {
                    _numbs.erase(i);
                    break;
                }
            }
        }
        for (size_t i = 0; i < _numbs.size(); ++i) {
            root->ch.push_back(new Node)
        }
        for (size_t i = 0; i < root->ch.size(); ++i) {
            root->ch[i]->val = _numbs[i];
        }
        for (size_t i = 0; i < root->ch.size(); ++i) {
            crTree(root->ch[i], _numbs);
        }
    }

    void getPerm(Node* root, std::string numb = "") {
        if (root->val != '-') {
            numb += root->val;
        }
        if (!root->ch.size()) {
            numb += root->val;
            numbs.push_back(numb);
            return;
        }
        for (size_t i = 0; i < root->ch.size(); ++i) {
            getPerm(root->ch[i], numb);
        }

public:
    std::string operator[](int i) const {
        return numbs[i];
    }
    explicit Tree(std::vector<char> val) {
        root = new Node;
        root->val = '-';
        crTree(root, val);
        getPerm(root);
    }
}
  
#endif  // INCLUDE_TREE_H_
