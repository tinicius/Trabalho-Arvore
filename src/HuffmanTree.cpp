#include "HuffmanTree.hpp"

HuffmanTree::HuffmanTree(WordInfo* info) {
    this->length = 0;
    this->root = (Node*)malloc(sizeof(Node));

    this->root->left = nullptr;
    this->root->right = nullptr;

    this->root->info = info;
}

HuffmanTree::~HuffmanTree() {}

HuffmanTree HuffmanTree::insert(Node** min1, Node** min2) {

    // WordInfo* info = (WordInfo*) malloc(sizeof(WordInfo));

    HuffmanTree newTree(nullptr);

    newTree.root->left = *min1;
    newTree.root->right = *min2;

    return newTree;
}