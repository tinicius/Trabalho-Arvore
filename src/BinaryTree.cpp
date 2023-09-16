#include "BinaryTree.hpp"

BinaryTree::BinaryTree(ofstream& file) : file(file) {
    this->root = nullptr;
    length = 0;
}

BinaryTree::~BinaryTree() {}

void BinaryTree::insert(Item* item, Item** node) {
    if (*node == nullptr) {
        *node = item;
        (*node)->left = nullptr;
        (*node)->right = nullptr;
        return;
    }

    if (item->value.frequency >= (*node)->value.frequency)
        insert(item, &(*node)->right);
    else
        insert(item, &(*node)->left);
}

void BinaryTree::preOrder(Item* node) {
    if (node == nullptr) return;

    preOrder(node->left);
    this->file << node->value.word << " " << node->value.frequency << " ";
    preOrder(node->right);
}

void BinaryTree::push(WordInfo& info) {
    Item* item = new Item(info);
    insert(item, &root);
}

void BinaryTree::showPreOrder() { this->preOrder(root); }
