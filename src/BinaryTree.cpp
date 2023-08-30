#include "BinaryTree.hpp"

#define dbg(x) cout << #x << " = " << x << endl

BinaryTree::BinaryTree() {
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
    cout << node->value.word << " " << node->value.frequency << endl;
    preOrder(node->right);
}

void BinaryTree::push(WordInfo& info) {
    Item* item = new Item(info);
    insert(item, &root);
}

void BinaryTree::showPreOrder() { this->preOrder(root); }

Item::Item(WordInfo& info) {
    this->value = info;
    this->left = nullptr;
    this->right = nullptr;
}

Item::~Item() {
    // delete this->left;
    // delete this->right;
}