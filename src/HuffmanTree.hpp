#ifndef HUFFMAN_TREE
#define HUFFMAN_TREE

#include <iostream>

#include "WordInfo.hpp"

using namespace std;

typedef struct Node {
    Node* left;
    Node* right;

    WordInfo* info;
    int prob;

} Node;

class HuffmanTree {
   private:
   
    int length;

    void preOrder(Node* node);

   public:
    Node* root;
    HuffmanTree(WordInfo* info);
    virtual ~HuffmanTree();
    HuffmanTree insert(Node** min1, Node** min2);
    void showPreOrder();
};

#endif